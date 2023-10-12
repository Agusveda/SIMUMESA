#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Clase_Articulo.h"
#include "Cargar_Cadena.h"

    ///SETS
    void Articulo:: setCodigoArticulo(int codArticulo){_CodArticulo=codArticulo;}
    void Articulo:: setNombreArticulo(const char *NombreArticulo){strcpy(_NombreArticulo,NombreArticulo);}
    void Articulo:: setPrecioArticulo(float precio){_Precio=precio;}
    void Articulo:: setStock(int stock){_Stock=stock;}
    void Articulo:: setEstadoArticulo(bool estado){_EstadoArticulo = estado;}
    ///GETS
    bool Articulo::getEstadoArticulo(){return _EstadoArticulo;}
    int Articulo::getCodigoArticulo(){return _CodArticulo;}
    const char *Articulo::getNombreArticulo(){return _NombreArticulo;}
    float Articulo::getPrecioArticulo(){return _Precio;}
    int Articulo::getStock(){return _Stock;}

    ///CONSTRUCTOR:
    Articulo::Articulo ()
    {
        _CodArticulo=0;
        strcpy(_NombreArticulo, " ");
        _Precio=0;
        _Stock=0;
        _EstadoArticulo=true;
    }

    ///AGREGA EMPLEADO
    void Articulo::CargarArticulo()
    {
        cout << "introducir el codigo del articulo :)" <<endl;
        cin >> _CodArticulo;
        ///FALTA TIPO ARTICULO
        cout << "introducir nombre del articulo: "<<endl;
        cargar_cadena(_NombreArticulo, 29);
        cout << "introducir precio del articulo :"<<endl;
        cin>>_Precio;
        cout<< "Ingresar el cargo "<<endl;
        cin>>_Stock;
        _EstadoArticulo = true;
    }


    ///MUESTRA EMPLEADO
    void Articulo::MostrarArticulo()
    {
       cout << "Codigo: "<<_CodArticulo<<endl;
       cout << "Nombre: "<<_NombreArticulo<<endl;
       cout << "Precio: "<<_Precio<<endl;
       cout << "Stock : "<<_Stock<<endl;
    }
    /////////////////////////////////////////////////////////////////////////////
    ///SET:
     void TipoArticulo::setIdTipoArticulo(int idArt){_idTipoArticulo=idArt;}
     void TipoArticulo::setNombreTipoArticulo(const char *NombreTipoArticulo){strcpy(_NombreTipoArticulo,NombreTipoArticulo);}
     ///GET:
     int TipoArticulo::getIdTipoArticulo(){return _idTipoArticulo;}
     const char *TipoArticulo::getNombreTipoArticulo(){return _NombreTipoArticulo;}


    TipoArticulo::CargarTipoArticulo()
    {
        cout<<" CODIGO DEL ARTICULO: ";
        cin>>_idTipoArticulo;
        cout<<" TIPO DE ARTICULO: ";
        cargar_cadena(_NombreTipoArticulo,29);
    }

    TipoArticulo::MostrarTipoArticulo()
    {
        cout<<" CODIGO DEL ARTICULO: " << _idTipoArticulo <<endl;
        cout<<" TIPO DE ARTICULO: "<< _NombreTipoArticulo <<endl;
    }



    ///GRABAR ARCHIVO EMPLEADO
    bool ArchivoArticulo::GrabarRegistroArticulo(){
    Articulo registro;
    FILE *Art;
    Art = fopen("Articulos.dat", "ab");
    if (Art == nullptr){
        cout << " ERROR DE ARCHIVO" << endl;
        system("pause");
        return false;
    }

    cout << "INGRESAR LOS VALORES DE ARTICULO "<< endl;
    registro.MostrarArticulo();
    bool escribio = fwrite(&registro , sizeof registro, 1 , Art);
    fclose(Art);
    return escribio;
    }



    ///MOSTRAR EL ARCHIVO
    bool ArchivoArticulo::MostrarRegistrosArticulo(){
    Articulo reg;
    FILE *Art;
    Art= fopen("Articulos.dat","rb");
       if(Art==NULL){
    cout<< "ERROR AL ABRIR EL ARCHIVO "<<endl;
    return false;
    }
    while(fread (&reg,sizeof reg, 1,Art)==1){
    if(reg.getEstadoArticulo()==true){
    reg.MostrarArticulo();
    cout<<endl;
    }
	}
	fclose(Art);
    return true;
    }





    /// BAJA LOGICA ARTICULO
    bool ArchivoArticulo::bajaLogicaRegistroArticulo(){
    int id, pos;
    cout << "ingresar el codigo de articulo a dar de baja : ";
    cin >> id;
    /// busca si el id existe en el archivo
    pos = buscarCodArticulo(id);
    if (pos == -1)
    {
        cout << " no existe el codigo del articulo " << endl;
        return false;
    }
    /// LEE EL REGISTRO DEL ARCHIVO Y LO PONE EN UNA VARIABLE
    Articulo registro;
    registro = leerRegistroArticulo(pos);
    cout << "registro a borrar" << endl;
    registro.MostrarArticulo();
    cout << endl;
    char opc;
    cout << "DESEA ELIMINAR REGISTRO (s/n)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S'){
        registro.setEstadoArticulo(false);
        bool quepaso=sobreEscribir_registroArticulo(registro,pos);
        return quepaso;
    }
    return false;
    }


    int ArchivoArticulo::buscarCodArticulo( int codArticulo ){
    Articulo registro;
    FILE *p;
    int pos = 0 ;
    p = fopen("Articulos.dat","rb");
    if ( p == NULL){
        return -2;
    }
    while (fread(&registro,sizeof registro, 1, p) ==1){
        if (codArticulo == registro.getCodigoArticulo()){
            fclose(p);
            return pos;
            cout << "el legajo esta en la posicion " << pos;
        }

        pos++;

    }

    fclose(p);
    return -1;
    }


    Articulo ArchivoArticulo::leerRegistroArticulo(int pos){
        Articulo reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    bool ArchivoArticulo::sobreEscribir_registroArticulo(Articulo registro, int pos)
    {

        FILE *p;
        p=fopen("Articulos.dat","rb+"); // EL + NOS PERMITE AGREGAR AL MODO LO QUE LE FALTA
        if(p==NULL)                       // EJEMPLO RB LEE Y CON EL + ESCRIBE TAMBIEN
        {
            return false;
        }

        fseek(p,sizeof registro * pos, 0);
        bool escribio = fwrite(&registro,sizeof registro,1,p);
        fclose(p);
        return escribio;
    }
    bool ArchivoArticulo::MostrarRegistrosXTipoArticulo()
    {
    Articulo reg;
    FILE *Art;
    Art= fopen("Articulos.dat","rb");
    if(Art==NULL)
    {
        cout<< "ERROR AL ABRIR EL ARCHIVO "<<endl;
        return false;
    }
    while(fread (&reg,sizeof reg, 1,Art)==1)
    {
        if(reg.getEstadoArticulo()==true)
        {
            reg.MostrarArticulo();
            cout<<endl;
        }
    }
    fclose(Art);
    return true;
    }
