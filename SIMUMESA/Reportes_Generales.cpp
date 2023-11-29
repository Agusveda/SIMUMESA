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






///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------

///---------------------------------------RECAUDACION---------------------------------------------

///---------------------------------------RECAUDACION---------------------------------------------

///---------------------------------------RECAUDACION---------------------------------------------

///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------





float RecaudacionDelDia()
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



float RecaudacionDelMes(int mes)
{

    if (mes <= 12 && mes >=1 )
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
        if(regfac.getFechaFactura().getMes() == mes && regfac.getCantidad()>0)
        {
            bandera =true;
            contImportemes += regfac.getCantidad();

        }
    }
    if(bandera)
    {

        cout << "RECAUDACION DEL MES " << mes << " FUE : $" << contImportemes << endl;
    }

}
    else {

        cout << " mes invalido ";

    }
}

float RecaudacionDelAnio(int anio)
{

    Fecha fechactual;

    if (anio <= fechactual.getAnio() && anio >=1900)
    {

    ArchivoFactura archifac;
    Factura regfac;
    int contReg = archifac.contarRegistrosFactura();
    float contImportemes = 0;
    bool bandera = false;
    for(int i = 0 ; i < contReg ; i++)
    {
        regfac = archifac.leerRegistroFactura(i);
        if(regfac.getFechaFactura().getAnio() == anio && regfac.getCantidad()>0)
        {
            bandera =true;
            contImportemes += regfac.getCantidad();

        }
    }
    if(bandera)
    {

        cout << "RECAUDACION DEL ANIO " << anio << " FUE : $" << contImportemes << endl;
    }

}
    else {

        cout << " anio invalido ";

    }
}

///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------

///---------------------------------------ART + VENDIDO-------------------------------------------

///---------------------------------------ART + VENDIDO-------------------------------------------

///---------------------------------------ART + VENDIDO-------------------------------------------

///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------

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


void ArticuloMasVendidoMes(int mes)
{
    if (mes <= 12 && mes >=1 )
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
                if(RegArt.getCodigoArticulo()==regdetallefac.getIDArticulo()&& regfac.getFechaFactura().getMes()==mes&& regdetallefac.getIDFactura()==regfac.getIdFactura())
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
    cout << "EL ARTICULO MAS VENDIDO DEL MES " << mes << " FUE: ";
    for(int x=0; x<contarArticulos; x++)
    {
        RegArt=ArchArt.leerRegistroArticulo(x);
        if (ArtMasvendido==RegArt.getCodigoArticulo() || vecrepetido[x] == RegArt.getCodigoArticulo())
        {
            cout <<" "<<  RegArt.getNombreArticulo() <<" |" << cantamax <<"|.  " ;
        }
    }
   }
   else {
    cout << " MES INVALIDO ";
   }
}


void ArticuloMasVendidoAnio(int anio  )
{
    Fecha fechactual;

    if (anio<=  fechactual.getAnio() && anio>=1900 )
    {

    ArchivoDetalleFactura archidetallefac;
    DetalleFactura regdetallefac;
    int contRegdetallefac = archidetallefac.contarRegistrosDetalleFactura();


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
                if(RegArt.getCodigoArticulo()==regdetallefac.getIDArticulo()&& regfac.getFechaFactura().getAnio()==anio&& regdetallefac.getIDFactura()==regfac.getIdFactura())
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
    cout << "EL ARTICULO MAS VENDIDO DEL ANIO " << anio << " FUE: ";
    for(int x=0; x<contarArticulos; x++)
    {
        RegArt=ArchArt.leerRegistroArticulo(x);
        if (ArtMasvendido==RegArt.getCodigoArticulo() || vecrepetido[x] == RegArt.getCodigoArticulo())
        {
            cout <<" "<<  RegArt.getNombreArticulo() <<" |" << cantamax <<"|.  " ;
        }
    }
   }
   else {
    cout << " ANIO INVALIDO ";
   }
}

///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------

///---------------------------------------ART - VENDIDO-------------------------------------------

///---------------------------------------ART - VENDIDO-------------------------------------------

///---------------------------------------ART - VENDIDO-------------------------------------------

///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------

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

