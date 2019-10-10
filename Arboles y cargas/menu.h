/////////
/// Carlos Varela 2019077177
/// Estándar GNC 11+
/// 19/09/19
/// Versión 1.0
//////////
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdlib.h>
class Menu{
public:
    Menu()
    {
        ColaS*espera=new ColaS();
    }

void menu(Binario B1,ArbolB clientes);
void menucompra(Binario B1,clienodo persona);
void agregarcarrito(Binario B1,clienodo persona);
void comprar(ArbolB Clientes,Binario super);
void agregarcarrito2(Binario B1,clienodo persona,pNodoBinario pasillop);
//void agregarcarrito3(Binario B1,clienodo persona,pNodoBinario pasillop,pNodoBinarioAVL productop);
//void agregarcarrito4(Binario B1,clienodo persona,pNodoBinario pasillop,pNodoBinarioAVL productop,Node*marcap);

private:
    ColaS*espera;
};


//void Menu::agregarcarrito4(Binario super,clienodo persona,pNodoBinario pasillop,pNodoBinarioAVL productop,Node*marcap)
/////In:Binario B1,clienodo persona,pNodoBinarioAVL pasillop,pNodoBinarioAVL productop,pNodoBinarioAVL marcap
/////out:None
/////Funci�n se encarga de pedir la cantidad de productos que quiere adquirir al carrito
//{
// int cantidad;
// if(marcap->cantidadGondola==0)
// {
//     cout<<"Actualmente no hay stock de este producto, por favor esperar a que la administraci�n recargue las gondolas"<<endl;
//     return menucompra(super,persona);
// }
// cout<<"Actualmente hay "<<marcap->cantidadGondola<<" productos"<<endl;
// cout<<"Cuantos productos desea llevar? ";
// cin>>cantidad;
// if(cin.fail())
//{
//    cout<<"Entrada invalida,por favor ingrese una cantidad valida"<<endl;
//    cin.clear();
//    cin.ignore(256,'\n');
//    return agregarcarrito4(super,persona,pasillop,productop,marcap);
//}
//if(cantidad>marcap->cantidadGondola)
//{
//    string vrfc;
//    cout<<"Actualmente solo hay "<<marcap->cantidadGondola<<" productos, desea llevarse lo que hay?"<<endl;
//    cout<<"1=Si \n 0=No"<<endl;
//    cin>>vrfc;
//    if (vrfc=="1")
//    {
//    cantidad=marcap->cantidadGondola;
//    marcap->cantidadGondola=marcap->cantidadGondola-marcap->cantidadGondola;
//    }
//    else
//    {
//        return menucompra(super,persona);
//    }
//}
//else
//{
//  marcap->cantidadGondola=marcap->cantidadGondola-cantidad;
//}
//if(persona->carrito->PilaVacia())
//{
//    persona->carrito->InsertarInicio(pasillop->valor,productop->valor,marcap->data,marcap->nombre,cantidad);
//}
//else
//{
//    conodo aux=persona->carrito->primero;
//    while(aux!=NULL)
//    {
//        if(aux==marcap->marca)
//        {
//            aux->cantidad=aux->cantidad+cantidad;
//        }
//        aux=aux->siguiente;
//    }
//    persona->carrito->InsertarInicio(pasillop->valor,productop->valor,marcap->valor,marcap->nombre,cantidad);
//}
//return menucompra(super,persona);
//}
//void Menu::agregarcarrito3(Binario super,clienodo persona,pNodoBinario pasillop,pNodoBinarioAVL productop)
/////In:Binario B1,clienodo persona,pNodoBinarioAVL pasillop,pNodoBinarioAVL productop
/////Out:None
/////Funci�n: Da a elegir entre las marcas
//{
//
//    string marcap;
//    Node*marcas=productop->marcas;
//    cout<<"Indique cual el c�digo de la marca a comprar: "<<"\n"<<endl;
//    cout<<"Ingrese 0 si quiere volver a la secci�n de productos"<<"\n"<<endl;
//    //Aquí va impresión
//    cout<<"Marca: ";
//    cin>>marcap;
//    cout<<""<<endl;
//    marcas=productop->marcas;
//    //buscarnodo
//    if(marcap==marcas->data.toString)
//    {
//    }
//    else if(marcap=="0")
//    {
//        return agregarcarrito2(super,persona,pasillop);
//    }
//    else
//    {
//        cout<<"Ese producto no existe"<<endl;
//        return agregarcarrito3(super,persona,pasillop,productop);
//    }
//    return agregarcarrito4(super,persona,pasillop,productop,marcas);
//}
void Menu::agregarcarrito2(Binario B1,clienodo persona,pNodoBinario pasillop)
///In:Binario B1,clienodo persona,pNodoBinarioAVL pasillop
///None_
///Funci�n: Da a elegir entre productos
{
    string productop;
    pNodoBinarioAVL productos=pasillop->productos;
    BinarioAVL arbol= BinarioAVL();
    arbol.InsertarBalanceado(productos,false&,productos->valor,productos->nombre);
    arbol.InordenI();
    cout<<"Indique cual el c�digo del que producto quiere revisar: "<<"\n"<<endl;
    cout<<"Ingrese 0 si quiere volver a la secci�n de pasillos"<<"\n"<<endl;
    cout<<productos->nombre<<"    Codigo: "<<productos->valor<<"\n"<<endl;
    cout<<"Producto: ";
    cin>>productop;
    cout<<""<<endl;
    if(productop==productos->atoi)
    {
    }
    else if(productop=="0")
    {
        return agregarcarrito(super,persona);
    }
    else
    {
        cout<<"Ese producto no existe"<<endl;
        return agregarcarrito2(super,persona,pasillop);
    }
    return agregarcarrito3(super,persona,pasillop,productos);

}
void Menu::agregarcarrito(Binario super,clienodo persona)
///In:Binario B1,clienodo persona
///None_
///Funci�n: Da a elegir entre pasillos
{
    string pasillop;
    cout<<"Indique el codigo del pasillo que quiere recorrer: "<<"\n"<<endl;
    cout<<"Ingrese 0 si quiere volver al menu de compra"<<"\n"<<endl;
    super.InordenI();
    cout<<"\n"<<endl;
    cin>>pasillop;
    pNodoBinario raiz=super.raiz;
    pNodoBinarioAVL pasillo=buscarNodo(raiz,atoi(pasillop))
    cout<<""<<endl;
    if(pasillo)
    {

    }

    else if(pasillop=="0")
    {
        return menucompra(super,persona);
    }
    else
    {
        cout<<"Ese pasillo no existe"<<endl;
        return agregarcarrito(super,persona);
    }
    return agregarcarrito2(super,persona,pasillo);
}
void Menu::menucompra(Binario super,clienodo persona)
///In:ListaDC super,clienodo persona
///Out:None
///Funci�n: permite al usuario elegir entre seguir comprando o irse a la cola de espera
{   int opcion;
    cout<<"Que desea realizar?"<<"\n"<<endl;
    cout<<"1.  Añadir compra al carrito"<<endl;
    cout<<"2.  Pagar"<<"\n"<<endl;
    cout<<"Recuerde que una vez en la cola de espera no podra realizar mas compras hasta que vuelva a entrar al supermercado"<<"\n"<<endl;
    cout<<"Opcion: ";
    cin>>opcion;
    cout<<" "<<endl;

    if(cin.fail())
{
    cout<<"Entrada invalida,por favor ingrese numeros"<<endl;
    cin.clear();
    cin.ignore(256,'\n');
    return menucompra(super,persona);
}
    if (opcion==1)
    {
       agregarcarrito(super,persona);
    }
    else if (opcion==2)
    {
        int consecutivo=persona->facturas;
        persona->facturas++;
        espera->insertarFinal(persona->cedula,persona->nombre,persona->telefono,persona->correo,persona->carrito,consecutivo);
        return;
    }
    else
    {
        return menucompra(super,persona);
    }
}
void Menu::comprar(ArbolB clientes,Binario super)
///In:ListaDC super,clienodo persona
///Out:None
///Funci�n: Solicita cedula y verifica contra listacliente/colaespera
{
string cedula;
cout<<"Por favor ingrese su numero de cedula:  "<<endl;
cout<<"Cedula: ";
cin>>cedula;
cout<<" "<<endl;
int cedulaI;
stringstream geek(cedula);
geek>>cedulaI;
int k;
//if(clientes.buscarNodo(clientes.obtenerRaiz(),cedulaI,k))
//
//{
    clienodo validar=espera->primero;

//    while(validar!=NULL)
//    {
//        if(validar->cedula==aux->obtenerClave(0))
//        {
//            cout<<"Esta cedula se encuentra en el supermercado"<<endl;
//            return;
//        }
//        validar=validar->siguiente;
//    }
    cout<<"Bienvenido :"<<"\n"<<endl;
    //aux->carrito=new Pila;
    clienodo aux2;
    menucompra(super,aux2);
//}
//else{
//    cout<<"No se encuentra afiliado"<<endl;
//    return;
//}
}

