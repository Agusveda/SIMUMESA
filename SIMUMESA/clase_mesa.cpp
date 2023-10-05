#include<cstring>
#include<cstdlib>
#include <iostream>
#include "clase_mesa.h"
using namespace std;

void Mesa::setNumeroDeMesa (int num)
    {
        if (_numero>0&&_numero<=5)
        {
            _numero=num;
        }
    }
int mesa::getNumeroDeMesa ();
bool Mesa::getEstado();
