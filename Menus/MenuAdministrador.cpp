//
// Created by Kendal Q on 21/9/2020.
//

#include "MenuAdministrador.h"
//Constructor de la clase MenuAdministrador
MenuAdministrador::MenuAdministrador(Maquina* m)
{
    this->maquinaA=m;
}

//Metodo para mostar en consola las opciones y funcionalidades del objeto MenuAdministrador.
void MenuAdministrador::mostrar()
{
    cout<<"------ Bienvenido al menu de administrador de la maquina expendedora! ------\n"<<endl;
    string contrasena="";
    while(contrasena!=this->contrasena)
    {
        cout <<"\nPor favor, ingrese la contrasena de acceso:";
        cin>>contrasena;
    }
    bool corriendo=true;
    while(corriendo)
    {
        int seleccion=0;
        cout<<"\n\nPor favor seleccione una de las siguientes opciones: "
              "\n1-> Mostrar informacion de la maquina"
              "\n2-> Cambiar el nombre de la maquina"
              "\n3-> Ingresar un nuevo producto"
              "\n4-> Agregar povisiones a un producto"
              "\n5-> Retirar provisiones de un producto"
              "\n6-> Borrar un producto de la maquina"
              "\n7-> Ver informacion sobre un producto"
              "\n8-> Ver el inventario de la maquina"
              "\n9-> Ingresar dinero"
              "\n10-> Retirar dinero"
              "\n11-> Cambiar la contrasena de acceso"
              "\n12-> Volver al menu principal\n"
              "Selecione una opcion: ";
        cin>>seleccion;
        if(seleccion==1)
        {
            cout<<this->maquinaA->toString()<<endl;
        }
        else if(seleccion==2)
        {
            string nombre="";
            cout<<"\nPor favor ingrese un nuevo nombre para la maquina:";
            cin>>nombre;
            this->maquinaA->setNombre(nombre);
            cout<<"\nNombre modificado correctamente!\n\n"<<endl;
        }
        else if(seleccion==3)
        {
            string nombre="";
            float precio=0;
            int cantidad=0;
            int pSeleccion=0;
            bool perecedero=false;
            while(pSeleccion!=2)
            {
                cout<<"Es el producto perecedero?: "
                      "\n1-> Si"
                      "\n2-> No"<<endl;
                cin>>pSeleccion;
                if(pSeleccion==1)
                {
                    perecedero=true;
                    break;
                }
            }
            cout<<"\nIngrese el nombre del producto: ";
            cin>>nombre;
            cout<<"\nIngrese un precio para el producto:";
            cin>>precio;
            cout<<"\nIngrese la cantidad de producto a insertar en la maquina:";
            cin>>cantidad;
            if(perecedero)
            {
                int dia;
                int mes;
                int ano;
                cout<<"\nIngrese el numero de dia en el que vence el producto: ";
                cin>>dia;
                cout<<"\nIngrese el numero de mes en el que vence el producto: ";
                cin>>mes;
                cout<<"\nIngrese el numero de ano en el que vence el producto: ";
                cin>>ano;
                ProductoPerecedero* p = new ProductoPerecedero(Fecha(dia,mes,ano),nombre,precio,cantidad);
                this->maquinaA->insertar(p);
            }
            else
            {
                int descuento=0;
                cout<<"\nIngrese el porcentaje de descuento que se le aplica a este producto:";
                cin>>descuento;
                ProductoNoPerecedero* p= new ProductoNoPerecedero(descuento,nombre,precio,cantidad);
                this->maquinaA->insertar(p);
            }
        }
        else if(seleccion==4)
        {
            string nombre="";
            int cantidad=0;
            this->maquinaA->mostrarInventario();
            cout<<"\nPor favor, ingrese el nombre del producto al que quiere agregar provisiones:";
            cin>>nombre;
            cout<<"\nIngrese el numero de provisiones a agregar:";
            cin>>cantidad;
            this->maquinaA->agregarProvisiones(nombre,cantidad);

        }
        else if(seleccion==5)
        {
            string nombre="";
            int cantidad=0;
            this->maquinaA->mostrarInventario();
            cout<<"\nPor favor, ingrese el nombre del producto al que quiere retirar provisiones:";
            cin>>nombre;
            cout<<"\nIngrese el numero de provisiones a retirar:";
            cin>>cantidad;
            this->maquinaA->agregarProvisiones(nombre,-cantidad);
        }
        else if(seleccion==6)
        {
            string nombre="";
            this->maquinaA->mostrarInventario();
            cout<<"\nPor favor, ingrese el nombre del producto que quiere eliminar de la maquina:";
            cin>>nombre;
            this->maquinaA->borrar(nombre);
        }
        else if(seleccion==7)
        {
            string nombre="";
            this->maquinaA->mostrarInventario();
            cout<<"\nPor favor, ingrese el nombre del producto que quiere informacion:";
            cin>>nombre;
            Producto* p=this->maquinaA->consultar(nombre);
            if(p!= nullptr)
            {
                cout << p->toString() << endl;
            }
            else
            {
                cout<<"ERROR: Producto no encontrado!"<<endl;
            }
        }
        else if(seleccion==8)
        {
            this->maquinaA->mostrarInventario();
        }
        else if(seleccion==9)
        {
            int dinero;
            cout<<"Ingrese la cantidad de dinero que se le va a agregar a la maquina:";
            cin>>dinero;
            this->maquinaA->ingresarDinero(dinero);
            cout<<"\nDinero agregado correctamente!"<<endl;
        }
        else if(seleccion==10)
        {
            int dinero;
            cout<<"Ingrese la cantidad de dinero que se va a retirar de la maquina:";
            cin>>dinero;
            this->maquinaA->retirarDinero(dinero);
            cout<<"\nDinero retirado correctamente!"<<endl;
        }
        else if(seleccion==11)
        {
            string contrasenaI="";
            bool correcta=false;
            while(true)
            {
                cout<<"\nIngrese la contrasena de acceso actual(Escriba Salir para volver al menu):";
                cin>>contrasenaI;
                if(contrasenaI=="Salir")
                {
                    break;
                }
                if(contrasenaI==this->contrasena)
                {
                    correcta=true;
                    break;
                }
            }
            if(correcta)
            {
                cout<<"\nIngrese la nueva contrasena:";
                cin>>this->contrasena;
                cout<<"\nContrasena modificada correctamente!"<<endl;
            }

        }
        else if(seleccion==12)
        {
            cout<<"\nVolviendo al menu principal...\n\n"<<endl;
            break;
        }
    }
}