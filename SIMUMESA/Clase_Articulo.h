#ifndef CLASE_ARTICULO_H
#define CLASE_ARTICULO_H

class Articulo
{
private:
    int _CodArticulo;
    int _TipoArticulo; /// 1 entrada - 2 bebida - 3 hamburguesas - 4 minutas - 5 postres ///
    char _NombreArticulo[30];
    float _Precio;
    int _Stock;
    bool _EstadoArticulo;
public:
        ///CONSTRUCTOR:
        Articulo();

        ///SETS
        void setCodigoArticulo(int articulo);
        void setNombreArticulo(const char *NombreArticulo);
        void setPrecioArticulo(float precio);
        void setStock(int stock);
        void setEstadoArticulo(bool EstadoArt);


        ///GETS
        bool getEstadoArticulo();
        int getCodigoArticulo();
        const char *getNombreArticulo();
        float getPrecioArticulo();
        int getStock();
        std::string getTipoArticulo()const;
        ///TipoArticulo getTipoDeArticulo();

        void CargarArticulo();
        void MostrarArticulo();
};







    class ArchivoArticulo{
    private:
         char nombre[30];

    public:
    ArchivoArticulo(const char *n){
        strcpy(nombre, n);}

    /// FUNCIONES
        bool GrabarRegistroArticulo();
        bool MostrarRegistrosArticulo();
        bool bajaLogicaRegistroArticulo();
        int  buscarCodArticulo( int _CodArticulo );
        Articulo leerRegistroArticulo(int pos);
        bool sobreEscribir_registroArticulo(Articulo registro, int pos);
        bool MostrarRegistrosXTipoArticulo();
        bool ModificarPreciosArticulo();

};


#endif // CLASE_ARTICULO_H
