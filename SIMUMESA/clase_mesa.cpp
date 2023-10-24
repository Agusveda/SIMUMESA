#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Clase_Articulo.h"
#include "clase_mesa.h"

    void Mesa::setNumero(int numero){_numero = numero;}
    void Mesa::setEstado (bool estado){_estado = estado;}
    ///get
    int Mesa::getNumero(){return _numero;}
    int Mesa::getEstado(){return _estado;}

    /// CARGAR/MOSTRAR

/*
    void Mesa::MostrarMesa();


void Mesa::CargarMesa()
{
Articulo a;
a.MostrarArticulo();
detallefactura b("DetalleFactura.dat");



cout << " ingresar cdg de entrada, en caso de no tener entrad 0 " << endl;
int tam=1;

while(!=0)
{


    cin >> _pedido[tam];
    cout << " Ingresar Cantidad : ";
    cin >> _Cantidad;
    tam++;

    b.GrabarRegistroDetalleFactura( _idFactura,_pedido,_cantidad);
}
b.mostrar();

cout << " ingresar plato principal, en caso de no tener plato 0 " << endl;
while(!=0){}
cout << " ingresar bebida, en caso de no tener bebida 0 " << endl;
while(!=0){}
cout << " ingresar postre, en caso de no tener " << endl;
while(!=0){}
}
void Pedido::MostrarMesa()
{
    cout << "Numero de mesa : " << _numero;
    cout << endl;
    cout << "estado de mesa : ";
    if (_estado == 1){cout << "activo :) ";}else { cout << "inactivo :( "; }
}

*/



