#include <QCoreApplication>
#include "socketcliente.h"
#include "clientethread.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SocketCliente test;
    test.Connect();
    clientethread cliente;
    cliente.start();
    return a.exec();
}
