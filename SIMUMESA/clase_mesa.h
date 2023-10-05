#ifndef CLASE_MESA_H
#define CLASE_MESA_H


class Mesa
{
    private:
        int _numeroMesa;
        bool _estadoMesa;
    public:
    ///set
    void setNumeroDeMesa (int num);
    void setEstadosDeMesa(bool estado);

    ///get
    int getNumeroDeMesa ();
    bool getEstadoDeMesa();

    /// CARGAR/MOSTRAR
    void CargarMesa();
    void MostrarMesa();



};

#endif // CLASE_MESA_H
