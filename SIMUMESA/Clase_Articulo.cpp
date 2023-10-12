#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Clase_Articulo.h"

///SETS
    void Articulo:: setCodigoArticulo(int codArticulo){_CodArticulo=codArticulo;}
    void Articulo:: setNombreArticulo(const char *NombreArticulo){strcpy(_NombreArticulo,NombreArticulo);}
    void Articulo:: setPrecioArticulo(float precio){_Precio=precio;}
    void Articulo:: setStock(int stock){_Stock=stock;}
    void Articulo:: setEstadoArticulo(bool estado){_EstadoArticulo = estado;}
    ///GETS
    bool Articulo::getEstadoArticulo(){return _EstadoArticulo;}
    int Articulo::getCodigoArticulo(){return _CodArticulo;}
    const char *Articulo::getNombreArticulo(){return _NombreArticulo;}
    float Articulo::getPrecioArticulo(){return _Precio;}
    int Articulo::getStock(){return _Stock;}

