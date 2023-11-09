#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Clase_Articulo.h"
#include "DetalleFactura.h"

    ///SET
    void DetalleFactura::setIDFactura(int idFactura){_idFactura=idFactura;}
    void DetalleFactura::setIDArticulo(int idArticulo){_idArticulo=idArticulo;}
    void DetalleFactura::setCantidad(int cantidad){_cantidad=cantidad;}
    void DetalleFactura::setPrecio (float precio){_precio=precio;}
    void DetalleFactura::setTipoArticulo(int tipoart){_tipoArticulo = tipoart;}
    ///GET
    int DetalleFactura::getIDFactura (){return _idFactura;}
    int DetalleFactura::getIDArticulo (){return _idArticulo;}
    int DetalleFactura::getPrecio (){return _cantidad;}
    int DetalleFactura::getCantidad (){return _precio;}
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
        else if (_tipoArticulo == 2){cout <<"MINUTAS";}
        else if (_tipoArticulo == 3){cout <<"HAMBURGUESAS";}
        else if (_tipoArticulo == 4){cout <<"BEBIDAS";}
        else {cout <<"POSTRES";}
       /// posibilidad de mostrar: Factura.mostrarFactura();

        cout << endl<<" ID DE ARTICULO: " << getIDArticulo()<<endl;

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
        cout << nombreart<< endl;
        cout<<" CANTIDAD DEL PRODUCTO: " << getCantidad();
        cout<<"x" << getPrecio() <<endl;
        int totalporart;

        totalporart=getCantidad()*getPrecio();
        cout << "total del producto" << totalporart;
        cout << endl;
        cout << endl;

    }




  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///                                              CLASE ARCHIVO FACTURA                                                  ///

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    ///GRABAR ARCHIVO DETALLE FACTURA
    bool ArchivoDetalleFactura::GrabarRegistroDetalleFactura(int tipoarticulo, int idFactura, int idArticulo,int cantidad){
    DetalleFactura registro;
    FILE *Art;
    Art = fopen("DetalleFactura.dat", "ab");
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
    Art= fopen("DetalleFactura.dat","rb");
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
    Art= fopen("DetalleFactura.dat","rb");
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

