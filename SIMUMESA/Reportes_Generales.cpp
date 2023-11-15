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



    void ArticuloMasVendidoDia(){

    ArchivoDetalleFactura archidetallefac;
    DetalleFactura regdetallefac;
    int contRegdetallefac = archidetallefac.contarRegistrosDetalleFactura();
    Fecha fechactual;

    ArchivoArticulo ArchArt("Articulos.dat");
    Articulo RegArt;
    int contarArticulos= ArchArt.contarRegistrosArticulo();
    int ArtMasvendido=0;
    int cantamax=0;
    for(int i=0;i<contRegdetallefac;i++){
        regdetallefac=archidetallefac.leerRegistroDetalleFactura(i);

        for(int x=0;x<contarArticulos;x++){

            RegArt=ArchArt.leerRegistroArticulo(x);

            if(RegArt.getCodigoArticulo()==regdetallefac.getIDArticulo()){

               if(regdetallefac.getCantidad()>ArtMasvendido)
               {
                   cantamax = regdetallefac.getCantidad();
                   ArtMasvendido = regdetallefac.getIDArticulo()+1;

               }



            }
        }

    }

     for(int x=0;x<contarArticulos;x++){
        RegArt=ArchArt.leerRegistroArticulo(x);
        if (ArtMasvendido==RegArt.getCodigoArticulo())
        {
     cout << "EL ARTICULO MAS VENDIDO DEL DIA "<< " FUE : " ;
            cout << RegArt.getNombreArticulo() << "CON LA CANTIDAD DE: :"<<cantamax;;


        }

     }

    }
    /*
    int Minimo=Vec[0];
    int Arti;
    for(int x=0;x<contarArticulos;x++){
        if(Vec[x]<Minimo&&Vec[x]!=0){
            Minimo=Vec[x];
            Arti=x;
        }

    }



    */
