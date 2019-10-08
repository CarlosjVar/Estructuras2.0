#ifndef TASK1_H
#define TASK1_H
#include <QRunnable>
#include <QObject>
#include <QDebug>

class Task1 : public QObject, public QRunnable
{
    Q_OBJECT
public:
    Task1();
protected:
    void run();
signals:
    void Result(int Number);

};

#endif // TASK1_H
