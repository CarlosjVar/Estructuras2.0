#include "B.h"
#include "Binario.h"
#include "ListaCiudades.h"
#include <iostream>

using namespace std;

int main(){
    Binario B1 = Binario();
    B1.cargarPasillos("Pasillos.txt");
    B1.cargarProductos("ProductosPasillos.txt");
    B1.cargarMarcas("MarcasProductos.txt");
    ArbolB B2 = ArbolB (5);
    B2.cargarClientes("Clientes.txt");
    ArbolB B3 = ArbolB (5);
    B3.cargarAdmins("Administradores.txt");
    listaCiudades L1 = listaCiudades();
    L1.cargarCiudades("Ciudades.txt");
    L1.Mostrar();
}
