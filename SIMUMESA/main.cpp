#include <iostream>
#include <cstdlib>
#include <cstdio>


using namespace std;
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


int main()
{
    //Fecha fechaa;
  ArchivoFactura arc;
  arc.MostrarRegistrosFactura();
    int dia=12,mes=11,anio=2023;

  Fecha f(dia,mes,anio);


  arc.GrabarRegistroFactura(7,f,4500);
  /*

    ///cout << fechaa.toString();
  menu_general();
  ArchivoMesa reg;
  reg.MostrarRegistrosDeMesa();
    ArchivoDetalleFactura rej;
    rej.MostrarRegistrosDetalleFactura();
  */

    return 0;
}
