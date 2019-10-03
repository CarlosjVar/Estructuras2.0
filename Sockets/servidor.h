#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <QTcpServer>

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
};

#endif // SERVIDOR_H
