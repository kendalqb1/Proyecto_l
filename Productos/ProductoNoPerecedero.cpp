//
// Created by Kendal Q on 21/9/2020.
//

#include "ProductoNoPerecedero.h"
//Constructor de la clase ProductoNoPerecedero
ProductoNoPerecedero::ProductoNoPerecedero(float descuento, string nombre, float precio, int cantidad):Producto(nombre,precio,cantidad)
{
    this->porcentajeDeDescuento=descuento;
}

//Metodo diseñado para obtener el atributo precio, con su respectivo descuento, del objeto ProductoNoPerecedero.
float ProductoNoPerecedero::getPrecio()
{
    return Producto::getPrecio()*(1-this->porcentajeDeDescuento/100);
}

//Metodo para imprimir en consola todos los atributos del objeto ProductoNoPerecedero de manera ordenada
string ProductoNoPerecedero::toString()
{
    return "Producto:"
           "\n\tNombre-> "+Producto::getNombre()+
           "\n\tCantidad-> "+to_string(Producto::getCantidad())+
           "\n\tPrecio sin descuento-> "+to_string(Producto::getPrecio())+
           "\n\tPrecio con descuento-> "+to_string(this->getPrecio())+"\n\n";
}
