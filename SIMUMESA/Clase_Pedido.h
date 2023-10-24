#ifndef CLASE_PEDIDO_H
#define CLASE_PEDIDO_H
#include "fecha.h"

class Factura
{

    private:
    int _idfactura;
    Fecha _fecha;


    public:

    ///set
    void setIDFactura(int idFactura);
    void setfecha(int idArticulo);

    ///get
    int getIDFactura();
    Fecha getfecha();

    ///CARGAR
    void CargarFactura();

    ///MOSTRAR
    void MostrarFactura();


};

#endif // CLASE_PEDIDO_H
