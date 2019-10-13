#include <QCoreApplication>
#include "server.h"
#include "ListaCiudades.h"
#include "Globales.h"
#include "AA.h"
#include "adminthread.h"
ArbolB B2=ArbolB(5);
ArbolB B3=ArbolB(5);
Binario B1;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    B1.cargarPasillos("Pasillos.txt");
    B1.cargarProductos("ProductosPasillos.txt");
    B1.cargarMarcas("MarcasProductos.txt");
    ArbolB B2 = ArbolB (5);
    B2.cargarClientes("Clientes.txt");
    B3.cargarAdmins("Administradores.txt");
    listaCiudades L1 = listaCiudades();
    L1.cargarCiudades("Ciudades.txt");
    B2.listaCreciente();
    adminThread admin;
    admin.start();
    Server myserv;
    myserv.StartServer();
    return a.exec();
}
