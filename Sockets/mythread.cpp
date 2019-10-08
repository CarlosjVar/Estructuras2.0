#include "mythread.h"



MyThread::MyThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}
void MyThread::run()
{
    //Aquí inicia el thread
    qDebug() << " Thread started";
    socket = new QTcpSocket();

    //Se define el ID
    if(!socket->setSocketDescriptor(this->socketDescriptor))
        {
            // something's wrong, we just emit a signal
            emit error(socket->error());
            return;
        }
    //Se conecta el socket con la señal
        //Se usa  Qt::DirectConnection porque vamos a usar multiThreading
        //A continuación se invoca un slot para ser utilizado
        connect(socket, SIGNAL(connected()), this, SLOT(disconnected()));
        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
        // Como van a haber varios clientes , deseamos saber quien es quien
        qDebug() << socketDescriptor << " Client connected";
        // Este thread debe loopear
        // Esto dado que el thread debe estar vivo para que la señal funcione bien
            exec();
}
void MyThread::readyRead()
{
    // Consigue la información
    QByteArray Data = this->socket->readAll();

    // Imprime en la consola del servidor
    qDebug(Data);
    this->socket->write("Cliete escribió"+Data);
}
void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";


    socket->deleteLater();
    exit(0);
}
void MyThread::connected()
{
    qDebug() << socketDescriptor << " connected";


    socket->deleteLater();
    exit(0);
}
