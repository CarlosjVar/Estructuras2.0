#include "servidor.h"
#include "mythread.h"
Servidor::Servidor(QObject *parent) :
    QTcpServer(parent)
{

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
           qDebug() << "Leyendo del puerto " << port << "...";
       }

}
void Servidor::incomingConnection(qintptr socketDescriptor)
{
    //Se recibe una nueva conexión
    qDebug()<<socketDescriptor<<"Conectando";
    MyThread *thread =new MyThread(socketDescriptor,this);
    // Conecta la señal/perdida
    // Cuando el thread no se necesite será eliminado
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
