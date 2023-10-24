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
    void CargarFactura(int idFactura, int idArticulo,int cantidad);
    void MostrarFactura();

};


    class ArchivoArticulo{
    private:
         char nombre[30];

    public:
    ArchivoArticulo(const char *n){
        strcpy(nombre, n);}

    /// FUNCIONES
        bool GrabarRegistroDetalleFactura(int idFactura, int idArticulo,int cantidad);
        bool MostrarRegistrosDetalleFactura();
        bool bajaLogicaRegistroArticulo();
        int  buscarCodArticulo( int _CodArticulo );
        DetalleFactura leerRegistroArticulo(int pos);
        bool sobreEscribir_registroArticulo(DetalleFactura registro, int pos);
        bool MostrarRegistrosXTipoArticulo();
        bool ModificarPreciosArticulo();

};


#endif // DETALLEFACTURA_H
