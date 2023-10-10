#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Clase_Empleado.h"
#include "Cargar_Cadena.h"

    ///SETS
    void Empleado:: setLegajo(int Legajo){_Legajo=Legajo;}
    void Empleado:: setNombreEmpleado(const char *NombreEmpleado){strcpy(_NombreEmpleado,NombreEmpleado);}
    void Empleado:: setApellidoEmpleado(const char *ApellidoEmpleado){strcpy(_ApellidoEmpleado,ApellidoEmpleado);}
    void Empleado:: setCargo(int Cargo){_Cargo=Cargo;}

    ///GETS
    int Empleado::getLegajo(){return _Legajo;}
    const char *Empleado::getNombreEmpleado(){return _NombreEmpleado;}
    const char *Empleado::getApellidoEmpleado(){return _ApellidoEmpleado;}
    int Empleado::getCargo(){return _Cargo;}



    ///AGREGA EMPLEADO
    void Empleado::AgregarEmpleado()
    {
        cout << "introducir Legajo de la Hamburguesa" <<endl;
        cin >> _Legajo;
        cout << "introducir nombre de empleado : "<<endl;
        cargar_cadena(_NombreEmpleado, 29);
        cout << "introducir Apellid de empleado :"<<endl;
        cargar_cadena(_ApellidoEmpleado, 29);
        cout<< "Ingresar el cargo "<<endl;
        cin>>_Cargo;
    }


    ///MUESTRA EMPLEADO
    void Empleado::MostrarEmpleado()
    {
       cout << "Legajo: "<<_Legajo<<endl;
       cout << "Nombre: "<<_NombreEmpleado<<endl;
       cout << "Apellido: "<<_ApellidoEmpleado<<endl;
       cout << "Cargo: "<<_Cargo<<endl;
    }



    ///GRABAR ARCHIVO EMPLEADO
    bool ArchivoEmpleado::GrabarRegistroEmpleado(){
    Empleado registro;
    FILE *Emp;
    Emp = fopen("Empleado.dat", "ab");
    if (Emp == nullptr){
        cout << " ERROR DE ARCHIVO" << endl;
        system("pause");
        return false;
    }

    cout << "INGRESAR LOS VALORES DEL REGISTRO"<< endl;
    registro.AgregarEmpleado();
    bool escribio = fwrite(&registro , sizeof registro, 1 , Emp);
    fclose(Emp);
    return escribio;
    }



    ///MOSTRAR EL ARCHIVO
    bool Mostrarregistros(){
    Empleado reg;
    FILE *Emp;
    Emp= fopen("Empleado.dat","rb");
       if(Emp==NULL){
    cout<< "ERROR AL ABRIR EL ARCHIVO "<<endl;
    return false;
    }
    while(fread (&reg,sizeof reg, 1,Emp)==1){
    reg.MostrarEmpleado();
    cout<<endl;
	}
	fclose(Emp);
    return true;
}



