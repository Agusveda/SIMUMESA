#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Clase_Factura.h"
#include "fecha.h"


        //SET

        void Factura::setIdFactura(int idFactura){_idFactura = idFactura;}
        void Factura::setFechaFactura(Fecha fechafactura){_fechaFactura=fechafactura;}
        void Factura::setCantidad(float cantidad){ _Cantidad = cantidad;}
        //GET

        int Factura::getIdFactura(){return _idFactura;}
        Fecha Factura::getFechaFactura(){return _fechaFactura;}
        float Factura::getCantidad(){return _Cantidad;}
        //CARGAR/MOSTRAR

        void Factura::CargarFactura(int idFactura,Fecha fechaactual, float cant)
        {
            _idFactura = idFactura;
            _fechaFactura;
            _Cantidad = cant;
        };
        void Factura::mostrarFactura()
        {
            cout << "idfactura:" << _idFactura;
            cout << _fechaFactura.toString();
            cout << " cantidad : " << _Cantidad;

        };





  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///                                              CLASE ARCHIVO FACTURA                                                 ///

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool GrabarRegistroFactura(int idFactura, Fecha fechaact, float cantidad)
    {
        Factura regfac;
        FILE *fac;
        fac = fopen("Facturas.dat", "ab");
        if (fac == nullptr){
            cout << " ERROR DE ARCHIVO" << endl;
            system("pause");
            return false;
        }

        cout << "INGRESAR LOS VALORES DE ARTICULO "<< endl;
        regfac.CargarFactura(idFactura,fechaact, cantidad);
        bool escribio = fwrite(&regfac , sizeof regfac, 1 , fac);
        fclose(fac);
        return escribio;
    }



    Factura ArchivoFactura::leerRegistroFactura(int pos)
    {
          Factura reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }


    bool ArchivoFactura::MostrarRegistrosFactura(){
    Factura reg;
    FILE *Art;
    Art= fopen("Facturas.dat","rb");
       if(Art==NULL){
    cout<< "ERROR AL ABRIR EL ARCHIVO "<<endl;
    return false;
    }
    while(fread (&reg,sizeof reg, 1,Art)==1){
    if(reg.getCantidad()>0){
    reg.mostrarFactura();
    cout<<endl;
    }
	}
	fclose(Art);
    return true;
    }


        int ArchivoFactura::contarRegistrosFactura(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Factura);
    }

