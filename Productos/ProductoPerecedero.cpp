//
// Created by Kendal Q on 21/9/2020.
//

#include "ProductoPerecedero.h"
//Constructor de la clase ProductoPerecedero
ProductoPerecedero::ProductoPerecedero(Fecha fechaDeVencimiento,string nombre,float precio,int cantidad):Producto(nombre,precio,cantidad)
{
    this->fechaDeVencimiento=fechaDeVencimiento;
}

//Metodo diseñado con el fin de obtener el atributo precio, con su respectivo descuento, del objeto ProductoPerecedero
float ProductoPerecedero::getPrecio()
{
    time_t t= time(0);
    tm* ahora=localtime(&t);
    int dia=ahora->tm_mday;
    int mes=ahora->tm_mon+1;
    int ano=ahora->tm_year+1900;

    int diasMes[12]={31,28,31,30,31,30,31,30,30,31,30,31};
    int diasMesEsp[12]={31,29,31,30,31,30,31,30,30,31,30,31};

    bool bisiestoActual;

    if(ano==this->fechaDeVencimiento.getAno())
    {
        bisiestoActual=ano%4==0;
        if(mes>this->fechaDeVencimiento.getMes())
        {
            return 0;
        }
        else if(mes+1==this->fechaDeVencimiento.getMes())
        {
            if(bisiestoActual)
            {
                if(diasMesEsp[mes-1]-dia+this->fechaDeVencimiento.getDia()<7)
                {
                    return Producto::getPrecio()*0.5;
                }
            }
            else if(diasMes[mes-1]-dia+this->fechaDeVencimiento.getDia()<7)
            {
                return Producto::getPrecio()*0.5;
            }
        }
        else if(mes==this->fechaDeVencimiento.getMes())
        {
            if(dia>this->fechaDeVencimiento.getDia())
            {
                return 0;
            }
            else if(this->fechaDeVencimiento.getDia()-dia<7)
            {
                return Producto::getPrecio()*0.5;
            }
        }
    }
    else if(ano+1==this->fechaDeVencimiento.getAno())
    {
        if(this->fechaDeVencimiento.getMes()==1&&mes==12)
        {
            if(diasMes[mes-1]-dia+this->fechaDeVencimiento.getDia()<7)
            {
                return Producto::getPrecio()*0.5;
            }
        }
    }
    else if (ano>this->fechaDeVencimiento.getAno())
    {
        return 0;
    }
    return Producto::getPrecio();
}
string ProductoPerecedero::toString()
{
    return "Producto:"
           "\n\tNombre-> "+Producto::getNombre()+
           "\n\tCantidad-> "+to_string(Producto::getCantidad())+
           "\n\tPrecio sin descuento-> "+to_string(Producto::getPrecio())+
           "\n\tPrecio con descuento-> "+to_string(this->getPrecio())+"\n\n";
}