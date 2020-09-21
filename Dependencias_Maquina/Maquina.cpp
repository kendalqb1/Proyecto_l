//
// Created by Kendal Q on 21/9/2020.
//

#include "Maquina.h"
//Constructor de la clase Maquina que permite instanciar un objeto Maquina sin definir una cantidad de dinero inicial.
Maquina::Maquina(int id, string nombre)
{
    this->identificador=id;
    this->nombre=nombre;
    this->coleccionDeProductos=Lista();
    this->monedero=MonederoElectronico();
}

//Constructor de la clase Maquina que permite instanciar un objeto Maquina con una cantidad de dinero inicial definida.
Maquina::Maquina(int id, string nombre, int dinero)
{
    this->identificador=id;
    this->nombre=nombre;
    this->coleccionDeProductos=Lista();
    this->monedero=MonederoElectronico(dinero);
}

//Metodo desarrollado para obtener el atributo identificador del objeto Maquina.
int Maquina::getIdentificador()
{
    return this->identificador;
}

//Metodo desarrollado para obtener el atributo nombre del objeto Maquina.
string Maquina::getNombre()
{
    return this->nombre;
}

//Metodo desarrollado para definir el atributo nombre del objeto Maquina.
void Maquina::setNombre(string nombre)
{
    this->nombre=nombre;
}

//Metodo para imprimir en consola todos los atributos del objeto Maquina de manera ordenada.
string Maquina::toString()
{
    return "Maquina: \n\tIdentificador-> "+to_string(this->identificador)+"\n\tNombre-> "+this->nombre+"\n\n\t"+this->monedero.toString();
}

//Metodo para agregar un nuevo producto al objeto Lista del objeto Maquina.
void Maquina::insertar(Producto* p)
{
    this->coleccionDeProductos.addLast(new Nodo(p));
}


//Metodo desarrollado para agregar provisiones a un objeto Producto en especifico dentro del objeto Lista dentro del objeto Maquina.
void Maquina::agregarProvisiones(string idProducto, int cantidad)
{
    this->coleccionDeProductos.modificarProvisiones(idProducto,cantidad);
}

//Metodo desarrollado para disminuir provisiones a un objeto Producto en especifico dentro del objeto Lista dentro del objeto Maquina.
void Maquina::disminuirProvisiones(string idProducto, int cantidad)
{
    this->coleccionDeProductos.modificarProvisiones(idProducto,-cantidad);
}

//Metodo para borrar un objeto Producto en especifico dentro del objeto Lista dentro del objeto Maquina
void Maquina::borrar(string id)
{
    this->coleccionDeProductos.del(id);
}

//Metodo para obtener un objeto Producto en especifico del objeto Lista dentro del objeto Maquina por su nombre .
Producto* Maquina::consultar(string id)
{
    return this->coleccionDeProductos.consultar(id);
}

//Metodo para obtener un objeto Producto en especifico del objeto Lista dentro del objeto Maquina por su posicion dentro del objeto Lista.
Producto* Maquina::consultar(int id)
{
    return this->coleccionDeProductos.consultar(id);
}

//Metodo para aumentar el atributo dinero dentro del objeto MonederoElectronico dentro del objeto Maquina.
void Maquina::ingresarDinero(int cantidad)
{
    this->monedero.setDinero(this->monedero.getDinero()+cantidad);
}


//Metodo para disminuirr el atributo dinero dentro del objeto MonederoElectronico dentro del objeto Maquina.
void Maquina::retirarDinero(int cantidad)
{
    this->monedero.setDinero(this->monedero.getDinero()-cantidad);
}


//Metodo para realizar una comprar utilizando el objeto Maquina.
string Maquina::realizarCompra(string id, int cantidad, int montoPago)
{
    Producto* p=this->coleccionDeProductos.consultar(id);
    if(p->getCantidad()-cantidad<0)
    {
        return "No hay suficientes unidades de este producto para completar la compra! ";
    }
    if(montoPago-p->getPrecio()*cantidad<0)
    {
        return "No se ingreso una cantidad suficiente de dinero!"
               "\n Hacen falta "+to_string(p->getPrecio()*cantidad-montoPago)+" colones";
    }
    string resultado=this->monedero.desgloceVuelto(montoPago-int(p->getPrecio())*cantidad);
    if(resultado!="-1")
    {
        this->coleccionDeProductos.modificarProvisiones(id,-cantidad);
        this->monedero.setDinero(this->monedero.getDinero()+montoPago);
        return resultado;
    }
    return"";

}

//Metodo para invocar el metodo imprimirInventario() del objeto Lista alamacenado en el objeto Maquina.
void Maquina::mostrarInventario()
{
    this->coleccionDeProductos.imprimirInventario();

}

