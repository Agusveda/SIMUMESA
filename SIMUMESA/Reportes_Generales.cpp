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

///---------------------------------------RECAUDACION--------------------------------------------------
float RecaudacionPorFecha(int dia, int mes, int anio) {
    ArchivoFactura archifac;
    Factura regfac;
    int contReg = archifac.contarRegistrosFactura();

    float contImporte = 0;
    bool bandera = false;

    for(int i = 0 ; i < contReg ; i++) {
        regfac = archifac.leerRegistroFactura(i);
        Fecha fechaFactura = regfac.getFechaFactura();

        if(fechaFactura.getDia() == dia && fechaFactura.getMes() == mes && fechaFactura.getAnio() == anio && regfac.getCantidad() > 0) {
            bandera = true;
            contImporte += regfac.getCantidad();
        }
    }

    if(bandera) {
        cout << "RECAUDACION POR FECHA " << dia << "/" << mes << "/" << anio << " FUE : $" << contImporte << endl;
    }
    else{
        cout<<"NO EXITEN REPORTES "<<endl;
    }

    return contImporte;
}


float RecaudacionDelDia() {
    Fecha fechactual;
    return RecaudacionPorFecha(fechactual.getDia(), fechactual.getMes(), fechactual.getAnio());
}


float RecaudacionDelMesYAnio(int mes, int anio) {
    return RecaudacionPorFecha(1, mes, anio); ///SE USA EL DIA PARA LEER DESDE EL PRIMER DIA DEL MES
}


float RecaudacionDelAnio(int anio) {
    return RecaudacionPorFecha(1, 1, anio); ///SE USA EL DIA 1 Y EL MES 1 PARA LEER DESDE EL PRINCIPIO DEL ANIO
}

///---------------------------------------------------------------------------------


/*float RecaudacionDelDia()
{
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
*/


