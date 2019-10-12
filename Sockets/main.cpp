#include <QCoreApplication>
#include "servidor.h"
#include "adminthread.h"
#include <iostream>
#include "ListaCiudades.h"
#include "Globales.h"
#include "AA.h"
using namespace std;
    Binario B1;
    ArbolB B2(5);
    ArbolB B3(5);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);    
//     Make a server and starts it
    B1.cargarPasillos("Pasillos.txt");
    B1.cargarProductos("ProductosPasillos.txt");
    B1.cargarMarcas("MarcasProductos.txt");
    ArbolB B2 = ArbolB (5);
    B2.cargarClientes("Clientes.txt");
    B3.cargarAdmins("Administradores.txt");
    listaCiudades L1 = listaCiudades();
    L1.cargarCiudades("Ciudades.txt");
    AA caca=AA();
    caca.cargarInventario("Inventario.txt");
    caca.Inorden();
    B1.InordenI();
    pNodoBinario aux=buscarNodo(B1.raiz,1);
    pNodoBinarioAVL aux2=buscarNodoAVL(aux->productos,20);
    cout<<aux2->nombre<<endl;
    Servidor server;
    server.startServer();
    AdminThread hola;
    hola.start();
    return a.exec();
}
