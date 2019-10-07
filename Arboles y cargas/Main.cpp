#include <stdlib.h>
#include "Binario.h"
#include <iostream>

using namespace std;

int main(){
    Binario B = Binario();
    B.cargarPasillos("Pasillos.txt");
    B.cargarProductos("ProductosPasillos.txt");
    B.cargarMarcas("MarcasProductos.txt");
}