float RecaudacionDelMes()
{
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



void ArticuloMasVendidoDia()
{

    ArchivoDetalleFactura archidetallefac;
    DetalleFactura regdetallefac;
    int contRegdetallefac = archidetallefac.contarRegistrosDetalleFactura();

    Fecha fechactual;

    ArchivoArticulo ArchArt("Articulos.dat");
    Articulo RegArt;

    ArchivoFactura archifac;
    Factura regfac;
    int contReg = archifac.contarRegistrosFactura();

    int contarArticulos= ArchArt.contarRegistrosArticulo();
    int ArtMasvendido=0;
    int cantamax=0;
    int vecrepetido[contarArticulos];

    for (int j=0; j<contReg; j++)
    {
        regfac=archifac.leerRegistroFactura(j);
        for(int i=0; i<contRegdetallefac; i++)
        {
            regdetallefac=archidetallefac.leerRegistroDetalleFactura(i);

            for(int x=0; x<contarArticulos; x++)
            {
                RegArt=ArchArt.leerRegistroArticulo(x);
                if(RegArt.getCodigoArticulo()==regdetallefac.getIDArticulo()&& regfac.getFechaFactura().getDia()==fechactual.getDia() && regdetallefac.getIDFactura()==regfac.getIdFactura())
                {
                    if(regdetallefac.getCantidad()>cantamax )
                    {
                        cantamax = regdetallefac.getCantidad();
                        ArtMasvendido = regdetallefac.getIDArticulo();
                    }
                    else if(regdetallefac.getCantidad()==cantamax)
                    {
                        vecrepetido[x] = regdetallefac.getIDArticulo();

                    }
                }
            }
        }
    }
    cout << "EL ARTICULO MAS VENDIDO DEL DIA " << fechactual.getDia() << " FUE: ";
    for(int x=0; x<contarArticulos; x++)
    {
        RegArt=ArchArt.leerRegistroArticulo(x);
        if (ArtMasvendido==RegArt.getCodigoArticulo() || vecrepetido[x] == RegArt.getCodigoArticulo())
        {
            cout <<" "<<  RegArt.getNombreArticulo() <<" |" << cantamax <<"|.  " ;
        }
    }
}


void ArticuloMasVendidoMes()
{
    ArchivoDetalleFactura archidetallefac;
    DetalleFactura regdetallefac;
    int contRegdetallefac = archidetallefac.contarRegistrosDetalleFactura();

    Fecha fechactual;

    ArchivoArticulo ArchArt("Articulos.dat");
    Articulo RegArt;

    ArchivoFactura archifac;
    Factura regfac;
    int contReg = archifac.contarRegistrosFactura();

    int contarArticulos= ArchArt.contarRegistrosArticulo();
    int ArtMasvendido=0;
    int cantamax=0;
    int vecrepetido[contarArticulos];

    for (int j=0; j<contReg; j++)
    {
        regfac=archifac.leerRegistroFactura(j);
        for(int i=0; i<contRegdetallefac; i++)
        {
            regdetallefac=archidetallefac.leerRegistroDetalleFactura(i);

            for(int x=0; x<contarArticulos; x++)
            {
                RegArt=ArchArt.leerRegistroArticulo(x);
                if(RegArt.getCodigoArticulo()==regdetallefac.getIDArticulo()&& regfac.getFechaFactura().getMes()==fechactual.getMes()&& regdetallefac.getIDFactura()==regfac.getIdFactura())
                {
                    if(regdetallefac.getCantidad()>cantamax )
                    {
                        cantamax = regdetallefac.getCantidad();
                        ArtMasvendido = regdetallefac.getIDArticulo();
                    }
                    else if(regdetallefac.getCantidad()==cantamax)
                    {
                        vecrepetido[x] = regdetallefac.getIDArticulo();
                    }
                }
            }
        }
    }
    cout << "EL ARTICULO MAS VENDIDO DEL MES " << fechactual.getMes() << " FUE: ";
    for(int x=0; x<contarArticulos; x++)
    {
        RegArt=ArchArt.leerRegistroArticulo(x);
        if (ArtMasvendido==RegArt.getCodigoArticulo() || vecrepetido[x] == RegArt.getCodigoArticulo())
        {
            cout <<" "<<  RegArt.getNombreArticulo() <<" |" << cantamax <<"|.  " ;
        }
    }
}

   void ArticuloMenosVendidoDia() {
    ArchivoDetalleFactura archidetallefac;
    DetalleFactura regdetallefac;
    int contRegdetallefac = archidetallefac.contarRegistrosDetalleFactura();
    Fecha fechactual;

    ArchivoArticulo ArchArt("Articulos.dat");
    Articulo RegArt;

    ArchivoFactura archifac;
    Factura regfac;
    int contReg = archifac.contarRegistrosFactura();

    int contarArticulos = ArchArt.contarRegistrosArticulo();
    int ArtMenosvendido = 0;
    int cantamin = 0;
    int vecrepetido[contarArticulos];

    bool primerValor = true;


for (int j=0;j<contReg;j++){
    regfac=archifac.leerRegistroFactura(j);
    for (int i = 0; i < contRegdetallefac; i++) {
        regdetallefac = archidetallefac.leerRegistroDetalleFactura(i);

        for (int x = 0; x < contarArticulos; x++) {
            RegArt = ArchArt.leerRegistroArticulo(x);
            if (RegArt.getCodigoArticulo() == regdetallefac.getIDArticulo()&& regfac.getFechaFactura().getDia()==fechactual.getDia()&& regdetallefac.getIDFactura()==regfac.getIdFactura()) {
                if (primerValor || regdetallefac.getCantidad() < cantamin) {
                    cantamin = regdetallefac.getCantidad();
                    ArtMenosvendido = regdetallefac.getIDArticulo();
                    primerValor = false;
                }
                 else if (regdetallefac.getCantidad()==cantamin)
                    {
                        vecrepetido[x] = regdetallefac.getIDArticulo();
                    }
            }
        }
    }
}

    if (!primerValor) {
        cout << "El ARTICULO MENOS VENDIDO DEL DIA " << fechactual.getDia() << " FUE: " ;
        for (int x = 0; x < contarArticulos; x++) {
            RegArt = ArchArt.leerRegistroArticulo(x);
            if (ArtMenosvendido == RegArt.getCodigoArticulo() && cantamin > 0 || vecrepetido[x] == RegArt.getCodigoArticulo()) {
                cout << RegArt.getNombreArticulo() << " | " << cantamin << " | " ;
            }
        }
    }
    else {
        cout << "No hay datos de ventas." << endl;
    }

}

