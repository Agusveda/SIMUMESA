#ifndef CLASE_EMPLEADO_H
#define CLASE_EMPLEADO_H


class Empleado{
    private:
        int _Legajo;
        char _NombreEmpleado[30], _ApellidoEmpleado[30];
        int _Cargo;
        bool _EstadoEmpleado;

    public:
    ///CONTRUCTOR
       Empleado();

    ///SETS
    void setLegajo(int Legajo);
    void setNombreEmpleado(const char *NombreEmpleado);
    void setApellidoEmpleado(const char *ApellidoEmpleado);
    void setEstado(bool Estado);

    ///GETS
    bool getEstado();
    int getLegajo();
    const char *getNombreEmpleado();
    const char *getApellidoEmpleado();
    string getCargo()const;


    void AgregarEmpleado();
    void MostrarEmpleado();

};

 class ArchivoEmpleado{
    private:
         char nombre[30];

    public:
    ArchivoEmpleado(const char *n){
        strcpy(nombre, n);}

    /// FUNCIONES
        bool GrabarRegistroEmpleado();
        bool MostrarRegistrosEmpleado();
        bool bajaLogicaRegistroEmpleado();
        int  buscarLegajoEmpleado( int legajo );
        Empleado leerRegistroEmpleado(int pos);
        bool sobreEscribir_registroEmpleado(Empleado registro, int pos);
};




#endif // CLASE_EMPLEADO_H


