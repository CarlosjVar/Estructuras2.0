#include "mycliente.h"

Mycliente::Mycliente(QObject*parent):QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(15);
}
void Mycliente::SetSocket(qintptr Desc)
{
    socket=new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    socket->setSocketDescriptor(Desc);
    qDebug()<<"Cliente conectado";
}
void Mycliente::connected()
{
    qDebug()<<"Cliente conectado ev";
}
void Mycliente::disconnected()
{
    qDebug()<<"Cliente no conectado";
}
void Mycliente::readyRead()
{
    QByteArray data=socket->readAll();
    if(data.toStdString().substr(0,2)=="LO")
    {
        std::string cedula=data.toStdString().substr(2,7);
        Pagina*cliente=new Pagina(5);
        int k;
        cliente=clientes.buscar(std::stoi(cedula),k);
        if (cliente!=nullptr)
        {
            socket->write("LOS");
        }
        else
        {
            socket->write("LON");
        }

    }
}
void Mycliente::write(QByteArray data)
{
        // Must always be called on thread 1
        this->socket->write(data);
}
