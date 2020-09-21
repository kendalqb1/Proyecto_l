//
// Created by Kendal Q on 21/9/2020.
//

#include "MonederoElectronico.h"
//Constructor standard de la clase MonederoElectronico.
MonederoElectronico::MonederoElectronico()
{
    this->dinero=0;
}

//Constructor especifico de la clase MonederoElectronico.
MonederoElectronico::MonederoElectronico(int dinero)
{
    this->dinero=dinero;
}

//Destructor de la clase MonederoElectronico
MonederoElectronico::~MonederoElectronico() {}


//Metodo diseñado para calcular el vuelto que debe ser entregado al cliente, ademas de si es posile entregar vuelto para la denominacion entregada.
string MonederoElectronico::desgloceVuelto(int vuelto)
{
    if(vuelto>this->dinero)
    {
        cout<<"ERROR: No hay suficiente dinero en la maquina para dar vuelto!"<<endl;
        return "-1";
    }
    int out=vuelto;
    int billetes[4]={2000,1000,500,100};
    int salida[4]={0,0,0,0};

    while (vuelto!=0)
    {
        if(vuelto<100)
        {
            cout<<"No se puede dar vuelto para la denominacion ingresada! "<<endl;
            return "-1";
        }
        for(int ind=0;ind<4;ind++)
        {
            if(billetes[ind]<=vuelto)
            {
                salida[ind]=salida[ind]+1;
                vuelto=vuelto-billetes[ind];
                break;
            }
        }
    }
    string entregable="Su vuelto: ";
    for(int ind=0;ind<4;ind++)
    {
        if(salida[ind]!=0)
        {
            entregable += "\n\t" + to_string(salida[ind]) + "x " + to_string(billetes[ind]);
        }
    }
    cout<<"\nGracias por su compra!\n"<<endl;
    this->dinero-=out;
    return entregable;
}

//Metodo para definir el atributo dinero del objeto MonederoElectronico.
void MonederoElectronico::setDinero(int dinero)
{
    this->dinero=dinero;
    if(this->dinero<0)
    {
        this->dinero=0;
    }
}

//Metodo para obtener el atributo dinero del objeto MonederoElectronico.
float MonederoElectronico::getDinero()
{
    return this->dinero;
}

//Metodo para imprimir en consola todos los atributos del objeto MonederoElectronico de manera ordenada
string MonederoElectronico::toString()
{
    return "Monedero:\n\tDinero-> "+to_string(this->dinero);
}
