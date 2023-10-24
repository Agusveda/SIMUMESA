#ifndef CLASE_MESA_H
#define CLASE_MESA_H
#include "Clase_Articulo.h"




class Mesa{
    private:
        int _numero;
        bool _estado;
        int _pedido;
    public:
    ///set
    void setNumero(int numero);
    void setEstado(bool estado);

    ///get
    int getNumero ();
    int getEstado ();


    /// CARGAR/MOSTRAR
    void CargarMesa();
    void MostrarMesa();



};

#endif // CLASE_MESA_H
