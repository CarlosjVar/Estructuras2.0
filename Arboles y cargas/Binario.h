#include "Pila.h"
#include <iostream>
using namespace std;


class Binario{
public:
    pNodoBinario raiz;

    Binario():raiz(NULL){}

    void InsertaNodo(int num);
    void PreordenI();
    void InordenI();
    void PostordenI();

    bool Hh;
};

void Binario::InsertaNodo(int num)
{
    if(raiz==NULL){
        raiz = new NodoBinario(num);
    }else{
        raiz->InsertaBinario(num);
    }
}

void Binario::PreordenI(){
    NodoBinario *Act = raiz;
    Pila p;
    while(p.Vacia()==false || (Act!=NULL)){
        if(Act!=NULL){
            cout<<Act->valor<<" - ";
            p.Push(Act);
            Act = Act->Hizq;
        }else{
            Act=p.Pop();
            Act=Act->Hder;
        }
    }
}

void Binario::InordenI(){
    NodoBinario *Act = raiz;
    Pila p;
    bool band=true;
    while(band){
        while(Act!=NULL){
            p.Push(Act);
            Act = Act->Hizq;
        }
        if(!p.Vacia()){
            Act=p.Pop();
            cout<<Act->valor<<" - ";
            Act=Act->Hder;
        }
        if(p.Vacia() & Act==NULL){
            break;
        }
    }
}

void Binario::PostordenI(){
    NodoBinario *Act = raiz;
    Pila p;
    Pila p2;
    while(!p.Vacia() || Act!=NULL){
        if(Act!=NULL){
            p2.Push(new NodoBinario(Act->valor));
            p.Push(Act);
            Act = Act->Hder;
        }else{
            Act=p.Pop();
            Act = Act->Hizq;
        }
    }
    while(!p2.Vacia()){
        NodoBinario *salida=p2.Pop();
        cout<<salida->valor<<" - ";
    }
}


class BinarioAVL{
public:
    pNodoBinarioAVL raiz;

    BinarioAVL():raiz(NULL){}

    void InsertaNodoAVL(int num);
    void PreordenI();
    void InordenI();
    void PostordenI();

    bool Hh;

    void Equilibrar1(NodoBinarioAVL *n, bool);
    void Equilibrar2(NodoBinarioAVL *n, bool);
    void InsertarBalanceado(NodoBinarioAVL*&r, bool &Hh, int x);
    void RotacionDobleIzquierda(NodoBinarioAVL *&n1, NodoBinarioAVL *&n2);
    void RotacionDobleDerecha(NodoBinarioAVL *&n1, NodoBinarioAVL *&n2);
    void RotacionSimpleIzquierda(NodoBinarioAVL *&n1, NodoBinarioAVL *&n2);
    void RotacionSimpleDerecha(NodoBinarioAVL *&n1, NodoBinarioAVL *&n2);
};

void BinarioAVL::PreordenI(){
    NodoBinarioAVL *Act = raiz;
    PilaAVL p;
    while(p.Vacia()==false || (Act!=NULL)){
        if(Act!=NULL){
            cout<<Act->valor<<" - ";
            p.Push(Act);
            Act = Act->Hizq;
        }else{
            Act=p.Pop();
            Act=Act->Hder;
        }
    }
}

void BinarioAVL::InordenI(){
    NodoBinarioAVL *Act = raiz;
    PilaAVL p;
    bool band=true;
    while(band){
        while(Act!=NULL){
            p.Push(Act);
            Act = Act->Hizq;
        }
        if(!p.Vacia()){
            Act=p.Pop();
            cout<<Act->valor<<" - ";
            Act=Act->Hder;
        }
        if(p.Vacia() & Act==NULL){
            break;
        }
    }
}

