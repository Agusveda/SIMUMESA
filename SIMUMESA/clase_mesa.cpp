#include<cstring>
#include<cstdlib>
#include <iostream>
#include "clase_mesa.h"
using namespace std;

void Mesa::setNumeroDeMesa (int num){if (num>0&&num<=5){_numeroMesa=num;}}

bool Mesa::setEstadosDeMesa(bool estado) {_estadoMesa = estado;}

int Mesa::getNumeroDeMesa(){return _numeroMesa;}

bool Mesa::getEstadoDeMesa(){return _estadoMesa;}

void Mesa::CargarMesa()
{
    cout << " ingresar numero de mesa :";
    cin >> _numeroMesa;
    cout << " ingresar estado de mesa | '1' activo  | '0' inactivo |  : ";
    cin >> _estadoMesa;
}
void Mesa::MostrarMesa()
{
    cout << "Numero de mesa : " << _numeroMesa;
    cout << endl;
    cout << "estado de mesa : ";
    if (_estadoMesa == 1){cout << "activo :) ";}else { cout << "inactivo :( "; }
}




