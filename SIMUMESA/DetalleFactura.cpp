#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;

#include "DetalleFactura.h"

    ///SET
    void DetalleFactura::setIDFactura(int idFactura){_idFactura=idFactura;}
    void DetalleFactura::setIDArticulo(int idArticulo){_idArticulo=idArticulo;}
    void DetalleFactura::setCantidad(int cantidad){_cantidad=cantidad;}
    void DetalleFactura::setPrecio (float precio){_precio=precio;}
    ///GET
    int DetalleFactura::getIDFactura (){return _idFactura;}
    int DetalleFactura::getIDArticulo (){return _idArticulo;}
    int DetalleFactura::getPrecio (){return _cantidad;}
    int DetalleFactura::getCantidad (){return _precio;}
    /// CARGAR
    void DetalleFactura::CargarFactura(int idFactura, int idArticulo,int cantidad){
        cin>>idFactura;
        cin>>idArticulo;
        cin>>cantidad;
        /*
        cout<<" PRECIO U/N:  $"
        cin>> _precio;
        */
    }

    ///MOSTRAR
    void DetalleFactura::MostrarFactura(){

       /// posibilidad de mostrar: Factura.mostrarFactura();
        cout<<" ID DE ARTICULO: " << getIDArticulo()<<endl;
        cout<<" CANTIDAD DEL PRODUCTO: " << getCantidad() <<endl;
        cout<<"x" << getPrecio() <<endl;
        int totalporart;

        totalporart=getCantidad()*getPrecio();
        cout << "total del producto" << totalporart;
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

    cout << "INGRESAR LOS VALORES DE LA MESA "<< endl;
    registro.CargarFactura( idFactura,idArticulo,cantidad);
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