void ArticuloMenosVendidoMes(int mes)
{
    if (mes<=12 && mes>=1 )
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

        int contarArticulos = ArchArt.contarRegistrosArticulo();
        int ArtMenosvendido = 0;
        int cantamin = 0;
        int vecrepetido[contarArticulos];

        bool primerValor = true;


        for (int j=0; j<contReg; j++)
        {
            regfac=archifac.leerRegistroFactura(j);
            for (int i = 0; i < contRegdetallefac; i++)
            {
                regdetallefac = archidetallefac.leerRegistroDetalleFactura(i);

                for (int x = 0; x < contarArticulos; x++)
                {


                    RegArt = ArchArt.leerRegistroArticulo(x);
                    if (RegArt.getCodigoArticulo() == regdetallefac.getIDArticulo()&& regfac.getFechaFactura().getMes()== mes && regdetallefac.getIDFactura()==regfac.getIdFactura() && regfac.getCantidad()>0)
                    {
                        if (primerValor || regdetallefac.getCantidad() < cantamin)
                        {
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

        if (!primerValor)
        {
                for (int i = 0 ;  i< contarArticulos; i++)
            {

                RegArt = ArchArt.leerRegistroArticulo(i);


                for(int x=0 ; x<contRegdetallefac ; x++)
                {
                regdetallefac = archidetallefac.leerRegistroDetalleFactura(x);

                    if(regdetallefac.getIDArticulo() == RegArt.getCodigoArticulo() && regdetallefac.getCantidad() > cantamin)
                    {
                        vecrepetido[i]=0;

                    }
                }

            }
            cout << "El ARTICULO MENOS VENDIDO DEL MES " << mes << " FUE: " ;


            for (int x = 0; x < contarArticulos; x++)
            {
                RegArt = ArchArt.leerRegistroArticulo(x);
                if (ArtMenosvendido == RegArt.getCodigoArticulo() && cantamin > 0 || vecrepetido[x] == RegArt.getCodigoArticulo())
                {
                    cout << RegArt.getNombreArticulo() << " | " << cantamin << " | " ;
                }
            }


        }
        else
        {
            cout << "No hay datos de ventas." << endl;
        }
    }
    else
    {
        cout<<" MES INVALIDO " <<endl;
    }

}

void ArticuloMenosVendidoAnio(int anio)
{
    Fecha fechactual;
    if (anio<= fechactual.getAnio() && anio>=1900 )
    {
        ArchivoDetalleFactura archidetallefac;
        DetalleFactura regdetallefac;
        int contRegdetallefac = archidetallefac.contarRegistrosDetalleFactura();

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


        for (int j=0; j<contReg; j++)
        {
            regfac=archifac.leerRegistroFactura(j);
            for (int i = 0; i < contRegdetallefac; i++)
            {
                regdetallefac = archidetallefac.leerRegistroDetalleFactura(i);

                for (int x = 0; x < contarArticulos; x++)
                {
                    RegArt = ArchArt.leerRegistroArticulo(x);
                    if (RegArt.getCodigoArticulo() == regdetallefac.getIDArticulo()&& regfac.getFechaFactura().getAnio()==anio && regdetallefac.getIDFactura()==regfac.getIdFactura()&&regfac.getCantidad()>0)
                    {
                        if (primerValor || regdetallefac.getCantidad() < cantamin)
                        {
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

        if (!primerValor)
        {
                for (int i = 0 ;  i< contarArticulos; i++)
            {

                RegArt = ArchArt.leerRegistroArticulo(i);


                for(int x=0 ; x<contRegdetallefac ; x++)
                {
                regdetallefac = archidetallefac.leerRegistroDetalleFactura(x);

                    if(regdetallefac.getIDArticulo() == RegArt.getCodigoArticulo() && regdetallefac.getCantidad() > cantamin)
                    {
                        vecrepetido[i]=0;

                    }
                }

            }
            cout << "El ARTICULO MENOS VENDIDO DEL ANIO " << anio << " FUE: " ;
            for (int x = 0; x < contarArticulos; x++)
            {
                RegArt = ArchArt.leerRegistroArticulo(x);
                if (ArtMenosvendido == RegArt.getCodigoArticulo() && cantamin > 0 || vecrepetido[x] == RegArt.getCodigoArticulo())
                {
                    cout << RegArt.getNombreArticulo() << " | " << cantamin << " | " ;
                }
            }
        }
        else
        {
            cout << "No hay datos de ventas." << endl;
        }
    }
    else
    {
        cout<<" ANIO INVALIDO " <<endl;
    }

}
