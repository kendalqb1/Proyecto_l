//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_MENUADMINISTRADOR_H
#define PROYECTO_L_MENUADMINISTRADOR_H
#include "../Dependencias_Maquina/Maquina.h"
#include "../Productos/ProductoPerecedero.h"
#include "../Productos/ProductoNoPerecedero.h"

//Clase MenuAdministrador desarrollado con el fin de implementar la funcionalidad del menu para administrar la maquina expendedora.
class MenuAdministrador {
private:
    Maquina* maquinaA;
    string contrasena="0000";

public:
    MenuAdministrador(Maquina* m);
    void mostrar();
};


#endif //PROYECTO_L_MENUADMINISTRADOR_H
