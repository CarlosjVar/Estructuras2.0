#ifndef RUNNABLE_H
#define RUNNABLE_H
#include <QRunnable>

class Runnable : public QRunnable
{
public:
    Runnable(qintptr handle);
    void run();
};

#endif // RUNNABLE_H
