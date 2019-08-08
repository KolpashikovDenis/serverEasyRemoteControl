#ifndef CUSTOMTCPSERVER_H
#define CUSTOMTCPSERVER_H

#include <iostream>
#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class CustomTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit CustomTcpServer(QObject *parent = nullptr);

signals:

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
};

#endif // CUSTOMTCPSERVER_H
