//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_PRODUCTOPERECEDERO_H
#define PROYECTO_L_PRODUCTOPERECEDERO_H
#include <time.h>
#include "../Auxiliares/Fecha.h"
#include "Producto.h"
using namespace std;

//Clase ProductoPerecedero diseñada con el fin de abstaer las particuladridades de los productos perecederos que se van a ingresar en la maquina expendedora.
class ProductoPerecedero: public Producto {
private:
    Fecha fechaDeVencimiento= Fecha(0, 0, 0);

public:
    ProductoPerecedero(Fecha fechaDeVencimiento, string nombre, float precio, int cantidad);
    float getPrecio();
    string toString();
};


#endif //PROYECTO_L_PRODUCTOPERECEDERO_H
