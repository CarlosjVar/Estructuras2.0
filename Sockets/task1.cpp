#include "task1.h"

Task1::Task1()
{

}
void Task1::run()
{
    qDebug()<<"Inicio: ";
    int iNumber=0;
    for(int i =0;i<100;i++)
    {
        iNumber++;
    }
    qDebug()<<"Completo";
    emit Result(iNumber);
}
