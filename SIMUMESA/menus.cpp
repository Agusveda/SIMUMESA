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

/// MENU GENERAL DONDE VAN A ESTAR LAS OPCIONES PRINCIPALES PARA EL INICIO DEL SISTEMA

int menu_general()
{
    int opc;
    while(true){
        system("cls");

        gotoxy(55,4);cout<<"MENU PRINCIPAL"<<endl;
        gotoxy(45,7);cout<<"============================"<<endl;
        dibujarCuadro(30,3,90,20);
        gotoxy(45,9);cout<<"1- INGRESAR COMO ADMINISTRADOR"<<endl;
        gotoxy(45,11);cout<<"2- INGRESAR COMO EMPLEADO"<<endl;
        gotoxy(45,13);cout<<"============================"<<endl;
        gotoxy(45,15);cout<<"0 - CERRAR PROGRAMA"<<endl;
        gotoxy(45,18);cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        cout<<endl;
        system("cls");
        switch(opc){
            case 1:
                int loginResult;

                do {
                loginResult = login();

                if (loginResult == 1)
                {
                gotoxy (45,10); cout << "INGRESO AL SISTEMA" << endl;
                menu_administrador();    //  LLAMA A LA FUNCION DEL MENU DEL ADMINISTRADOR AQUI
                }
                else{
                cout << endl;
                gotoxy (45,13);  cout << "PASSWORD O USUARIO INCORRECTOS" << endl;
                gotoxy (45,15); cout << "PRESIONE CUALQUIER TECLA PARA VOLVER A INTENTAR" << endl;

                char a; // variable
                a = (char)getch(); // FUNCION DE CONIO.H QUE TOMA UN CARACTER PARA CONTINUAR, FUNCION PARECIDA A SYSTEM("PAUSE")
                system("cls");
                    }
                }
                while (loginResult != 1);


            break; // FINALIZA OPCION 1


            case 2:
                gotoxy (45,10); cout << "INGRESO AL SISTEMA" << endl;
                menu_empleado();
                break;
            case 0:
            cout << " ADIOS, UN GUSTO!";
                return 0;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                system("cls");
                break;
        }
    system("pause>null");
    }
}


/// MENU PARA EL ADMINISTRADOR, LUEGO DEL INGRESAR CON "1" AL MENU PRINCIPAL

int menu_administrador()
{
    int opci;
    while(true){
        system("cls");

        gotoxy(55,4);cout<<"MENU ADMINISTRADOR"<<endl;
        gotoxy(45,7);cout<<"============================"<<endl;
        dibujarCuadro(30,3,90,26);
        gotoxy(45,9);cout<<"1- MODIFICAR PRECIO DE LA CARTA"<<endl;
        gotoxy(45,11);cout<<"2- VER PRECIO DE LA CARTA "<<endl;
        gotoxy(45,13);cout<<"3- VER STOCK ACTUAL"<<endl;
        gotoxy(45,15);cout<<"4- RENOVAR STOCK"<<endl;
        gotoxy(45,17);cout<<"5- AGREGAR EMPLEADO"<<endl;
        gotoxy(45,19);cout<<"6- MOSTRAR EMPLEADOS EXISTENTES"<<endl;
        gotoxy(45,21);cout<<"============================"<<endl;
        gotoxy(45,22);cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        gotoxy(45,24);cout<<"INGRESE UNA OPCION: ";
        cin>>opci;
        system("cls");

        switch(opci){
            case 1:
                cout << "elegiste caso 1"<< endl;
                break;
            case 2:
                cout << "elegiste caso 2"<< endl;
                break;
            case 3:
                cout << "elegiste caso 3"<< endl;
                break;
            case 4:
                cout << "elegiste caso 4"<< endl;
                break;

            case 5:{

                    ArchivoEmpleado archiE("Empleado.dat");
                    if(archiE.GrabarRegistroEmpleado()) {cout << " EL EMPLEADO FUE REGISTRADO CORRECTAMENTE" << endl;}
                    else {cout << "ERROR AL REGISTRAR EL EMPLEADO" << endl;}
            }
            break;
            case 6:{
                ArchivoEmpleado archiE("Empleados.dat");
                if(archiE.MostrarRegistrosEmpleado()){
                        char a; // variable
                        a = (char)getch();
                        cout << "estos fueron los empleados";}
                else { cout << "ERROR" ;}

            }



            case 0:
                menu_general();
                return 0;
                break;

            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    system("pause");
    }
}
int menu_empleado()
{
    int opci;
    while(true){
        system("cls");

        gotoxy(55,4);cout<<"MENU EMPLEADO"<<endl;
        gotoxy(45,7);cout<<"============================"<<endl;
        dibujarCuadro(30,3,90,24);
        gotoxy(45,9);cout<<"1- CARGAR MESA "<<endl;
        gotoxy(45,11);cout<<"2- VER MESA "<<endl;
        gotoxy(45,13);cout<<"3- SACAR CUENTA "<<endl;
        gotoxy(45,17);cout<<"============================"<<endl;
        gotoxy(45,19);cout<<"0- VOLVER MENU PRINCIPAL "<<endl;
        gotoxy(45,22);cout<<"INGRESE UNA OPCION: ";
        cin>>opci;
        system("cls");

        switch(opci){
            case 1:
                gotoxy(45,4);cout << "INGRESAR lEGAJO DE EMPLEADO "<< endl;


                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                cout << "elegiste caso 4"<< endl;

                break;
            case 0:
                menu_general();
                return 0;
                break;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    system("pause");
    }
}











