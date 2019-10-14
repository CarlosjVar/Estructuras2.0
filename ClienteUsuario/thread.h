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
    bool LoginV();
signals:
    void WriteByte(QByteArray data);
    void waitResponse();
};

#endif // THREAD_H
