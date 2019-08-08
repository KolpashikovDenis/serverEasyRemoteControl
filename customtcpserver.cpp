#include <iostream>
#include "customtcpserver.h"

CustomTcpServer::CustomTcpServer(QObject *parent) : QObject(parent)
{
    m_tcpServer = new QTcpServer(this);
    connect(m_tcpServer, &QTcpServer::newConnection, this, &CustomTcpServer::slotNewConnection);
    if(!m_tcpServer->listen(QHostAddress::Any, 6000))
    {
        qDebug() << "Server not started!";
    } else
    {
        qDebug() << "Server started successfully!";
    }
}

void CustomTcpServer::slotNewConnection()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();
    m_tcpSocket->write("Hello! I am Echo Server\r\n");
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &CustomTcpServer::slotServerRead);
    connect(m_tcpSocket, &QTcpSocket::disconnected, this, &CustomTcpServer::slotClientDisconnected);
}

void CustomTcpServer::slotServerRead()
{
    while(m_tcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = m_tcpSocket->readAll();
        m_tcpSocket->write(array);
        std::cout << array.constData() << std::endl;
    }
}

void CustomTcpServer::slotClientDisconnected()
{
    m_tcpSocket->close();
}
