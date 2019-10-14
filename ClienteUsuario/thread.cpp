#include "thread.h"
using namespace std;
Thread::Thread(QObject*parent)
{
    connect(this,SIGNAL(WriteByte(QByteArray)),&socket,SLOT(WriteByte(QByteArray)));
    connect(this,SIGNAL(waitResponse()),&socket,SLOT(waitResponse(2000)));
}
void Thread::run()
{
    cout<<"Bienvenido"<<endl;
    while(true)
    {
        cout<<"Ingrese su cédula"<<endl;
        string cedula ;
        cin>>cedula;
        string login="LO";
        login.append(cedula);
        emit WriteByte(QByteArray::fromStdString(login));
        emit waitResponse();
        this->sleep(1);
        if(socket.getestado())
        {
            cout<<"Login correcto";
            while(true)
            {
                
            }
        }
        else
        {
            cout<<"No se encuentra registrado";
        }



    }


}

