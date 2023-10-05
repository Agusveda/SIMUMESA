#ifndef CLASE_PEDIDO_H
#define CLASE_PEDIDO_H
#include "clase_mesa.h"

class Minutas
{
    private:
    char nombreMinutas[20];
    float precioMinutas;
    int stockMinutas;
    int id;
    bool estado;

    public:

    Minutas(){

    strcpy(nombreMinutas,"vacio");
    precioMinutas =0;
    stockMinutas = 0;    }

    // SET

    void setNombreMinutas(const char *_nombreminutas);
    void setPrecioMinutas(float _precioMinutas);
    void setStockMinutas(int _stockMinutas);
    void setIdMinutas (int _id);
    void setEstadoMinutas(bool _estado);

    // GET

    const char * getNombreMinutas();
    float getPrecioMinutas();
    int getStockMinutas();
    int getIdMinutas();
    bool getEstadoMinutas();

    ///MOSTRAR/CARGAR

    void mostrarMinutas();
    void agregarminutas();

};

class ArchivoMinutas{

private:
    char nombre[30];

public:

    ArchivoMinutas(const char *n){
    strcpy(nombre, n);}


    /// funciones del archivo

    bool modificarMinutas();

    int bajaLogicaRegistroMinutas();

    Minutas leerRegistroMinutas(int pos);

    int contarRegistrosMinutas();

    bool grabarRegistroMinutas();

    int buscar_IdMinutas( int id );

    bool sobreEscribir_registroMinutas(Minutas registro, int pos);

};

#endif // CLASE_PEDIDO_H
