#ifndef CLASE_MESA_H
#define CLASE_MESA_H
#include "Clase_Articulo.h"




class Mesa:public Articulo
{
    protected:
        int _postre[50];
        int _bebida[50];
        int _PlatoPricipal[50];
        int _entrada[50];
    public:
    ///set
    void setEntrada(int entrada);
    void setPostre (int postre);
    void setBebida(int bebida);
    void setPlatoPrincipal (int PlatoPricipal);
    ///get
    int getEntrada ();
    int getpostre ();
    int getBebida ();
    int getPlatoPrincipal ();

    /// CARGAR/MOSTRAR
    void CargarMesa();
    void MostrarMesa();



};

#endif // CLASE_MESA_H
