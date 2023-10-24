#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;

#include "clase_mesa.h"

    void Pedido::setEntrada(int entrada){_entrada = entrada;}
    void Pedido::setPostre (int postre){_postre = postre;}
    void Pedido::setBebida(int bebida){_bebida = bebida;}
    void Pedido::setPlatoPrincipal (int PlatoPricipal){_PlatoPricipal = PlatoPricipal;}
    ///get
    int Pedido::getEntrada(){return _entrada;}
    int Pedido::getpostre(){return _postre;}
    int Pedido::getBebida(){return _bebida;}
    int Pedido::getPlatoPrincipal(){return _PlatoPricipal;}

    /// CARGAR/MOSTRAR
    void Pedido::MostrarMesa();

void Pedido::CargarMesa()
{
mostrararticulos();

cout << " ingresar cdg de entrada, en caso de no tener entrad 0 " << endl;
while(!=0){
        int m=1;
        int entrada
        papas fritas

}
cout << " ingresar plato principal, en caso de no tener plato 0 " << endl;
while(!=0){}
cout << " ingresar bebida, en caso de no tener bebida 0 " << endl;
while(!=0){}
cout << " ingresar postre, en caso de no tener " << endl;
while(!=0){}tadoMesa;
}

void Pedido::MostrarMesa()
{
    cout << "Numero de mesa : " << _numeroMesa;
    cout << endl;
    cout << "estado de mesa : ";
    if (_estadoMesa == 1){cout << "activo :) ";}else { cout << "inactivo :( "; }
}




