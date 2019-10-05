#include <stdlib.h>
#include "Binario.h"
#include <iostream>

using namespace std;

int main(){
    /*
    Binario B;
    B.cargarPasillos("Pasillos.txt");
    B.cargarProductos("ProductosPasillos.txt");
    */
    RBTree B2;
    B2.InsertaNodo(B2.root,5,"Abarrotes");
    B2.InsertaNodo(B2.root,8,"Jugos");
    B2.InsertaNodo(B2.root,10,"Carnes");
    B2.InsertaNodo(B2.root,3,"Licor");
    B2.inOrderHelper(B2.root);
}
