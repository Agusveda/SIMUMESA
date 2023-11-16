#include<cstring>
#include<cstdlib>
#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
#include "Clase_Empleado.h"
#include "menus.h"
#include "rlutil.h"
#include "decoracion.h"
#include "Cargar_Cadena.h"
#include "Clase_Articulo.h"
#include "clase_mesa.h"
#include "DetalleFactura.h"
#include "Clase_Factura.h"
#include "Reportes_Generales.h"
/// MENU GENERAL DONDE VAN A ESTAR LAS OPCIONES PRINCIPALES PARA EL INICIO DEL SISTEMA
Fecha fechaa;
bool mesa;
int mesas;

 Mesa *vmesa=nullptr;


  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///                                              MENU PRINCIPAL                                                         ///

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu_general()
{
    int opc;
    while(true)
    {
        system("cls");

        gotoxy(55,4);
        cout<<"MENU PRINCIPAL"<<endl;
        gotoxy(45,7);
        cout<<"============"<<fechaa.toString()<<"================"<<endl;
        dibujarCuadro(30,3,90,20);
        gotoxy(45,9);
        cout<<"1- INGRESAR COMO ADMINISTRADOR"<<endl;
        gotoxy(45,11);
        cout<<"2- INGRESAR COMO EMPLEADO"<<endl;
        gotoxy(45,13);
        cout<<"3- REPORTES GENERALES "<<endl;
        gotoxy(45,15);
        cout<<"============================"<<endl;
        gotoxy(45,17);
        cout<<"0 - CERRAR PROGRAMA"<<endl;
        gotoxy(45,19);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;

        cout<<endl;
        system("cls");
        switch(opc)
        {
        case 1:


            int loginResult;

            do
            {
                loginResult = login();

                if (loginResult == 1)
                {
                    gotoxy (45,10);
                    cout << "INGRESO AL SISTEMA" << endl;
                    menu_administrador();    //  LLAMA A LA FUNCION DEL MENU DEL ADMINISTRADOR AQUI
                }
                else
                {
                    cout << endl;
                    gotoxy (45,13);
                    cout << "PASSWORD O USUARIO INCORRECTOS" << endl;
                    gotoxy (45,15);
                    cout << "PRESIONE CUALQUIER TECLA PARA VOLVER A INTENTAR" << endl;

                    char a; // variable
                    a = (char)getch(); // FUNCION DE CONIO.H QUE TOMA UN CARACTER PARA CONTINUAR, FUNCION PARECIDA A SYSTEM("PAUSE")
                    system("cls");
                }
            }
            while (loginResult != 1);


            return 0 ;
            break; // FINALIZA OPCION 1


        case 2:
            {
              if (mesa==false){
                gotoxy(30,13);
                cout << " \t\t INGRESAR CANTIDAD DE MESAS :";
                cin >> mesas;
                mesa=true;
                vmesa= new Mesa[mesas+1];
              }

            menu_empleado();
            }
            return 0;
            break;

        case 3:
            gotoxy (15,10);
            cout << "REPORTES GENERALES:" << endl;
            gotoxy (15,12);
            cout << "----------------------------------------------" << endl;
            gotoxy (15,14);
            RecaudacionDelDia();
            gotoxy (15,16);
            cout << "----------------------------------------------" << endl;
            gotoxy (15,18);
            ArticuloMasVendidoDia();
            gotoxy (15,20);
            cout << "----------------------------------------------" << endl;
            gotoxy (15,22);
            ArticuloMasVendidoMes();
            gotoxy (15,24);
            cout << "----------------------------------------------" << endl;
            gotoxy (15,26);
            ArticuloMenosVendidoDia();
            gotoxy (15,28);
            cout << "----------------------------------------------" << endl;

            char a; // variable
            a = (char)getch();
            break;

        case 0:
            cout << " ADIOS, UN GUSTO!";

            mesa=false;
            delete vmesa;

            return 0;
        default:
            cout<<"OPCION INCORRECTA"<<endl;
            system("cls");
            break;
            return 0;
        }
    }
    return 0;
}






  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///                                             MENU ADMINISTRADOR                                                      ///

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/// MENU PARA EL ADMINISTRADOR, LUEGO DEL INGRESAR CON "1" AL MENU PRINCIPAL

