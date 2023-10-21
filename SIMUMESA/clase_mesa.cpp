#include<cstring>
#include<cstdlib>
#include <iostream>
#include "clase_mesa.h"

using namespace std;
    void Mesa::setEntrada(int entrada){_entrada = entrada;}
    void Mesa::setPostre (int postre){_postre = postre;}
    void Mesa::setBebida(int bebida){_bebida = bebida;}
    void Mesa::setPlatoPrincipal (int PlatoPricipal){_PlatoPricipal = PlatoPricipal;}
    ///get
    int Mesa::getEntrada(){return _entrada;}
    int Mesa::getpostre(){return _postre;}
    int Mesa::getBebida(){return _bebida;}
    int Mesa::getPlatoPrincipal(){return _PlatoPricipal;}

    /// CARGAR/MOSTRAR
    void Mesa::MostrarMesa();

void Mesa::CargarMesa()
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

void Mesa::MostrarMesa()
{
    cout << "Numero de mesa : " << _numeroMesa;
    cout << endl;
    cout << "estado de mesa : ";
    if (_estadoMesa == 1){cout << "activo :) ";}else { cout << "inactivo :( "; }
}




