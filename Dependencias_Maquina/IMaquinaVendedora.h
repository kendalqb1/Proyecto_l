//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_IMAQUINAVENDEDORA_H
#define PROYECTO_L_IMAQUINAVENDEDORA_H
#include"iostream"
using namespace std;

//Clase IMaquinaVendedora desarrollada para implementar los metodos de la interfaz de la parte de cobro de la maquina expendedora.
class IMaquinaVendedora {
public:
    virtual string getNombre()=0;
    virtual string realizarCompra(string id, int cantidad, int montoPago)=0;
    virtual string toString()=0;
};


#endif //PROYECTO_L_IMAQUINAVENDEDORA_H
