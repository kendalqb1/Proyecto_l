//
// Created by Kendal Q on 21/9/2020.
//

#include "Fecha.h"
//constructor de la clase Fecha.
Fecha::Fecha(int dia, int mes, int ano)
{
    this->dia=dia;
    this->mes=mes;
    this->ano=ano;
}

//Metodo para obtener el dia almacenado en el objeto Fecha.
int Fecha::getDia()
{
    return this->dia;
}

//Metodo para obtener el mes almacenado en el objeto Fecha.
int Fecha::getMes()
{
    return this->mes;
}

//Metodo para obtener el año almacenado en el objeto Fecha.
int Fecha::getAno()
{
    return this->ano;
}