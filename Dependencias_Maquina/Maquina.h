//
// Created by Kendal Q on 21/9/2020.
//

#ifndef PROYECTO_L_MAQUINA_H
#define PROYECTO_L_MAQUINA_H
#include "iostream"
#include "../Monedero/MonederoElectronico.h"
#include "IMaquinaAdministradora.h"
#include "IMaquinaVendedora.h"
#include "../Auxiliares/Lista.h"
using namespace std;

//Clase Maquina que representa la maquina expendedora como tal.
class Maquina: public IMaquinaAdministradora,IMaquinaVendedora {
private:
    int identificador;
    string nombre;
    MonederoElectronico monedero;
    Lista coleccionDeProductos;

public:
    Maquina(int id, string nombre);
    Maquina(int id, string nombre,int dinero);
    int getIdentificador();
    string getNombre();
    void setNombre(string nombre);
    string toString();
    void insertar(Producto* p);
    void agregarProvisiones(string idProducto,int cantidad);
    void disminuirProvisiones(string idProducto,int cantidad);
    void borrar(string id);
    Producto* consultar(string id);
    Producto* consultar(int id);
    void ingresarDinero(int cantidad);
    void retirarDinero(int cantidad);
    string realizarCompra(string id,int cantidad,int montoPago);
    void mostrarInventario();
};


#endif //PROYECTO_L_MAQUINA_H
