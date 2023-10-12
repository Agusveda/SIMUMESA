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
    Articulo ()
    {
        _CodArticulo=0;
        strcpy(_NombreArticulo, " ");
        _Precio=0;
        _Stock=0;
        _EstadoArticulo=true;
    }
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

        CargarArticulo();
        MostrarArticulos();
};

#endif // CLASE_ARTICULO_H
