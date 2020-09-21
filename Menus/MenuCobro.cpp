//
// Created by Kendal Q on 21/9/2020.
//

#include "MenuCobro.h"
//Constructor de la clase MenuCobro
MenuCobro::MenuCobro(Maquina *m)
{
    this->maquinaA=m;
}

//Metodo para mostar en consola las opciones y funcionalidades del objeto MenuCobro.
void MenuCobro::mostrar()
{
    cout<<"------ Bienvenido al menu de compra de la maquina expendedora! ------\n"<<endl;
    bool corriendo=true;
    while(corriendo)
    {
        int seleccion = 0;
        cout << "\n\nPor favor seleccione una de las siguientes opciones: "
                "\n1-> Mostrar productos"
                "\n2-> Comprar producto"
                "\n3-> Volver al menu principal\n" << endl;
        cin >> seleccion;
        if(seleccion==1)
        {
            this->maquinaA->mostrarInventario();
        }
        else if(seleccion==2)
        {
            this->maquinaA->mostrarInventario();
            cout<<"Ingrese el numero del producto que desea comprar:";
            cin>>seleccion;
            Producto* p=this->maquinaA->consultar(seleccion);
            if(p!= nullptr)
            {
                cout<<p->toString()<<endl;
                bool comprar=false;
                seleccion=0;
                while(true)
                {
                    cout<<"\n Desea comprar el producto?:"
                          "\n 1-> Si"
                          "\n 2-> No\n";
                    cin >> seleccion;
                    if(seleccion==1)
                    {
                        comprar=true;
                        break;
                    }
                    else if(seleccion==2)
                    {
                        break;
                    }
                }
                if(comprar)
                {
                    int dinero=0;
                    int cantidad=0;
                    cout<<"\nCuantas unidades desea comprar?:";
                    cin>>cantidad;
                    cout<<"\nCon cuanto desea cancelar?: ";
                    cin>>dinero;
                    comprar=false;
                    seleccion=0;
                    while(true)
                    {
                        cout <<"\n Desea continuar con la compra?:"
                               "\n 1-> Si"
                               "\n 2-> No\n";
                        cin >> seleccion;
                        if(seleccion==1)
                        {
                            comprar=true;
                            break;
                        }
                        else if(seleccion==2)
                        {
                            break;
                        }
                    }
                    if(comprar)
                    {
                        cout<<this->maquinaA->realizarCompra(p->getNombre(),cantidad,dinero)<<endl;
                    }
                    else
                    {
                        cout<<"Transaccion cancelada"<<endl;
                    }

                }
                else
                {
                    cout<<"Transaccion cancelada"<<endl;
                }
            }
        }
        else if(seleccion==3)
        {
            cout<<"\nVolviendo al menu principal...\n\n"<<endl;
            break;
        }
    }
}
