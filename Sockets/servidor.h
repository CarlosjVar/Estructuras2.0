#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <QTcpServer>
#include <QThreadPool>
#include "myclient.h"
#include <QTcpSocket>
#include <QAbstractSocket>

class Servidor: public QTcpServer
{
    Q_OBJECT
public:
    explicit Servidor(QObject *parent = 0);
    void startServer();
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);
    QThreadPool *pool;
};

#endif // SERVIDOR_H
