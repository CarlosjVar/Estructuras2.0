#include <QCoreApplication>
#include "servidor.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);    
    // Make a server and starts it
    Servidor server;
    server.startServer();
    return a.exec();
}
