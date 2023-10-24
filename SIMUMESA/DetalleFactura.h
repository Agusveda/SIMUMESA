#ifndef DETALLEFACTURA_H
#define DETALLEFACTURA_H


class DetalleFactura
{
    private:
        int _idFactura;
        int _idArticulo;
        int _cantidad;
        float _precio;
    public:
    ///set
    void setIDFactura(int idFactura);
    void setIDArticulo(int idArticulo);
    void setCantidad(int cantidad);
    void setPrecio (float precio);
    ///get
    int getIDFactura ();
    int getIDArticulo ();
    int getPrecio ();
    int getCantidad ();

    /// CARGAR/MOSTRAR
    void CargarFactura();
    void MostrarFactura();

};

#endif // DETALLEFACTURA_H
