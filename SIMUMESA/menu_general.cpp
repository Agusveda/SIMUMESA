#include<cstring>
#include<cstdlib>
#include <iostream>
#include "rlutil.h"
#include "menu_general.h"
#include <conio.h>
#include <windows.h>

using namespace std;


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
        system("cls");
        switch(opc){
            case 1:
                cout << "elegiste caso 1"<< endl;
                menu_administrador();
                return 0;
                break;
            case 2:
                cout << "elegiste caso 2"<< endl;
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

/// HACE LAS LINEAS PARA EL MENU PRINCIPAL (MAS QUE NADA DISENIO)


void dibujarCuadro(int x1,int y1,int x2,int y2)
{

    int i;
    for (i=x1;i<x2;i++)
    {
	gotoxy(i,y1);printf("Ä") ;//linea horizontal superior
	gotoxy(i,y2);printf("Ä") ;//linea horizontal inferior
    }

    for (i=y1;i<y2;i++)
    {
	gotoxy(x1,i);printf("³") ;//linea vertical izquierda
	gotoxy(x2,i);printf("³") ;//linea vertical derecha
    }
    gotoxy(x1,y1);printf("Ú");
    gotoxy(x1,y2);printf("À");
    gotoxy(x2,y1);printf("¿");
    gotoxy(x2,y2);printf("Ù");
}



/// MENU PARA EL ADMINISTRADOR, LUEGO DEL INGRESAR CON "1" AL MENU PRINCIPAL

int menu_administrador()
{
    int opci;
    while(true){
        system("cls");

        gotoxy(55,4);cout<<"MENU ADMINISTRADOR"<<endl;
        gotoxy(45,7);cout<<"============================"<<endl;
        dibujarCuadro(30,3,90,24);
        gotoxy(45,9);cout<<"1- MODIFICAR PRECIO DE LA CARTA"<<endl;
        gotoxy(45,11);cout<<"2- VER PRECIO DE LA CARTA "<<endl;
        gotoxy(45,13);cout<<"3- RENOVAR STOCK"<<endl;
        gotoxy(45,15);cout<<"4- VER STOCK ACTUAL"<<endl;
        gotoxy(45,17);cout<<"============================"<<endl;
        gotoxy(45,19);cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        gotoxy(45,20);cout<<"INGRESE UNA OPCION: ";
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
                return 0;
                break;
            case 0:
                menu_general();
                return 0;
                break;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    system("pause>null");
    }



}







