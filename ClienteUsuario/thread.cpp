#include "thread.h"
using namespace std;
Thread::Thread(QObject*parent)
{
    connect(this,SIGNAL(WriteByte(QByteArray)),&socket,SLOT(WriteByte(QByteArray)));
}
void Thread::run()
{
    cout<<"Bienvenido al menú del supermercado"<<endl;
    while(true)
    {
        char d;
        cout<<"Elija una opción"<<endl;
        cin>>d;
        switch(d)
        {
            case '1':
                emit WriteByte("Hola");
            break;
            case '2':
                emit WriteByte("Adios");
            break;
        }
    }
}