void Menu::menu(Binario super,ArbolB clientes)
///In:Binario B1mercado,inventario inventario,listaClientes clientes
///Out:None
///Funci�n: Men� que funciona como nexo principal entre todas las funcionalidades
{
    int opcion;
cout<<"Bienvenido al sistema de gestion del supermercado por favor selecciones una opcion: "<<endl;
cout<<"1. Comprar"<<endl;
cout<<"2. Facturar"<<endl;
cout<<"3. Revisar Gondolas"<<endl;
cout<<"4. Verificar Inventario"<<endl;
cout<<"5. Generacion de reportes"<<endl;
cout<<"0. Salir del programa"<<endl;
cout<<"Opcion: ";
cin>>opcion;
cout<<" "<<endl;
if(cin.fail())
{
    cout<<"Entrada invalida,por favor ingrese numeros"<<endl;
    cin.clear();
    cin.ignore(256,'\n');
    return menu(super,clientes);
}


if (opcion==1)
{
    comprar(clientes,super);
}
else if(opcion==2)
{
    if(espera->ColaVacia())
    {
        cout<<"La cola de clientes est� vac�a"<<endl;
    }
    else
    {

    }
}
else if (opcion==3)
{

}
else if(opcion==4)
{

}
else if(opcion==5)
{

}
else if(opcion==0)
{
    return;
}
else
{
    return menu(super,clientes);
}
    return menu(super,clientes);
}


#endif // MENU_H_INCLUDED
