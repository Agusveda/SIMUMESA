#include<cstring>
#include<cstdlib>
#include <iostream>
#include <windows.h>
#include "rlutil.h"
#include "decoracion.h"
#include "Cargar_Cadena.h"

using namespace std;




bool login() {
    const char* usuario = "Admin";
    const char* contrasenia = "12345";

    gotoxy(45,9);   cout << "Login" << endl;
    gotoxy(45,11);cout<<"============================"<<endl;
    gotoxy(45,17);cout<<"============================"<<endl;
    gotoxy(45,13); cout << "Usuario: ";
    char usuario2[20];
    cargar_cadena(usuario2, 19);
    gotoxy(45,15);    cout << "password: ";
    char contrasenia2[20];
    asteriscos_contrasenia(contrasenia2);
    system("cls");

    bool contraCorrectas=0;
    if (strcmp(usuario2, usuario) == 0 && strcmp(contrasenia2, contrasenia) == 0)
    {
        contraCorrectas=1;

    }
    else {contraCorrectas=0;}

    return contraCorrectas;

}



void asteriscos_contrasenia(char frase[])
{


    int i=0;
    cout.flush(); // limpia la linea
	int aux=0;

    do
    {
        frase[i] = (char)getch(); /// funcion getch nos ayuda a poder tomar cada valor ingresado sin apretar enter


        if(frase[i]!=8)  // no es retroceso
        {
            cout << '*';  // muestra por pantalla
            i++;

            if (frase[i-1]==13){
        		printf("\b \b"); // espacio y retroceso
			}
        }



        else if(i>0)    // es retroceso y hay caracteres
        {
            cout << (char)8 << (char)32 << (char)8;
            i--;  //el caracter a borrar e el backspace
        }


        cout.flush();

    }while(frase[i-1]!=13);  // si presiona ENTER

    frase[i-1] = 0;
}
















/// HACE LAS LINEAS PARA EL MENU PRINCIPAL (MAS QUE NADA DISEÑO)


void dibujarCuadro(int x1,int y1,int x2,int y2)
{

    int i;
    for (i=x1;i<x2;i++)
    {
	gotoxy(i,y1);cout << "Ä" ;   //linea horizontal superior
	gotoxy(i,y2);cout << "Ä" ;   //linea horizontal inferior
    }
    for (i=y1;i<y2;i++)
    {
	gotoxy(x1,i);cout << "³" ;   //linea vertical izquierda
	gotoxy(x2,i);cout << "³" ;   //linea vertical derecha
    }
    gotoxy(x1,y1);cout << "Ú";   //esquina superior izquierda
    gotoxy(x1,y2);cout << "À";  // esquina inferior izquierda
    gotoxy(x2,y1);cout << "¿";  // esquina superior derecha
    gotoxy(x2,y2);cout << "Ù";  // esquina inferior derecha
}
