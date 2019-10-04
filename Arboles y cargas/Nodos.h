#include <iostream>
#include <string>
using namespace std;

class NodoBinarioAVL {
   public:

    NodoBinarioAVL(int num, NodoBinarioAVL *der = NULL, NodoBinarioAVL *izq = NULL, NodoBinarioAVL *sig=NULL, NodoBinarioAVL *ant=NULL):
        Hizq(izq), Hder(der), valor(num), siguiente(sig), anterior(ant), FB(0) {}

    string nombre;
    int valor;
    int FB;
    NodoBinarioAVL *Hizq, *Hder, *siguiente, *anterior;

    friend class Pila;
    friend class Binario;
    friend class BinarioAVL;
    void InsertaBinarioAVL(int num);
};

void NodoBinarioAVL::InsertaBinarioAVL(int num)
{
    if(num<valor){
        if(Hizq==NULL){
            Hizq = new NodoBinarioAVL(num);
        }else{
            Hizq->InsertaBinarioAVL(num);
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoBinarioAVL(num);
        }else{
            Hder->InsertaBinarioAVL(num);
        }
    }
}

typedef NodoBinarioAVL *pnodoAVL;
typedef NodoBinarioAVL *pNodoBinarioAVL;


class NodoBinario {
   public:

    NodoBinario(int num,string nombre, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Hizq(izq), Hder(der), valor(num), nombre(nombre), siguiente(sig), anterior(ant){}

    string nombre;
    int valor;
    pNodoBinarioAVL productos;
    NodoBinario *Hizq, *Hder, *siguiente, *anterior;

    friend class Pila;
    friend class Binario;

    void InsertaBinario(int num, string nombre);
};

typedef NodoBinario *pnodo;
typedef NodoBinario *pNodoBinario;

void NodoBinario::InsertaBinario(int num,string nombre)
{
    if(num<valor){
        if(Hizq==NULL){
            Hizq = new NodoBinario(num,nombre);
        }else{
            Hizq->InsertaBinario(num,nombre);
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoBinario(num,nombre);
        }else{
            Hder->InsertaBinario(num,nombre);
        }
    }
}
