#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Cargar_Cadena.h"
#include "Clase_Minutas.h"


    void Minutas::setNombreMinutas(const char *_nombreminutas){strcpy(nombreMinutas,_nombreminutas);}
    void Minutas::setPrecioMinutas(float _precioMinutas){precioMinutas = _precioMinutas;}
    void Minutas::setStockMinutas(int _stockMinutas){stockMinutas = _stockMinutas;}
    void Minutas::setIdMinutas (int _id){id = _id;}
    void Minutas::setEstadoMinutas( bool _Estado){estado= _Estado;}

    // GET

    const char *  Minutas::getNombreMinutas(){return nombreMinutas;}
    float Minutas::getPrecioMinutas(){return precioMinutas;}
    int Minutas::getStockMinutas(){return stockMinutas;}
    int Minutas::getIdMinutas(){return id;}
    bool Minutas::getEstadoMinutas(){return estado;}

    void Minutas::mostrarMinutas()
    {
       cout << id << "  "  << nombreMinutas << "             $ " << precioMinutas << "             stock disponible: "<< stockMinutas;
    }
    void Minutas::agregarminutas()
    {
        cout << "introducir ID de la minutas" ;
        cin >> id;
        cout << "introducir nombre de minuta : ";
        cargar_cadena(nombreMinutas, 19);
        cout << "introducir precio de la minuta :";
        cin >> precioMinutas;
    }




    /// FUNCIONES DE ARCHIVO MINUTAS






    bool ArchivoMinutas::modificarMinutas()
    {
    ArchivoMinutas archi("minutas.dat");
    int id, pos;
    cout << "ingresar el ID de la minuta a modificar : ";
    cin >> id;


    /// busca si el id existe en el archivo
    pos = archi.buscar_IdMinutas(id);
    if (pos == -1)
    {
        cout << " no existe el iID" << endl;
        return false;
    }

    /// lee el registro del archivo y lo pone en una variable
    Minutas registro;
    registro = archi.leerRegistroMinutas(pos);
    cout << "registro a modificar" << endl;
    registro.mostrarMinutas();
    cout << endl;
    char opc;

    cout << "DESEA MODIFICAR EL REGISTRO (s/n)" << endl;
    cin >> opc;
    char nombreMinutasNuevo[20];
    if (opc == 's' || opc == 'S'){
        cout << "ingresar nuevo titulo secundario" << endl;
        cargar_cadena(nombreMinutasNuevo,19);

        registro.setNombreMinutas(nombreMinutasNuevo);

        bool quepaso=archi.sobreEscribir_registroMinutas(registro,pos);
        return quepaso;

    }
    return false;
}



    bool ArchivoMinutas::sobreEscribir_registroMinutas(Minutas registro, int pos){


    FILE *p;
    p=fopen("minutas.dat","rb+"); // EL + NOS PERMITE AGREGAR AL MODO LO QUE LE FALTA
                                // EJEMPLO RB LEE Y CON EL + ESCRIBE TAMBIEN
    if(p==NULL){
        return false;
    }

    fseek(p,sizeof registro * pos, 0);
    bool escribio = fwrite(&registro,sizeof registro,1,p);
    fclose(p);
    return escribio;

}

    int ArchivoMinutas::bajaLogicaRegistroMinutas(){

    int id, pos;
    cout << "ingresar el id del alumno a dar de baja : ";
    cin >> id;


    /// busca si el id existe en el archivo
    pos = buscar_IdMinutas(id);
    if (pos == -1)
    {
        cout << " no existe el ID" << endl;
        return false;
    }

    /// lee el registro del archivo y lo pone en una variable
    Minutas registro;
    registro = leerRegistroMinutas(pos);
    cout << "registro a borrar" << endl;
    registro.mostrarMinutas();
    cout << endl;
    char opc;

    cout << "DESEA ELIMINAR REGISTRO (s/n)" << endl;
    cin >> opc;

    if (opc == 's' || opc == 'S'){
        registro.setEstadoMinutas(false);
        bool quepaso=sobreEscribir_registroMinutas(registro,pos);
        return quepaso;

    }
    return false;
}


    Minutas ArchivoMinutas::leerRegistroMinutas(int pos){
        Minutas reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    int ArchivoMinutas::contarRegistrosMinutas(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Minutas);
    }

    bool ArchivoMinutas::grabarRegistroMinutas(){


    Minutas registro;
    FILE *pAlu;

    pAlu = fopen("minutas.dat", "ab"); /// SE USA AD QUE ES PARA ADD BINARY, ANIADIR
    if (pAlu == nullptr){
        cout << " ERRROR DE ARCHIVO" << endl;
        system("pause");
        return false;
    }

    cout << "INGRESAR LOS VALORES DEL REGISTRO"<< endl;
    registro.agregarminutas();
    bool escribio = fwrite(&registro , sizeof registro, 1 , pAlu);
    fclose(pAlu);
    return escribio;


 }


    int ArchivoMinutas::buscar_IdMinutas( int id ){
    Minutas registro;
    FILE *p;
    int pos = 0 ;
    p = fopen("alumnos.dat","rb");
    if ( p == NULL){
        return -2;
    }
    while (fread(&registro,sizeof registro, 1, p) ==1){
        if (id == registro.getIdMinutas()){
            fclose(p);
            return pos;
            cout << "el id esta en la posicion " << pos;
        }
        pos++;
    }
    fclose(p);
    return -1;

  }




