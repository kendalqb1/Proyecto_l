//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_FECHA_H
#define PROYECTO_L_FECHA_H

//Clase auxiliar diseñada para abstraer el concepto de fecha
class Fecha {
private:
    int dia;
    int mes;
    int ano;

public:
    Fecha(int dia, int mes, int ano);
    int getDia();
    int getMes();
    int getAno();
};


#endif //PROYECTO_L_FECHA_H
