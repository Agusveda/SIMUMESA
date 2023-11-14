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
#include "Clase_Factura.h"

    void Mesa::setNumero(int numero){_numero = numero;}
    void Mesa::setEstado (bool estado){_estado = estado;}
    void Mesa::setidFactura(int idFactura){_idFactura = idFactura;}

    ///get
    int Mesa::getNumero(){return _numero;}
    int Mesa::getEstado(){return _estado;}
    int Mesa::getidFactura(){return _idFactura;}
    /// CARGAR/MOSTRAR


    void Mesa::MostrarMesa(){
        cout<<" Numero de mesa: " <<_numero<<endl;
        cout<<" Estado de la mesa: " <<_estado<<endl;
        cout<<" ID De La Factura: " <<_idFactura<<endl;
    }

void Mesa::CargarMesa(int numesa, bool estado, int idfactura)
{
    setNumero(numesa);
    setEstado(estado);
    setidFactura(idfactura);
}

/// VOID CARGAR MESA
void Mesa::CargarPedidoMesa(int idfactura)
{
ArchivoArticulo archiArticulo("Articulos.dat"); /// ACA ESTAN TODOS LOS ARTICULOS,
archiArticulo.MostrarRegistrosArticulo(); /// SE MUESTRAN TODOS LOS ARTICULOS
ArchivoDetalleFactura archiDetalleFac;/// ACA VAN A ESTAR LOS ARTICULOS CON EL IDFACTURA
while(true){
        system("cls");

        gotoxy(45,4);cout<<"INGRESAR TIPO DE ARTICULO A CARGAR"<<endl;
        gotoxy(45,7);cout<<"============================"<<endl;
        dibujarCuadro(30,3,90,24);
        gotoxy(45,9);cout<<"1- CARGAR ENTRADA"<<endl;
        gotoxy(45,11);cout<<"2- CARGAR MINUTAS"<<endl;
        gotoxy(45,13);cout<<"3- CARGAR HAMBURGUESA "<<endl;
        gotoxy(45,15);cout<<"4- CARGAR BEBIDAS "<<endl;
        gotoxy(45,17);cout<<"5- CARGAR POSTRES"<<endl;
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
                    cin >> cantdelpedido ;

                    archiDetalleFac.GrabarRegistroDetalleFactura(1,idfactura,cdgpedido,cantdelpedido);
                break;
            case 2:
                 archiArticulo.MostrarRegistrosXTipoArticulo(2);
                    cin >> cdgpedido;
                    cout << "cantidad:";
                    cin >> cantdelpedido ;

                    archiDetalleFac.GrabarRegistroDetalleFactura(2,idfactura,cdgpedido,cantdelpedido);

                break;
            case 3:
                    archiArticulo.MostrarRegistrosXTipoArticulo(3);
                    cin >> cdgpedido;
                    cout << "cantidad:";
                    cin >> cantdelpedido ;

                    archiDetalleFac.GrabarRegistroDetalleFactura(3,idfactura,cdgpedido,cantdelpedido);
                break;
            case 4:
                    archiArticulo.MostrarRegistrosXTipoArticulo(4);
                    cin >> cdgpedido;
                    cout << "cantidad:";
                    cin >> cantdelpedido ;

                    archiDetalleFac.GrabarRegistroDetalleFactura(4,idfactura,cdgpedido,cantdelpedido);
                break;
                case 5:
                    archiArticulo.MostrarRegistrosXTipoArticulo(5);
                    cin >> cdgpedido;
                    cout << "cantidad:";
                    cin >> cantdelpedido;

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

    ArchivoMesa::ArchivoMesa (){strcpy(nombre,"Mesas.dat");}

    Mesa ArchivoMesa:: leerRegistroMesa(int pos){
        Mesa reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    int ArchivoMesa :: contarRegistrosMesa(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Mesa);
    }

    bool ArchivoMesa :: GrabarRegistroMesa(int numesa, bool estado, int idfactura)
    {
    Mesa registro;
    FILE *Art;
    Art = fopen(nombre, "ab");
    if (Art == nullptr){
        cout << " ERROR DE ARCHIVO" << endl;
        system("pause");
        return false;
    }

    cout << "INGRESAR LOS VALORES DE LA factura "<< endl;
    registro.CargarMesa(numesa,estado,idfactura);
    bool escribio = fwrite(&registro , sizeof registro, 1 , Art);
    fclose(Art);
    return escribio;
    }

    bool ArchivoMesa::MostrarRegistrosDeMesa (){
    Mesa reg;
    FILE *Art;
    Art= fopen(nombre,"rb");
       if(Art==NULL){
    cout<< "ERROR AL ABRIR EL ARCHIVO "<<endl;
    return false;
    }
    while(fread (&reg,sizeof reg, 1,Art)==1){

    reg.MostrarMesa();
    cout<<endl;

	}
	fclose(Art);
    return true;
    }

bool ArchivoMesa::BajaLogicaDEDetallefactura(int idfactura) {
    int pos;

    // Busca si el idfactura existe en el archivo
    pos = buscarIdFactura(idfactura);
    if (pos == -1) {
        cout << "No existe la factura con el ID ingresado." << endl;
        return false;
    }

    // Lee el registro del archivo y lo coloca en una variable
    Mesa registro;
    registro = leerRegistroMesa(pos);

    char opc;
    cout << "¿Desea sacar la cuenta? (Ingrese 's' para sí, 'n' para no): ";
    cin >> opc;

    if (opc == 's' || opc == 'S') {
        // Realiza la baja lógica
        registro.setEstado(false);
        bool quepaso = //sobreEscribir_registroDetalleFactura(registro, pos);
        cout << "----- La cuenta es ------ " << endl;

        return quepaso;
    }

    return false;
}

int ArchivoMesa::buscarIdFactura( int idfactura )
    {
    Mesa registro;
    FILE *p;
    int pos = 0 ;
    p = fopen(nombre,"rb");
    if ( p == NULL){
        return -2;
    }
    while (fread(&registro,sizeof registro, 1, p) ==1){
        if (idfactura == registro.getidFactura()){
            fclose(p);
            return pos;
            cout << "el ID Factura esta en la posicion " << pos;
        }
            pos++;
    }

    fclose(p);
    return -1;
}


