//
// Created by Kendal Q on 21/9/2020.
//

#include "Nodo.h"
//Constructor standard del objeto Nodo.
Nodo::Nodo()
{
    this->next= nullptr;
}

//Constructos especifico del objeto Nodo.
Nodo::Nodo(Producto* p)
{
    this->next= nullptr;
    this->valor=p;
}

//Metodo desarrollado para obtener el objeto Producto almacenado dentro del objeto Nodo.
Producto* Nodo::getProducto()
{
    return this->valor;
}

//Metodo desarrollado para obtener el puntero al siguiente objeto Nodo dentro de un objeto Lista.
Nodo *Nodo::getNext() {
    return this->next;
}

//Metodo desarrollado para definir el puntero al siguiente objeto Nodo dentro de un objeto Lista.
void Nodo::setNext(Nodo *n)
{
    this->next=n;
}

//Metodo para definir el objeto Producto que irá almacenado dentro del objeto Nodo.
void Nodo::setValue(Producto* p)
{
    this->valor=p;
}