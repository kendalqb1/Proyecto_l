//
// Created by Kendal Q on 21/9/2020.
//

#include "MenuPrincipal.h"
//Constructor de la clase MenuPrincipal
MenuPrincipal::MenuPrincipal()
{

}

//Metodo desarrollado para mostrar las opciones y funcionalidades del objeto MenuPrincipal.
void MenuPrincipal::menuPrincipal()
{
    cout<<"------ Bienvenido al menu principal de la maquina expendedora! ------\n"<<endl;
    cout<<"-> Desea inicializar la maquina con dinero dentro?"<<endl;
    cout<<"1. Si"<<endl;
    cout<<"2. No\n"<<endl;
    int seleccion=0;
    int dinero=0;
    Maquina* maquina;
    while(seleccion!=2)
    {
        cout << "Por favor, seleccione una de las opciones anteriores:";
        cin >> seleccion;
        if(seleccion==1)
        {
            cout<<"\nCon cuanto dinero quiere inicializar la maquina?: ";
            cin>>dinero;
            break;
        }
    }
    string nombre="";
    int identificador=0;
    cout<<"\nIngrese un nombre para la maquina: ";
    cin>>nombre;
    cout<<"\nIngrese un identifiacdor para la maquina: ";
    cin>>identificador;
    maquina= new Maquina(identificador,nombre,dinero);

    //variable booleana que permite definir manualmente si se quiere inicializar la maquina con algunos productos predefinidos.
    bool predefinido= true;
    if(predefinido)
    {
        ProductoNoPerecedero* a= new ProductoNoPerecedero(50,"Gomitas", 200, 10);
        ProductoPerecedero* b= new ProductoPerecedero(Fecha(24,2,2020),"Leche",1000,20);
        ProductoNoPerecedero* c= new ProductoNoPerecedero(12.5,"Miel",800,6);
        ProductoNoPerecedero* d= new ProductoNoPerecedero(40,"Aceite_de_cocina", 1500, 15);
        ProductoPerecedero* e= new ProductoPerecedero(Fecha(24,2,2020),"Natilla",1200,15);
        ProductoNoPerecedero* f= new  ProductoNoPerecedero(0,"Naranjas",200,6);
        maquina->insertar(a);
        maquina->insertar(b);
        maquina->insertar(c);
        maquina->insertar(d);
        maquina->insertar(e);
        maquina->insertar(f);
    }

    this->admMenu=MenuAdministrador(maquina);
    this->cbrMenu=MenuCobro(maquina);

    cout<<"\n\nMaquina inicializada correctamente!\n"<<endl;
    cout<<maquina->toString()<<endl;

    bool corriendo=true;
    while(corriendo)
    {
        cout<<"\n\nPor favor seleccione una de las siguientes opciones: "
              "\n1-> Menu de administrador"
              "\n2-> Menu de Compra"
              "\n3-> Salir"<<endl;
        cin>>seleccion;
        if(seleccion==1)
        {
            menuAdministrador();
        }
        else if(seleccion==2)
        {
            menuCobro();
        }
        else if(seleccion==3)
        {
            cout<<"Gracias por utilizar la maquina expendedora! "<<endl;
            break;
        }

    }

}

//Metodo desarrollado para invocar el metodo mostrar() del objeto MenuAdministrador del objeto MenuPrincipal.
void MenuPrincipal::menuAdministrador()
{
    this->admMenu.mostrar();
}

//Metodo desarrollado para invocar el metodo mostrar() del objeto MenuCobro del objeto MenuPrincipal.
void MenuPrincipal::menuCobro()
{
    this->cbrMenu.mostrar();
}
