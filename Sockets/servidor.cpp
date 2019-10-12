#include "servidor.h"
#include "myclient.h"
Servidor::Servidor(QObject *parent) :
    QTcpServer(parent)
{
    pool =new QThreadPool(this);
    pool->setMaxThreadCount(5);
}
void Servidor::startServer()
{
    int port=1111;
    if(!this->listen(QHostAddress::Any, port))
        {
            qDebug() << "No se pudo iniciar el servidor";
        }
    else
       {
           qDebug() << "Inicio el servidor";
       }

}
void Servidor::incomingConnection(qintptr socketDescriptor)
{
    MyClient *cliente=new MyClient(this);
    cliente->SetSocket(socketDescriptor);
    qDebug()<<"Nuevo cliente "+ socketDescriptor;

}
