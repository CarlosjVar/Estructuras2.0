#include <stdlib.h>
#include "Binario.h"
#include <iostream>

using namespace std;

int main(){
    Binario B;
    B.cargarPasillos("Pasillos.txt");
    B.PostordenG(B.raiz);
}
