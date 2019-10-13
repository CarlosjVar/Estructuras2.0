#ifndef MYCLIENTE_H
#define MYCLIENTE_H

#include <QObject>
#include <QTcpSocket>
#include <QtDebug>
#include <QThreadPool>

class Mycliente: public QObject
{
    Q_OBJECT
public:
   explicit Mycliente(QObject*parent=nullptr);
   void SetSocket(qintptr Desc);
signals:

public slots:
   void connected();
   void disconnected();
   void readyRead();
   void write(QByteArray Data);
private:
    QTcpSocket*socket;
};

#endif // MYCLIENTE_H
