#ifndef CLASE_MESA_H
#define CLASE_MESA_H
#include "Clase_Articulo.h"




class Mesa{
    private:
        int _numero;
        bool _estado;
        int _idFactura;
    public:
    ///set
    void setNumero(int numero);
    void setEstado(bool estado);
    void setidFactura(int _idFactura);
    ///get
    int getNumero ();
    int getEstado ();
    int getidFactura();

    /// CARGAR/MOSTRAR
    void CargarMesa(int numesa, bool estado, int idfactura);
    void CargarPedidoMesa(int idfactura);
    void MostrarMesa();



};

class ArchivoMesa {
private:
    char nombre[30];
public:
    ArchivoMesa (const char *n);
    Mesa leerRegistroMesa(int pos);
    int contarRegistrosMesa();
    bool GrabarRegistroMesa(int numesa, bool estado, int idfactura);
    bool MostrarRegistrosFactura();






};

#endif // CLASE_MESA_H
