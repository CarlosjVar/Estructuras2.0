#ifndef ADMINTHREAD_H
#define ADMINTHREAD_H
#include <QThread>
#include <QObject>
#include <QDebug>
#include <iostream>
#include <string>
#include <strings.h>
#include "Globales.h"
class AdminThread: public QThread
{
    Q_OBJECT
public:
    AdminThread();
    void run() override;

};

#endif // ADMINTHREAD_H
