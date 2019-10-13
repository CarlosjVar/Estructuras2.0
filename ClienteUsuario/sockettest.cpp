#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
}

void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    socket->connectToHost("localhost",1234);


        if(socket->waitForConnected(3000))
        {
            qDebug() << "Connected!";
        }
        else
        {
            qDebug() << "Not connected!";
        }

}
void SocketTest::connected()
{
    qDebug()<<"Conectado";
}
void SocketTest::disconnected()
{
    qDebug()<<"Desconectao";
}
void SocketTest::WriteByte(QByteArray data)
{
    this->socket->write(data);
}
void SocketTest::readyRead()
{
    qDebug()<<this->socket->readAll();
}
