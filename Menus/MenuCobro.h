//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_MENUCOBRO_H
#define PROYECTO_L_MENUCOBRO_H
#include "../Dependencias_Maquina/Maquina.h"

//Clase MenuCobro desarrollado con el fin de implementar la funcionalidad del menu para realizar ventas de la maquina expendedora.
class MenuCobro {
private:
    Maquina* maquinaA;

public:
    MenuCobro(Maquina* m);
    void mostrar();
};


#endif //PROYECTO_L_MENUCOBRO_H
