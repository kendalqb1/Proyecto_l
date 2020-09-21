//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_PRODUCTO_H
#define PROYECTO_L_PRODUCTO_H
#include <iostream>
#include <string>
using namespace std;

//Clase Producto diseñada para abstraer las generalidades de los productos que se vana a ingresar en la maquina expendedora.
class Producto {
private:
    string nombre;
    int cantidad;
    float precio;
public:
    Producto();
    Producto(string nombre,float precio,int cantidad);
    ~Producto();
    string getNombre();
    virtual float getPrecio();
    int getCantidad();
    void setNombre(string nombre);
    void setPrecio(float precio);
    void setCantidad(int cantidad);
    virtual string toString();

};


#endif //PROYECTO_L_PRODUCTO_H
