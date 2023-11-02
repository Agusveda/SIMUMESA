#ifndef CLASE_FACTURA_H
#define CLASE_FACTURA_H
#include "fecha.h"

class Factura
{

    private:
        int _idFactura;
        Fecha _fechaFactura;

    public:
        //SET

        void setIdFactura(int idFactura);
        void setFechaFactura (Fecha fechafactura);

        //GET

        int getIdFactura();
        Fecha getFechaFactura();

        //CARGAR/MOSTRAR
        void CargarFactura();
        void mostrarFactura();

};


  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///                                              CLASE ARCHIVO FACTURA                                                  ///

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  class ArchivoFactura{

  private:
        char nombre[30];
  public:
    ArchivoFactura(const char *n){
        strcpy(nombre, n);}




    /// FUNCIONES

    bool GrabarRegistroFactura(int idFactura, int idArticulo,int cantidad);
    bool MostrarRegistrosFactura();
    Factura leerRegistroFactura(int pos);

};



#endif // CLASE_FACTURA_H
