#ifndef CLASE_EMPLEADO_H
#define CLASE_EMPLEADO_H


class Empleado{
    private:
        int _Legajo;
        char _NombreEmpleado[30], _ApellidoEmpleado[30];
        int _Cargo;

    public:
        ///CONTRUCTOR
       Empleado(){
            strcpy(_NombreEmpleado, "");
            strcpy (_ApellidoEmpleado, "");
            _Legajo = 0;
            _Cargo = 0;}


    ///SETS
    void setLegajo(int Legajo);
    void setNombreEmpleado(const char *NombreEmpleado);
    void setApellidoEmpleado(const char *ApellidoEmpleado);
    void setCargo(int Cargo);

    ///GETS
    int getLegajo();
    const char *getNombreEmpleado();
    const char *getApellidoEmpleado();
    int getCargo();


    void AgregarEmpleado();
    void MostrarEmpleado();

};

 class ArchivoEmpleado{
    private:
    public:

    /// FUNCIONES
        bool GrabarRegistroEmpleado();
        bool MostrarRegistros();

};

#endif // CLASE_EMPLEADO_H


