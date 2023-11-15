#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Clase_Articulo.h"
#include "DetalleFactura.h"
#include "clase_mesa.h"

    ///SET

    void DetalleFactura::setIDFactura(int idFactura){_idFactura=idFactura;}
    void DetalleFactura::setIDArticulo(int idArticulo){_idArticulo=idArticulo;}
    void DetalleFactura::setCantidad(int cantidad){_cantidad=cantidad;}
    void DetalleFactura::setPrecio (float precio){_precio=precio;}
    void DetalleFactura::setTipoArticulo(int tipoart){_tipoArticulo = tipoart;}
    ///GET
    int DetalleFactura::getIDFactura (){return _idFactura;}
    int DetalleFactura::getIDArticulo (){return _idArticulo;}
    int DetalleFactura::getPrecio (){return _precio;}
    int DetalleFactura::getCantidad (){return _cantidad;}
    int DetalleFactura::getTipoArticulo(){return _tipoArticulo;}
    /// CARGAR
    void DetalleFactura::CargarFactura(int tipoarticulo,int idFactura, int idArticulo,int cantidad){
        _idFactura = idFactura;
        _tipoArticulo = tipoarticulo;
        _idArticulo = idArticulo ;
        _cantidad=cantidad;


        /*
        cout<<" PRECIO U/N:  $"
        cin>> _precio;
        */
    }

    ///MOSTRAR
    void DetalleFactura::MostrarFactura(){

                char nombreart[30];
        cout << "ID DE FACTURA :" << getIDFactura() <<endl;
        cout << "TIPO DE ARTICULO :";

        if(_tipoArticulo == 1){cout << "ENTRADA";}
        else if (_tipoArticulo == 2){cout <<"PLATO PRINCIPAL";}
        else if (_tipoArticulo == 3){cout <<"HAMBURGUESAS";}
        else if (_tipoArticulo == 4){cout <<"BEBIDAS";}
        else {cout <<"POSTRES";}
       /// posibilidad de mostrar: Factura.mostrarFactura();

        cout << endl<<"ID DE ARTICULO: " << getIDArticulo()<<endl;

        ArchivoArticulo archiArt("Articulos.dat");
        Articulo regArt;
        int cantRegArt = archiArt.contarRegistrosArticulo();
        for ( int i=0; i<cantRegArt; i++)
        {
            regArt = archiArt.leerRegistroArticulo(i);
            if (regArt.getCodigoArticulo() == getIDArticulo())
            {
                strcpy(nombreart,regArt.getNombreArticulo());
                setPrecio(regArt.getPrecioArticulo());
            }


        }

        cout <<"ARTICULO: "<< nombreart<< endl;
        cout<<"CANTIDAD DEL PRODUCTO: " << getCantidad();
        cout<<"x" << getPrecio() <<endl;
        float totalporart;

        totalporart=getCantidad()*getPrecio();
        cout << "TOTAL DEL PRODUCTO: " << totalporart;
        cout << endl;
        cout << endl;

    }


  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///                                              CLASE ARCHIVO FACTURA                                                  ///

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ArchivoDetalleFactura::ArchivoDetalleFactura (){strcpy(nombre,"DetalleFactura.dat");}


    /// sacar el total por numero de mesa

   void DetalleFactura::TotalDeFacturacion(int idfactura) {

    ArchivoDetalleFactura archdetalle;
    DetalleFactura regdetalle;

    int cantdetalle = archdetalle.contarRegistrosDetalleFactura();
    int totalFactura=0;
    for(int i=0; i<cantdetalle;i++)
    {
    regdetalle = archdetalle.leerRegistroDetalleFactura(i);

    if(regdetalle.getIDFactura()==idfactura)
    {
        regdetalle.MostrarFactura();
        totalFactura += regdetalle.getCantidad()*regdetalle.getPrecio();

    }

    }

    cout << "El total de la cuenta es: $" << totalFactura << endl;

}



    ///GRABAR ARCHIVO DETALLE FACTURA
    bool ArchivoDetalleFactura::GrabarRegistroDetalleFactura(int tipoarticulo, int idFactura, int idArticulo,int cantidad){
    DetalleFactura registro;
    FILE *Art;
    Art = fopen(nombre, "ab");
    if (Art == nullptr){
        cout << " ERROR DE ARCHIVO" << endl;
        system("pause");
        return false;
    }

    cout << "INGRESAR LOS VALORES DE LA factura "<< endl;
    registro.CargarFactura(tipoarticulo,idFactura,idArticulo,cantidad);
    bool escribio = fwrite(&registro , sizeof registro, 1 , Art);
    fclose(Art);
    return escribio;
    }



    ///MOSTRAR EL ARCHIVO DETALLE FACTURA
    bool ArchivoDetalleFactura::MostrarRegistrosDetalleFactura(){
    DetalleFactura reg;
    FILE *Art;
    Art= fopen(nombre,"rb");
       if(Art==NULL){
    cout<< "ERROR AL ABRIR EL ARCHIVO "<<endl;
    return false;
    }
    while(fread (&reg,sizeof reg, 1,Art)==1){

    reg.MostrarFactura();
    cout<<endl;

	}
	fclose(Art);
    return true;
    }

    int ArchivoDetalleFactura :: contarRegistrosDetalleFactura(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(DetalleFactura);
    }

    ///LEER ARCHIVO DETALLE FACTURA
    DetalleFactura ArchivoDetalleFactura::leerRegistroDetalleFactura(int pos){
        DetalleFactura reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    bool ArchivoDetalleFactura::MostrarDetalleFacturaXIdFactura(int idfactura){
    DetalleFactura reg;
    FILE *Art;
    Art= fopen(nombre,"rb");
    if(Art==NULL){
    cout<< "ERROR AL ABRIR EL ARCHIVO "<<endl;
    return false;
    }

    while(fread (&reg,sizeof reg, 1,Art)==1){

    if(reg.getIDFactura()==idfactura)
    {

    reg.MostrarFactura();
    cout<<endl;
    }

	}
	fclose(Art);
    return true;
    }

    /**
    int ArchivoDetalleFactura::buscarIdFactura( int idfactura )
    {
    DetalleFactura registro;
    FILE *p;
    int pos = 0 ;
    p = fopen(nombre,"rb");
    if ( p == NULL){
        return -2;
    }
    while (fread(&registro,sizeof registro, 1, p) ==1){
        if (idfactura == registro.getIDFactura()){
            fclose(p);
            return pos;
            cout << "el ID Factura esta en la posicion " << pos;
        }
            pos++;
    }

    fclose(p);
    return -1;
}
*/

/*
    bool ArchivoDetalleFactura::BajaLogicaDEDetallefactura(int idfactura) {
    int pos;

    // Busca si el idfactura existe en el archivo
    pos = buscarIdFactura(idfactura);
    if (pos == -1) {
        cout << "No existe la factura con el ID ingresado." << endl;
        return false;
    }

    // Lee el registro del archivo y lo coloca en una variable
    DetalleFactura registro;
    registro = leerRegistroDetalleFactura(pos);

    char opc;
    cout << "¿Desea sacar la cuenta? (Ingrese 's' para sí, 'n' para no): ";
    cin >> opc;

    if (opc == 's' || opc == 'S') {
        // Realiza la baja lógica
        registro.(false);
        bool quepaso = //sobreEscribir_registroDetalleFactura(registro, pos);
        cout << "Registro después de la baja lógica:" << endl;
        registro.MostrarFactura();
        return quepaso;
    }

    return false;
}
*/
