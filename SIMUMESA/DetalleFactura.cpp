#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;

#include "DetalleFactura.h"

    ///set
    void DetalleFactura::setIDFactura(int idFactura){_idFactura=idFactura;}
    void DetalleFactura::setIDArticulo(int idArticulo){_idArticulo=idArticulo;}
    void DetalleFactura::setCantidad(int cantidad){_cantidad=cantidad;}
    void DetalleFactura::setPrecio (float precio){_precio=precio;}

    ///get
    int DetalleFactura::getIDFactura (){return _idFactura;}
    int DetalleFactura::getIDArticulo (){return _idArticulo;}
    int DetalleFactura::getPrecio (){return _cantidad;}
    int DetalleFactura::getCantidad (){return _precio;}

    /// CARGAR/MOSTRAR
    void DetalleFactura::CargarFactura(int idFactura, int idArticulo,int cantidad){
        cin>>idFactura;
        cin>>idArticulo;
        cin>>cantidad;
        /*
        cout<<" PRECIO U/N:  $"
        cin>> _precio;
        */
    }
    void DetalleFactura::MostrarFactura(){
        cout<<" ID DE FACTURA: " << _idFactura <<endl;
        cout<<" ID DE ARTICULO: " << _idArticulo <<endl;
        cout<<" CANTIDAD DEL PRODUCTO: " << _cantidad <<endl;
        cout<<" PRECIO U/N:  $" << _precio <<endl;
    }







    ///GRABAR ARCHIVO EMPLEADO
    bool ArchivoArticulo::GrabarRegistroDetalleFactura(int idFactura, int idArticulo,int cantidad){
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



    ///MOSTRAR EL ARCHIVO
    bool ArchivoArticulo::MostrarRegistrosDetalleFactura(){
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
