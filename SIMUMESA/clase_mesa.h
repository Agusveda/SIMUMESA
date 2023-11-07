#ifndef CLASE_MESA_H
#define CLASE_MESA_H
#include "Clase_Articulo.h"




class Mesa{
    private:
        int _numero;
        bool _estado;
        int _idpedido;
    public:
    ///set
    void setNumero(int numero);
    void setEstado(bool estado);
    void setPedido(int pedido);
    ///get
    int getNumero ();
    int getEstado ();
    int getPedido();

    /// CARGAR/MOSTRAR
    void CargarMesa(int idfactura);
    void MostrarMesa();



};

#endif // CLASE_MESA_H
