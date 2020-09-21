//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_LISTA_H
#define PROYECTO_L_LISTA_H
#include "Nodo.h"
#include "iostream"
using namespace std;

//Clase Lista que implementa una lista simple
class Lista {
private:
    Nodo* head;
    int len;

public:
    Lista();
    int getLen();
    void addLast(Nodo* n);
    void del(string id);
    void modificarProvisiones(string id,int cantidad);
    Producto* consultar(string id);
    Producto* consultar(int id);
    void imprimirInventario();

};


#endif //PROYECTO_L_LISTA_H
