#include <iostream>
using namespace std;

class NodoBinarioAVL {
   public:

    NodoBinarioAVL(int num, NodoBinarioAVL *der = NULL, NodoBinarioAVL *izq = NULL, NodoBinarioAVL *sig=NULL, NodoBinarioAVL *ant=NULL):
        Hizq(izq), Hder(der), valor(num), siguiente(sig), anterior(ant), FB(0) {}


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

    NodoBinario(int num, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Hizq(izq), Hder(der), valor(num), siguiente(sig), anterior(ant){}


    int valor;
    pNodoBinarioAVL productos;
    NodoBinario *Hizq, *Hder, *siguiente, *anterior;

    friend class Pila;
    friend class Binario;

    void InsertaBinario(int num);
};

typedef NodoBinario *pnodo;
typedef NodoBinario *pNodoBinario;

void NodoBinario::InsertaBinario(int num)
{
    if(num<valor){
        if(Hizq==NULL){
            Hizq = new NodoBinario(num);
        }else{
            Hizq->InsertaBinario(num);
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoBinario(num);
        }else{
            Hder->InsertaBinario(num);
        }
    }
}
