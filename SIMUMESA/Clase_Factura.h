#ifndef CLASE_FACTURA_H
#define CLASE_FACTURA_H
#include "fecha.h"

class Factura
{

    private:
        int _idFactura;
        Fecha _fechaFactura;
        float _Cantidad;

    public:
        //SET

        void setIdFactura(int idFactura);
        void setFechaFactura (Fecha fechafactura);
        void setCantidad(float cantidad);
        //GET

        int getIdFactura();
        Fecha getFechaFactura();
        float getCantidad();
        //CARGAR/MOSTRAR
        void CargarFactura(int idFactura,Fecha fechaactual, float cant);
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

    int contarRegistrosFactura();
    bool GrabarRegistroFactura(int idFactura, Fecha fechaact, float cantidad);
    bool MostrarRegistrosFactura();
    Factura leerRegistroFactura(int pos);
};



#endif // CLASE_FACTURA_H
