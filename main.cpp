#include <QCoreApplication>
#include "customtcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CustomTcpServer mServer;

    return a.exec();
}
