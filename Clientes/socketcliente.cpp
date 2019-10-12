#include "socketcliente.h"

SocketCliente::SocketCliente(QObject *parent):QObject(parent)
{
}
void SocketCliente::Connect()
{
    socket = new QTcpSocket(this);
        socket->connectToHost("localhost",1111);

        if(socket->waitForConnected(3000))
        {
            qDebug() << "Connected!";
        }
        else
        {
            qDebug() << "Not connected!";
        }

        // sent

        // got

        // closed
}
