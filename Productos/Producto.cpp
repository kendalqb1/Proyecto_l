//
// Created by Kendal Q on 21/9/2020.
//

#include "Producto.h"
//Constructor standard de la clase Producto.
Producto::Producto()
{
    this->nombre="";
    this->precio=0;
    this->cantidad=0;

}

//Constructor especifico de la clase Producto.
Producto::Producto(string nombre, float precio, int cantidad)
{
    this->nombre=nombre;
    this->precio=precio;
    this->cantidad=cantidad;
}

//Destructor de la clase Producto.
Producto::~Producto(){}

//Metodo para obtener el atributo nombre del objeto Producto
string Producto::getNombre()
{
    return this->nombre;
}

//Metodo para obtener el atributo precio del objeto Producto
float Producto::getPrecio()
{
    return this->precio;
}

//Metodo para obtener el atributo cantidad del objeto Producto
int Producto::getCantidad()
{
    return this->cantidad;
}

//Metodo para definir el atributo nombre del objeto Producto
void Producto::setNombre(string nombre)
{
    this->nombre=nombre;
}

//Metodo para definir el atributo precio del objeto Producto
void Producto::setPrecio(float precio)
{
    this->precio=precio;
}

//Metodo para definir el atributo cantidad del objeto Producto
void Producto::setCantidad(int cantidad)
{
    this->cantidad=cantidad;
}

//Metodo para imprimir en consola todos los atributos del objeto Producto de manera ordenada
string Producto::toString()
{
    return "Producto:"
           "\n\tNombre-> "+this->nombre+
           "\n\tCantidad-> "+to_string(this->cantidad)+
           "\n\tPrecio-> "+to_string(this->precio)+"\n\n";
}
