#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;

#include "DetalleFactura.h"

    ///set
    void DetalleFactura::setIDFactura(int idFactura){_idFactura=idFactura;}
    void DetalleFactura::setIDArticulo(int idArticulo){_idArticulo=idArticulo;}
    void DetalleFactura::setCantidad(int cantidad){_cantidad=cantidad;}
    void DetalleFactura::setPrecio (float precio){_precio=precio;}

    ///get
    int DetalleFactura::getIDFactura (){return _idFactura;}
    int DetalleFactura::getIDArticulo (){return _idArticulo;}
    int DetalleFactura::getPrecio (){return _cantidad;}
    int DetalleFactura::getCantidad (){return _precio;}

    /// CARGAR/MOSTRAR
    void DetalleFactura::CargarFactura(){
        cout<<" ID DE FACTURA: ";
        cin>>_idFactura;
        cout<<" ID DE ARTICULO: ";
        cin>>_idArticulo;
        cout<<" CANTIDAD DEL PRODUCTO: ";
        cin>>_cantidad;
        cout<<" PRECIO U/N:  $"
        cin>> _precio;
    }
    void DetalleFactura::MostrarFactura(){
        cout<<" ID DE FACTURA: " << _idFactura <<endl;
        cout<<" ID DE ARTICULO: " << _idArticulo <<endl;
        cout<<" CANTIDAD DEL PRODUCTO: " << _cantidad <<endl;
        cout<<" PRECIO U/N:  $" << _precio <<endl;
    }
