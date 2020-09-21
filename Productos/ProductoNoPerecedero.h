//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_PRODUCTONOPERECEDERO_H
#define PROYECTO_L_PRODUCTONOPERECEDERO_H
#include "Producto.h"

//Clase ProductoNoPerecedero diseñada con el fin de abstaer las particuladridades de los productos no perecederos que se van a ingresar en la maquina expendedora.
class ProductoNoPerecedero: public Producto {
private:
    float porcentajeDeDescuento;

public:
    ProductoNoPerecedero(float descuento,string nombre,float precio,int cantidad);
    float getPrecio();
    string toString();
};


#endif //PROYECTO_L_PRODUCTONOPERECEDERO_H
