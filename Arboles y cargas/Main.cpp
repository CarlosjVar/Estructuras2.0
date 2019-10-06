#include <stdlib.h>
#include "Binario.h"
#include "ArbolB.h"
#include <iostream>

using namespace std;

int main(){
    ArbolB B = ArbolB(4);
    B.insertar(16);
    B.insertar(89);
    B.insertar(4);
    B.insertar(5);
    B.insertar(1);
    B.escribir();
}
