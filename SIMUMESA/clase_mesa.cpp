#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Clase_Articulo.h"
#include "clase_mesa.h"
#include "Clase_Articulo.h"
#include "DetalleFactura.h"
#include "rlutil.h"
#include "decoracion.h"

    void Mesa::setNumero(int numero){_numero = numero;}
    void Mesa::setEstado (bool estado){_estado = estado;}
    ///get
    int Mesa::getNumero(){return _numero;}
    int Mesa::getEstado(){return _estado;}

    /// CARGAR/MOSTRAR


  ///  void Mesa::MostrarMesa();


void Mesa::CargarMesa()
{

ArchivoArticulo archiArticulo("Articulos.dat"); /// ACA ESTAN TODOS LOS ARTICULOS,
archiArticulo.MostrarRegistrosArticulo(); /// SE MUESTRAN TODOS LOS ARTICULOS
ArchivoDetalleFactura archiDetalleFac("DetalleFactura.dat");/// ACA VAN A ESTAR LOS ARTICULOS CON EL IDFACTURA
while(true){
        system("cls");

        gotoxy(55,4);cout<<"INGRESAR TIPO DE ARTICULO A CARGAR"<<endl;
        gotoxy(45,7);cout<<"============================"<<endl;
        dibujarCuadro(30,3,90,24);
        gotoxy(45,9);cout<<"1- CARGAR ENTRADA"<<endl;
        gotoxy(45,11);cout<<"2- CARGAR MINUTAS"<<endl;
        gotoxy(45,13);cout<<"3- CARGAR HAMBURGUESA "<<endl;
        gotoxy(45,15);cout<<"4- CARGAR BEBIDAS "<<endl;
        gotoxy(45,16);cout<<"5- CARGAR POSTRES"<<endl;
        gotoxy(45,19);cout<<"============================"<<endl;
        gotoxy(45,21);cout<<"0- VOLVER MENU PRINCIPAL "<<endl;
        gotoxy(45,23);cout<<"INGRESE UNA OPCION: ";
        int opci;
        cin>>opci;
        system("cls");
        int cdgpedido;
        int cantdelpedido;
        switch(opci){

            case 1:
                    archiArticulo.MostrarRegistrosXTipoArticulo(1);
                    cin >> cdgpedido;
                    cout << "cantidad:";
                    cin >> cantDelPedido ;

                    archiDetalleFac.GrabarRegistroDetalleFactura(1,idfactura,cdgpedido,cantdelpedido);
                break;
            case 2:
                 archiArticulo.MostrarRegistrosXTipoArticulo(2);
                    cin >> cdgpedido;
                    cout << "cantidad:";
                    cin >> cantDelPedido ;

                    archiDetalleFac.GrabarRegistroDetalleFactura(2,idfactura,cdgpedido,cantdelpedido);

                break;
            case 3:
                    archiArticulo.MostrarRegistrosXTipoArticulo(3);
                    cin >> cdgpedido;
                    cout << "cantidad:";
                    cin >> cantDelPedido ;

                    archiDetalleFac.GrabarRegistroDetalleFactura(3,idfactura,cdgpedido,cantdelpedido);
                break;
            case 4:
                    archiArticulo.MostrarRegistrosXTipoArticulo(4);
                    cin >> cdgpedido;
                    cout << "cantidad:";
                    cin >> cantDelPedido ;

                    archiDetalleFac.GrabarRegistroDetalleFactura(4,idfactura,cdgpedido,cantdelpedido);
                break;
                case 5:
                    archiArticulo.MostrarRegistrosXTipoArticulo(5);
                    cin >> cdgpedido;
                    cout << "cantidad:";
                    cin >> cantDelPedido;

                    archiDetalleFac.GrabarRegistroDetalleFactura(5,idfactura,cdgpedido,cantdelpedido);

                break;
            case 0:
                return ;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    }


}
/*
cout << " ingresar cdg de entrada, en caso de no tener entrad 0 " << endl;
int tam=1;

while(!=0)
{


    cin >> _pedido[tam];
    cout << " Ingresar Cantidad : ";
    cin >> _Cantidad;
    tam++;

    b.GrabarRegistroDetalleFactura( _idFactura,_pedido,_cantidad);
}
b.mostrar();
1 minutas
mostrarporarticulo(1);
cout << " ingresar plato principal, en caso de no tener plato 0 " << endl;
while(!=0){}


2 entrda

3 postre


cout << " ingresar plato principal, en caso de no tener plato 0 " << endl;
while(!=0){}
cout << " ingresar bebida, en caso de no tener bebida 0 " << endl;
while(!=0){}
cout << " ingresar postre, en caso de no tener " << endl;
while(!=0){}
}
void Pedido::MostrarMesa()
{
    cout << "Numero de mesa : " << _numero;
    cout << endl;
    cout << "estado de mesa : ";
    if (_estado == 1){cout << "activo :) ";}else { cout << "inactivo :( "; }
}




for (i=0; i<tipoarticulo;i++){

    for(Factura){


    }
        for(DetalleFactura)

    if(detallefactura.idfactura()==factura.idfactura())
    {
        cout << tipoarticulo << getarticulo << cantidad <<cantidad()*Getprecio();


    }


}


*/

