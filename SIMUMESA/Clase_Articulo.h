#ifndef CLASE_ARTICULO_H
#define CLASE_ARTICULO_H


class Articulo
{
private:
    int _CodArticulo;
    ///TipoArticulo _TipoArticulo;
    char _NombreArticulo[30];
    float _Precio;
    int _Stock;
    bool _EstadoArticulo;
public:
        ///CONSTRUCTOR:
        Articulo();

        ///SETS
        void setCodigoArticulo(int articulo);
        /// void setTipoArticulo (TipoArticulo tipoArticulo);
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
        ///TipoArticulo getTipoDeArticulo();

        void CargarArticulo();
        void MostrarArticulo();
};

class TipoArticulo{
private:
    int _idTipoArticulo;
    char _NombreTipoArticulo[30];
public:
     ///SET:
     void setIdTipoArticulo(int idArt);
     void setNombreTipoArticulo(const char *NombreTipoArticulo);
     ///GET:
     int getIdTipoArticulo();
     const char *getNombreTipoArticulo();
     CargarTipoArticulo();
     MostrarTipoArticulo();
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

};


#endif // CLASE_ARTICULO_H
