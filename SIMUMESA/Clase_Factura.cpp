#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
#include "Clase_Factura.h"
#include "fecha.h"


        //SET

        void Factura::setIdFactura(int idFactura){_idFactura = idFactura;}
        void Factura::setFechaFactura(Fecha fechafactura){_fechaFactura=fechafactura;}

        //GET

        int Factura::getIdFactura(){return _idFactura;}
        Fecha Factura::getFechaFactura(){return _fechaFactura;}

        //CARGAR/MOSTRAR
        void Factura::CargarFactura()
        {
            cout << "Ingresar idfactura:";
            cin >> _idFactura;

        };
        void Factura::mostrarFactura()
        {
            cout << "idfactura:" << _idFactura;
            cout << _fechaFactura.toString();

        };





  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///                                              CLASE ARCHIVO FACTURA                                                 ///

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





