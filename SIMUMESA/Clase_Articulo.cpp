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
    int Articulo::getTipoArticulo(){return _TipoArticulo;}

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
        cout << "INTRODUCIR EL CODIGO DEL ARTICULO:)" <<endl;
        cin >> _CodArticulo;
        cout << "INTRODUCIR TIPO DE ARTICULO "<< endl;
        cin>> _TipoArticulo;
        cout << "INTRODUCIR NOMBRE DEL ARTICULO: "<<endl;
        cargar_cadena(_NombreArticulo, 29);
        cout << "INTRODUCIR PRECIO DEL ARTICULO :"<<endl;
        cin>>_Precio;
        cout<< "INGRESAR EL STOCK"<<endl;
        cin>>_Stock;
        _EstadoArticulo = true;
    }


    ///MUESTRA EMPLEADO
    void Articulo::MostrarArticulo()
    {



       cout << "Codigo: "<<_CodArticulo<<endl;
        cout << "Tipo articulo: ";
       if(_TipoArticulo == 1){cout << "ENTRADA";}
        else if (_TipoArticulo == 2){cout <<"MINUTAS";}
        else if (_TipoArticulo == 3){cout <<"HAMBURGUESAS";}
        else if (_TipoArticulo == 4){cout <<"BEBIDAS";}
        else {cout <<"POSTRES";}
       cout << endl;
       cout << "Nombre: "<<_NombreArticulo<<endl;
       cout << "Precio: "<<_Precio<<endl;
       cout << "Stock : "<<_Stock<<endl;
    }


  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///                                              CLASE ARCHIVO ARTICULO                                                 ///

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    registro.CargarArticulo();
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
        registro.MostrarArticulo();
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

    int ArchivoArticulo::contarRegistrosArticulo(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Articulo);
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

    bool ArchivoArticulo::MostrarRegistrosXTipoArticulo(int tipoart)
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
            if(reg.getTipoArticulo() == tipoart)
            {

            reg.MostrarArticulo();
            cout<<endl;
            }
        }
    }
    fclose(Art);
    return true;
    }

    /// MODIFICAR PRECIO ARTICULO
    bool ArchivoArticulo::ModificarPreciosArticulo ()
    {
        ArchivoArticulo archi("Articulos.dat");
        ///INGRESAR EL VALOR QUE IDENTIFICA EL REGISTRO A BORRAR
        int cod, pos;
        cout<<"INGRESAR EL CODIGO DEL ARTICULO ";
        cin>>cod;
        ///BUSCAR SI EL CODIGO EXISTE EN EL ARCHIVO.
        ///LA FUNCION DEVUELVE LA POSICIÓN DEL REGISTRO EN EL ARCHIVO. SI NO ENCUENTRA EL CODIGO DEVUELVE -1
        pos=archi.buscarCodArticulo(cod);
        if(pos==-1)
        {
            cout<<"NO EXISTE ESE CODIGO"<<endl;
            return false;
        }
        ///LEER EL REGISTRO DEL ARCHIVO Y PONERLO EN UNA VARIABLE DE MEMORIA
        Articulo reg;
        reg=archi.leerRegistroArticulo(pos);

        cout<<"REGISTRO A MODIFICAR "<<endl;
        reg.MostrarArticulo();
        cout<<endl;
        char opc;
        cout<<"DESEA MODIFICARLO? (S/N) ";
        cin>>opc;
        float precioNuevo;
       if(opc=='s'|| opc=='S')
        {
            cout<<"INGRESAR NUEVO PRECIO ";
            cin>>precioNuevo;
            reg.setPrecioArticulo(precioNuevo);
            ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO EN LA MISMA POSICION QUE TENÍA
            bool quePaso=archi.sobreEscribir_registroArticulo(reg, pos);
            cout << " EL ARTICULO QUEDARIA DE LA SIGUIENTE MANERA: " << endl;
            reg.MostrarArticulo();
            return quePaso;
        }
        return false;
    }


