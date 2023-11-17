#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Clase_Empleado.h"
#include "Cargar_Cadena.h"
#include "Validaciones.h"
    ///SETS
    void Empleado:: setLegajo(int Legajo){_Legajo=Legajo;}
    void Empleado:: setNombreEmpleado(const char *NombreEmpleado){strcpy(_NombreEmpleado,NombreEmpleado);}
    void Empleado:: setApellidoEmpleado(const char *ApellidoEmpleado){strcpy(_ApellidoEmpleado,ApellidoEmpleado);}
    void Empleado:: setEstado(bool estado){_EstadoEmpleado = estado;}
    ///GETS
    bool Empleado::getEstado(){return _EstadoEmpleado;}
    int Empleado::getLegajo(){return _Legajo;}
    const char *Empleado::getNombreEmpleado(){return _NombreEmpleado;}
    const char *Empleado::getApellidoEmpleado(){return _ApellidoEmpleado;}
    string  Empleado::getCargo()const {return (_Cargo==1?"ADMINITRADOR":"EMPLEADO/CAMARERO");}

    /// CONSTTRUCTOR:
    Empleado::Empleado()
    {
        strcpy(_NombreEmpleado, "");
        strcpy (_ApellidoEmpleado, "");
        _Legajo = 0;
        _Cargo = 0 ;
    }

    ///AGREGA EMPLEADO
    void Empleado::AgregarEmpleado()
    {
        cout << "INTRODUCIR EL LEGAJO DEL EMPLEADO :" <<endl;
        cin >> _Legajo;
        ValidarInt(_Legajo);
        cout << "INTRODUCIR NOMBRE DEL EMPLEADO :"<<endl;
        cargar_cadena(_NombreEmpleado, 29);
        cout << "INTRODUCIR APELLIDO DEL EMPLEADO :"<<endl;
        cargar_cadena(_ApellidoEmpleado, 29);
        cout<< "INGRESAR CARGO DEL EMPLEADO "<<endl;
        cout<<"PRECIONE (1) ADMINISTRADOR, PRECIONES (2) PARA EMPLEADO "<<endl;
        cin>>_Cargo;
        _EstadoEmpleado = true;
    }


    ///MUESTRA EMPLEADO
    void Empleado::MostrarEmpleado()
    {
       cout << "Legajo: "<<_Legajo<<endl;
       cout << "Nombre: "<<_NombreEmpleado<<endl;
       cout << "Apellido: "<<_ApellidoEmpleado<<endl;
       cout << "Cargo: "<<getCargo()<<endl;
    }



    ///GRABAR ARCHIVO EMPLEADO
    bool ArchivoEmpleado::GrabarRegistroEmpleado(){
    Empleado registro;
    FILE *Emp;
    Emp = fopen("Empleados.dat", "ab");
    if (Emp == nullptr){
        cout << " ERROR DE ARCHIVO" << endl;
        system("pause");
        return false;
    }

    cout << "INGRESAR LOS VALORES DEL REGISTRO DEL EMPLEADO"<< endl;
    registro.AgregarEmpleado();
    bool escribio = fwrite(&registro , sizeof registro, 1 , Emp);
    fclose(Emp);
    return escribio;
    }



    ///MOSTRAR EL ARCHIVO
    bool ArchivoEmpleado::MostrarRegistrosEmpleado(){
    Empleado reg;
    FILE *Emp;
    Emp= fopen("Empleados.dat","rb");
       if(Emp==NULL){
    cout<< "ERROR AL ABRIR EL ARCHIVO "<<endl;
    return false;
    }
    while(fread (&reg,sizeof reg, 1,Emp)==1){
    if(reg.getEstado()==true){
    reg.MostrarEmpleado();
    cout<<endl;
    }
	}
	fclose(Emp);
    return true;
}





    /// Baja logica empleado
    bool ArchivoEmpleado::bajaLogicaRegistroEmpleado(){

    int id, pos;
    cout << "ingresar el Legajo a dar de baja : ";
    cin >> id;


    /// busca si el id existe en el archivo
    pos = buscarLegajoEmpleado(id);
    if (pos == -1)
    {
        cout << " no existe el legajo" << endl;
        return false;
    }

    /// LEE EL REGISTRO DEL ARCHIVO Y LO PONE EN UNA VARIABLE
    Empleado registro;
    registro = leerRegistroEmpleado(pos);
    cout << "registro a borrar" << endl;
    registro.MostrarEmpleado();
    cout << endl;
    char opc;

    cout << "DESEA ELIMINAR REGISTRO (s/n)" << endl;
    cin >> opc;

    if (opc == 's' || opc == 'S'){
        registro.setEstado(false);
        bool quepaso=sobreEscribir_registroEmpleado(registro,pos);
        return quepaso;
    }


    return false;
}
int ArchivoEmpleado::buscarLegajoEmpleado( int legajo ){
    Empleado registro;
    FILE *p;
    int pos = 0 ;
    p = fopen("Empleados.dat","rb");
    if ( p == NULL){
        return -2;
    }
    while (fread(&registro,sizeof registro, 1, p) ==1){
        if (legajo == registro.getLegajo()){
            fclose(p);
            return pos;
            cout << "el legajo esta en la posicion " << pos;
        }

        pos++;

    }

    fclose(p);
    return -1;




}

Empleado ArchivoEmpleado::leerRegistroEmpleado(int pos){
        Empleado reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    bool ArchivoEmpleado::sobreEscribir_registroEmpleado(Empleado registro, int pos){


    FILE *p;
    p=fopen("Empleados.dat","rb+"); // EL + NOS PERMITE AGREGAR AL MODO LO QUE LE FALTA
    if(p==NULL){                      // EJEMPLO RB LEE Y CON EL + ESCRIBE TAMBIEN
        return false;
    }

    fseek(p,sizeof registro * pos, 0);
    bool escribio = fwrite(&registro,sizeof registro,1,p);
    fclose(p);
    return escribio;

}





