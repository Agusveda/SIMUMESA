#ifndef CLASE_MESA_H
#define CLASE_MESA_H


class Mesa
{
    private:
        int _numero;
        bool _estado;
    public:
        ///set
    void setNumeroDeMesa (int num);

        ///get
        int getNumeroDeMesa ();
        bool getEstado();

    /// CARGAR/MOSTRAR
    void CargarMesa();
    void MostrarMesa();

    Mesa ();

};

#endif // CLASE_MESA_H
