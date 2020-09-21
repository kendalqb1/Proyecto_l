//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_IMAQUINAADMINISTRADORA_H
#define PROYECTO_L_IMAQUINAADMINISTRADORA_H
#include <iostream>
#include "../Productos/Producto.h"

using namespace std;

//Clase IMaquinaAdministradora desarrollada para implementar los metodos de la interfaz de la parte administrativa de la maquina expendedora.
class IMaquinaAdministradora {
public:
    virtual int getIdentificador()=0;
    virtual string getNombre()=0;
    virtual void setNombre(string nombre)=0;
    virtual string toString()=0;
    virtual void insertar(Producto* p)=0;
    virtual void agregarProvisiones(string idProducto,int cantidad)=0;
    virtual void disminuirProvisiones(string idProducto,int cantidad)=0;
    virtual void borrar(string id)=0;
    virtual Producto* consultar(string id)=0;
    virtual void ingresarDinero(int cantidad)=0;
    virtual void retirarDinero(int cantidad)=0;
};


#endif //PROYECTO_L_IMAQUINAADMINISTRADORA_H