int menu_administrador()
{
    int opci;
    while(true)
    {
        system("cls");

        gotoxy(55,4);
        cout<<"MENU ADMINISTRADOR"<<endl;
        gotoxy(45,7);
        cout<<"===============CARTA==============="<<endl;
        dibujarCuadro(30,3,95,30);
        gotoxy(45,9);
        cout<<"1- VER CARTA "<<endl;
        gotoxy(45,11);
        cout<<"2- AGREGAR ARTICULO EN LA CARTA "<<endl;
        gotoxy(45,13);
        cout<<"3- MODIFICAR PRECIO"<<endl;
        gotoxy(45,15);
        cout<<"4- BAJA LOGICA DE ARTICULO EN LA CARTA"<<endl;
        gotoxy(45,17);
        cout<<"=============EMPLEADOS============="<<endl;
        gotoxy(45,19);
        cout<<"5- AGREGAR EMPLEADO"<<endl;
        gotoxy(45,21);
        cout<<"6- MOSTRAR EMPLEADOS EXISTENTES"<<endl;
        gotoxy(45,23);
        cout<<"7- DAR DE BAJA EMPLEADOS EXISTENTES"<<endl;
        gotoxy(45,25);
        cout<<"==================================="<<endl;
        gotoxy(45,26);
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        gotoxy(45,28);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opci;
        system("cls");

        switch(opci)
        {
        case 1:
            {
                ArchivoArticulo archiArt("Articulos.dat");

                for (int n=1 ; n <=5 ; n++)
                {

                if(archiArt.MostrarRegistrosXTipoArticulo(n))
                {
                    cout << "//////////////////////////////////" << endl;
                }
                else
                {
                    cout << " Error al visualizar los articulos de la carta";
                }
                }
                char a; // variable
                a = (char)getch();
                cout << "estos fueron los articulos";
            }

        return menu_administrador();
        case 2:
            {
                ArchivoArticulo archiArt("Articulos.dat");
                if(archiArt.GrabarRegistroArticulo()){
                    cout << "articulo grabado correctamente";
                }
                else
                {
                    cout << " Error al grabar el articulo";
                }
                char a; // variable
                a = (char)getch();
            }
        return menu_administrador();
        case 3:
            {
                ArchivoArticulo archiArt("Articulos.dat");
                if (archiArt.ModificarPreciosArticulo()){cout<<" precio de articulo actualizado ";}

                else {cout<<" Error al al modificar el precio ";}

                char a; // variable
                a = (char)getch();
            }
                return menu_administrador();
                break;
        case 4:
        {
            ArchivoArticulo archiArt("Articulos.dat");
            if(archiArt.bajaLogicaRegistroArticulo())
            {
                cout << "EL ARTICULO FUE DADO DE BAJA CORRECTAMENTE";
                char a; // variable
                a = (char)getch();
            }
            else
            {
                cout << " |--VOLVIENDO AL MENU--| " ;
            }
            char a; // variable
            a = (char)getch();
        }
        return menu_administrador();
        break;

        case 5:
        {

            ArchivoEmpleado archiE("Empleado.dat");
            if(archiE.GrabarRegistroEmpleado())
            {
                cout << " EL EMPLEADO FUE REGISTRADO CORRECTAMENTE" << endl;
            }
            else
            {
                cout << "ERROR AL REGISTRAR EL EMPLEADO" << endl;
            }
        }
        break;
        case 6:
        {
            cout<<" \t \t *****EMPLEADOS DISPONIBLES***** " << endl;
            cout<<"----------------------"<<endl;
            ArchivoEmpleado archiE("Empleados.dat");
            if(archiE.MostrarRegistrosEmpleado())
            {
                cout << "----------------------";
            }
            else
            {
                cout << " ---VOLVIENDO AL MENU--- " ;
            }
            char a; // variable
            a = (char)getch();
        }
        break;
        case 7:
        {
            ArchivoEmpleado archiE("Empleados.dat");
            if(archiE.bajaLogicaRegistroEmpleado())
            {
                char a; // variable
                a = (char)getch();
                cout << "EL EMPLEADO FUE DADO DE BAJA CORRECTAMENTE";
            }
            else
            {
                cout << " |--VOLVIENDO AL MENU--| " ;
            }
            char a; // variable
            a = (char)getch();
        }
        return menu_administrador();
        break;

        case 0:
            menu_general();
            return 0;

        default:
            cout<<"OPCION INCORRECTA"<<endl;
            break;
        }
    }
    return 0;
}





  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///                                              MENU EMPLEADO                                                          ///

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







