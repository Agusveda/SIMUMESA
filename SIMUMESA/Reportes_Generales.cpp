#include<cstring>
#include<cstdlib>
#include <iostream>
#include "Reportes_Generales.h"
#include "decoracion.h"
#include "rlutil.h"
#include "menus.h"
#include "clase_mesa.h"
#include "Cargar_Cadena.h"
#include "Clase_Empleado.h"
#include "Clase_Articulo.h"
#include "fecha.h"
#include "DetalleFactura.h"
#include "Clase_Factura.h"


    void ArticuloMasVendidoDia();
    void ArticuloMenosVendidoDia();
    void ArticuloMasVendidoMes();



    float RecaudacionDelDia(){
    ArchivoFactura archifac;
    Factura regfac;
    int contReg = archifac.contarRegistrosFactura();
    Fecha fechactual;
    float contImporte = 0;
    bool bandera = false;
    for(int i = 0 ; i < contReg ; i++)
    {
        regfac = archifac.leerRegistroFactura(i);
        if(regfac.getFechaFactura().getDia()==fechactual.getDia() && regfac.getCantidad()>0)
        {
            bandera =true;
            contImporte += regfac.getCantidad();

        }
    }
        if(bandera)
        {

            cout << "RECAUDACION DEL DIA " << fechactual.getDia() << " FUE : $" << contImporte << endl;
        }

    }



    float RecaudacionDelMes(){
    ArchivoFactura archifac;
    Factura regfac;
    int contReg = archifac.contarRegistrosFactura();
    Fecha fechactual;
    float contImportemes = 0;
    bool bandera = false;
    for(int i = 0 ; i < contReg ; i++)
    {
        regfac = archifac.leerRegistroFactura(i);
        if(regfac.getFechaFactura().getMes()==fechactual.getMes() && regfac.getCantidad()>0)
        {
            bandera =true;
            contImportemes += regfac.getCantidad();

        }
    }
        if(bandera)
        {

            cout << "RECAUDACION DEL MES " << fechactual.getMes() << " FUE : $" << contImportemes << endl;
        }

    }



    void ArticuloMenosVendidoDia(){

    ArchivoFactura archifac;
    Factura reg;
    int contReg = archifac.contarRegistrosFactura();
    Fecha fechactual;

    ArchivoArticulo ArchArt("Articulos.dat");
    Articulo RegArt;
    int contarArticulos= ArchArt.contarRegistrosArticulo();

    for(int i=0;i<contReg;i++){
        reg=archifac.leerRegistroFactura(i);
        cont
    }
    }