void BinarioAVL::PostordenI(){
    NodoBinarioAVL *Act = raiz;
    PilaAVL p;
    PilaAVL p2;
    while(!p.Vacia() || Act!=NULL){
        if(Act!=NULL){
            p2.Push(new NodoBinarioAVL (Act->valor));
            p.Push(Act);
            Act = Act->Hder;
        }else{
            Act=p.Pop();
            Act = Act->Hizq;
        }
    }
    while(!p2.Vacia()){
        NodoBinarioAVL *salida=p2.Pop();
        cout<<salida->valor<<" - ";
    }
}


void BinarioAVL::Equilibrar1(NodoBinarioAVL* n, bool Hh){
    NodoBinarioAVL *n1;
    switch (n->FB){
        case -1: n->FB = 0;
        break;
        case 0: n->FB = 1;
        Hh = false;
        break;
        case 1: n1 = n->Hder;
        if(n1->FB>=0){
            if(n1->FB=0){
                Hh = false;
                RotacionSimpleDerecha(n, n1);
            }else{
                RotacionDobleDerecha(n, n1);
            }
        }
    }
}

void BinarioAVL::Equilibrar2(NodoBinarioAVL* n, bool Hh){
    NodoBinarioAVL *n1;
    switch (n->FB){
        case 1: n->FB = 0;
        break;
        case 0: n->FB = 1;
        Hh = false;
        break;
        case -1: n1 = n->Hizq;
        if(n1->FB<=0){
            if(n1->FB=0){
                Hh = false;
                RotacionSimpleIzquierda(n, n1);
            }else{
                RotacionDobleIzquierda(n, n1);
            }
        }
    }
}

void BinarioAVL::InsertarBalanceado(pNodoBinarioAVL &ra, bool &Hh, int x){
    pNodoBinarioAVL n1;
    if(ra==NULL){
        ra = new NodoBinarioAVL(x);
        Hh = true;
    }else{
        if(x<ra->valor){
            InsertarBalanceado(ra->Hizq, Hh, x);
        if(Hh){
            switch(ra->FB){
                case 1: ra->FB=0;
                Hh = false;
                break;
                case 0: ra->FB  = -1;
                break;
                case -1: n1=ra->Hizq;
                if(n1->FB ==-1){
                    RotacionSimpleIzquierda(ra, n1);
                }else{
                    RotacionDobleIzquierda(ra,n1);
                }
                Hh = false;
                break;
            }
        }
        }else{
            if(x>ra->valor){
                InsertarBalanceado(ra->Hder, Hh, x);
                if(Hh){
                    switch(ra->FB){
                        case -1: ra->FB=0;
                        Hh = false;
                        break;
                        case 0: ra->FB=1;
                        break;
                        case 1:n1=ra->Hder;
                        if(n1->FB==1){
                            RotacionSimpleDerecha(ra, n1);
                        }else{
                            RotacionDobleDerecha(ra, n1);
                        }
                        Hh=false;
                        break;
                    }
                }
            }
        }
    }
}

void BinarioAVL::RotacionDobleIzquierda(NodoBinarioAVL*& n, NodoBinarioAVL*& n1){
    NodoBinarioAVL *n2;
    n2=n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder=n;
    n1->Hder=n2->Hizq;
    n2->Hizq=n1;

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void BinarioAVL::RotacionDobleDerecha(NodoBinarioAVL*& n, NodoBinarioAVL*& n1){
    NodoBinarioAVL *n2;
    n2=n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq=n;
    n1->Hizq=n2->Hder;
    n2->Hder=n1;

    if(n2->FB==1){
        n->FB=-1;
    }else{
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void BinarioAVL::RotacionSimpleDerecha(NodoBinarioAVL*& n, NodoBinarioAVL*& n1){
    n->Hder=n1->Hizq;
    n1->Hizq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
}

void BinarioAVL::RotacionSimpleIzquierda(NodoBinarioAVL*& n, NodoBinarioAVL*& n1){
    n->Hizq=n1->Hder;
    n1->Hder=n;

    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=1;
    }
    n=n1;
}


