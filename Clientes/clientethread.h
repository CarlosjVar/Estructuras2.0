#ifndef CLIENTETHREAD_H
#define CLIENTETHREAD_H
#include <QThread>
#include <QObject>
#include <QDebug>
#include <iostream>
#include <string>
#include <strings.h>
#include <QObject>

class clientethread: public QThread
{
     Q_OBJECT
public:
    clientethread();
    void run();
};

#endif // CLIENTETHREAD_H
