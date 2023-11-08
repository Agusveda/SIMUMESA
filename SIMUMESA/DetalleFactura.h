#ifndef DETALLEFACTURA_H
#define DETALLEFACTURA_H


class DetalleFactura
{
    private:
        int _idFactura;
        int _tipoArticulo;
        int _idArticulo;
        int _cantidad;
        float _precio;
        float _total;

    public:
    ///SET
    void setIDFactura(int idFactura);
    void setIDArticulo(int idArticulo);
    void setCantidad(int cantidad);
    void setPrecio (float precio);
    void setTipoArticulo(int tipoArt);
    ///GET
    int getIDFactura ();
    int getIDArticulo ();
    int getPrecio ();
    int getCantidad ();
    int getTipoArticulo();
    /// CARGAR/MOSTRAR
    void CargarFactura(int tipoarticulo,int idFactura, int idArticulo,int cantidad);
    void MostrarFactura();

};



  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///                                              CLASE ARCHIVO DETALLEFACTURA                                           ///

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    class ArchivoDetalleFactura{
    private:
         char nombre[30];

    public:
    ArchivoDetalleFactura(const char *n){
        strcpy(nombre, n);}

    /// FUNCIONES
        bool GrabarRegistroDetalleFactura(int Tipoarticulo, int idFactura, int idArticulo,int cantidad);
        bool MostrarRegistrosDetalleFactura();
        DetalleFactura leerRegistroDetalleFactura(int pos);
        bool MostrarDetalleFacturaXIdFactura(int idfactura);
        int contarRegistrosDetalleFactura();
      //  bool TotalporIdFactura(int total por Factura)
      // getprecio(cantidad*precio);



};


#endif // DETALLEFACTURA_H
