#include<cstring>
#include<cstdlib>
#include <iostream>
#include "Validaciones.h"

using namespace std;

void validarChar(char& c){
    while (cin.fail()){
        cin.clear();
        cin.ignore();
        cin>>c;
    }
    }
void ValidarInt(int& b){
    while (cin.fail()){
        cin.clear();
        cin.ignore();
        cin>>b;
    }
    }
