//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_MENUPRINCIPAL_H
#define PROYECTO_L_MENUPRINCIPAL_H
#include "iostream"
#include "MenuAdministrador.h"
#include "MenuCobro.h"
#include "MenuPrincipal.h"
#include "../Dependencias_Maquina/Maquina.h"
#include "../Productos/ProductoNoPerecedero.h"
#include "../Productos/ProductoPerecedero.h"
using namespace std;

//Clase MenuPrincipal desarrollada con el fin de unificar la funcionalidad de los objetos MenuAdministrador y MenuCobro de la maquina expendedora.
class MenuPrincipal {
private:
    MenuAdministrador admMenu = MenuAdministrador(nullptr);
    MenuCobro cbrMenu=MenuCobro(nullptr);

public:
    MenuPrincipal();
    void menuPrincipal();
    void menuAdministrador();
    void menuCobro();
};


#endif //PROYECTO_L_MENUPRINCIPAL_H
