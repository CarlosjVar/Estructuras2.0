#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H

#include <QTcpServer>
#include <QThreadPool>
#include <QTcpSocket>
#include <QAbstractSocket>

class SocketCliente:public QObject
{
public:
    explicit SocketCliente(QObject *parent = 0);
    void Connect();
signals:

public slots:

private:
    QTcpSocket *socket;

};

#endif // SOCKETCLIENTE_H
