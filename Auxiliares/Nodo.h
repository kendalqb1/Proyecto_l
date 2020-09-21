//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_NODO_H
#define PROYECTO_L_NODO_H
#include "../Productos/Producto.h"
//Clase Nodo dieñada para ser utilizada por la estructura de datos desarrollada por el objeto Lista.
class Nodo {
private:
    Producto* valor;
    Nodo* next;

public:
    Nodo();
    Nodo(Producto* p);
    Producto* getProducto();
    Nodo* getNext();
    void setNext(Nodo* n);
    void setValue(Producto* p);

};


#endif //PROYECTO_L_NODO_H
