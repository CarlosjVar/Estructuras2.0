#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QObject>
#include <iostream>
#include <string>
#include "socketglobal.h"
class Thread:public QThread
{
    Q_OBJECT
public:
    Thread(QObject*parent=nullptr);
    void run() override;
signals:
    void WriteByte(QByteArray data);
};

#endif // THREAD_H
