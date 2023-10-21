#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;

#include "DetalleFactura.h"

    ///set
    void DetalleFactura::setIDFactura(int idFactura);
    void DetalleFactura::setIDArticulo(int idArticulo);
    void DetalleFactura::setCantidad(int cantidad);
    void DetalleFactura::setPrecio (float precio);
    ///get
    int getIDFactura ();
    int getIDArticulo ();
    int getPrecio ();
    int getCantidad ();

    /// CARGAR/MOSTRAR
    void MostrarFactura();