int menu_empleado()
{
    int opci;
    while(true)
    {
        system("cls");

        gotoxy(55,4);
        cout<<"MENU EMPLEADO"<<endl;
        gotoxy(45,7);
        cout<<"============"<<fechaa.toString()<<"================"<<endl;
        dibujarCuadro(30,3,90,24);
        gotoxy(45,9);
        cout<<"1- CARGAR MESA "<<endl;
        gotoxy(45,11);
        cout<<"2- VER MESA DISPONIBLES"<<endl;
        gotoxy(45,13);
        cout<<"3- SACAR CUENTA "<<endl;
        gotoxy(45,17);
        cout<<"============================"<<endl;
        gotoxy(45,19);
        cout<<"0- VOLVER MENU PRINCIPAL "<<endl;
        gotoxy(45,22);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opci;
        system("cls");
        /// abro archivos
            ArchivoDetalleFactura ArchDetalle;
            ArchivoMesa archM;
            Mesa regMesa;
            DetalleFactura regdetalle;
        ///
        /// SETEO EL VEC TEMPORAL MESA

        ///
        if (vmesa== NULL) return 0;
        int nummesa;
        int cantIdFactura= 0;

        switch(opci)
        {
        case 1:
            {


            gotoxy(45,4);
            cout << "INGRESAR NUMERO DE LA MESA A CARGAR"<< endl;
            cin >> nummesa;


            bool existe = false;
            cantIdFactura = ArchDetalle.contarRegistrosDetalleFactura();
            int cantIdMesa = archM.contarRegistrosMesa();
            int idfac = vmesa[nummesa].getidFactura();

            for (int x=0 ; x<cantIdMesa; x++)
            {

            regMesa = archM.leerRegistroMesa(x);
            if(nummesa == regMesa.getNumero() && regMesa.getEstado()==1)
            {

            for (int i=0; i<cantIdFactura; i++)
            {
                regdetalle = ArchDetalle.leerRegistroDetalleFactura(i);

                if (regMesa.getidFactura()==regdetalle.getIDFactura())
                {
                    existe=true;
                }
            }
        }
    }


            if (existe==false)
            {
                if (cantIdFactura == -1) // me aseguro que el primer registro no tenga idfactura = 0
                {
                vmesa[nummesa].setidFactura(1);
                regMesa.CargarPedidoMesa(vmesa[nummesa].getidFactura()); /// me aseguro que el idfactura no sea repetido
                existe ==true;
                archM.GrabarRegistroMesa(nummesa,1,vmesa[nummesa].getidFactura());
                }
                else {

                vmesa[nummesa].setidFactura(cantIdMesa+1);
                regMesa.CargarPedidoMesa(vmesa[nummesa].getidFactura()); /// me aseguro que el idfactura no sea repetido
                existe == true;
                archM.GrabarRegistroMesa(nummesa,1,vmesa[nummesa].getidFactura());
                }


            }

            else
            {

                regMesa.CargarPedidoMesa(vmesa[nummesa].getidFactura()); /// si la mesa existe lo cargo contra lo que ya este

            }


            }

                break;
            case 2:
            {
                DetalleFactura regDetalle;
                int idfactura;
                  cout << "INGRESAR NUMERO DE LA MESA A MOSTRAR: ";
                  cin >> nummesa;
                  cout<<endl;

                int cant = archM.contarRegistrosMesa();
                for (int i=0; i<cant ; i++)
                {
                regMesa = archM.leerRegistroMesa(i);
                if(regMesa.getNumero()==nummesa && regMesa.getEstado()==true)
                {
                    idfactura = regMesa.getidFactura();
                    cout<< " MESA VINCULADA: " << regMesa.getNumero() <<endl;

                }

                }

                    ArchDetalle.MostrarDetalleFacturaXIdFactura(idfactura);
                    system("pause");
            }
                break;
            case 3:{

                DetalleFactura regDetalle;
                  cout << " INGRESAR NUMERO DE LA MESA QUE DESEE SACAR LA CUENTA: ";
                  cin >> nummesa;

                int cant = archM.contarRegistrosMesa();
                for (int i=0; i<cant ; i++)
                {
                regMesa = archM.leerRegistroMesa(i);
                if(regMesa.getNumero()==nummesa && regMesa.getEstado()==true)
                {
                int idfactura = regMesa.getidFactura();
                  regDetalle.TotalDeFacturacion(idfactura);
                 if(archM.BajaLogicaEstadoMesa(idfactura)) cout << "Cuenta sacada con exito"<< endl;

                  break;

                }

                }

                    system("pause");
            }



            case 0:
                menu_general();
                return 0;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    }
            return 0;
}











