#include "myclient.h"
#include <QObject>
MyClient::MyClient(QObject *parent) : QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(15);
}
void MyClient::SetSocket(qintptr Descriptor)
{
    socket= new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    socket->setSocketDescriptor(Descriptor);
    qDebug()<<"Cliente conectado";
}
void MyClient::connected()
{
    qDebug()<<"Conectado";
}
void MyClient::disconnected()
{
  qDebug()<<"Desconectado";
}
void MyClient::readyRead()
{
   QByteArray requestData=this->socket->readAll();
   qDebug(requestData);
   this->socket->write("Cliente Wrote:"+requestData);
}
void MyClient::TaskResult(int Number)
{
    QByteArray Buffer;
    Buffer.append("task result= ");
    Buffer.append(QString::number(Number));
    socket->write(Buffer);
}
