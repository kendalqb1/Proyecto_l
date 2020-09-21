//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_MONEDEROELECTRONICO_H
#define PROYECTO_L_MONEDEROELECTRONICO_H
#include <iostream>
#include <string>
using namespace std;

//Clase MonederoElectronico diseñada para abstraer el monedero que va dentro de la maquina expendedora.
class MonederoElectronico {
private:
    int dinero;

public:
    MonederoElectronico();
    MonederoElectronico(int dinero);
    ~MonederoElectronico();
    string desgloceVuelto(int vuelto);
    void setDinero(int dinero);
    float getDinero();
    string toString();
};


#endif //PROYECTO_L_MONEDEROELECTRONICO_H
