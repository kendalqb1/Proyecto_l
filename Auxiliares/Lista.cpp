//
// Created by Kendal Q on 21/9/2020.
//

#include "Lista.h"
//Constructor de la clase Lista
Lista::Lista()
{
    this->head=nullptr;
    this->len=0;
}
// Metodo diseñado para obtener el atributo de longitud del objeto Lista.
int Lista::getLen()
{
    return this->len;
}

//Metodo para añadir elementos al final del objeto Lista.
void Lista::addLast(Nodo* n)
{
    if(this->head== nullptr)
    {
        this->head=n;
    }
    else
    {
        Nodo* temp=this->head;
        while(temp->getNext()!= nullptr)
        {
            temp=temp->getNext();
        }
        temp->setNext(n);
    }
    len++;
}

//Metodo para eliminar elementos del objeto Lista por nombre.
void Lista::del(string id)
{
    if(this->head->getProducto()->getNombre()==id)
    {
        Nodo* temp=this->head->getNext();
        this->head->setNext(nullptr);
        delete(this->head);
        this->head=temp;
        temp= nullptr;
        delete(temp);
        this->len--;
        cout<<"Producto eliminado correctamente!"<<endl;
    }
    else
    {
        Nodo* temp=this->head;
        if(temp->getNext()!=nullptr)
        {
            while (temp->getNext()->getProducto()->getNombre() != id)
            {
                temp = temp->getNext();
                if(temp->getNext()== nullptr)
                {
                    temp= nullptr;
                    break;
                }
            }
            if(temp!= nullptr)
            {
                Nodo *temp2 = temp->getNext();
                temp->setNext(temp2->getNext());
                temp2->setNext(nullptr);
                temp = nullptr;
                delete (temp2);
                delete (temp);
                this->len--;
                cout<<"Producto eliminado correctamente!"<<endl;
            }
            else
            {
                cout<<"ERROR: Elemento no encontrado!"<<endl;
            }
        }
        else
        {
            cout<<"ERROR: Elemento no encontrado!"<<endl;
        }
    }

}

//Metodo para modificar la cantidad de elementos disponibles de un objeto Producto almacenado dentro del objeto Lista.
void Lista::modificarProvisiones(string id, int cantidad)
{
    Nodo* temp=this->head;
    while(temp!= nullptr)
    {
        if(temp->getProducto()->getNombre()==id)
        {
            if(temp->getProducto()->getCantidad()+cantidad<0)
            {
                temp->getProducto()->setCantidad(0);
            }
            else
            {
                temp->getProducto()->setCantidad(temp->getProducto()->getCantidad() + cantidad);
            }
            break;
        }
        temp=temp->getNext();
    }
    if(temp== nullptr)
    {
        cout<<"ERROR: Producto no encontrado!"<<endl;
    }
    else
    {
        cout<<"Provisiones modificadas correctamente!"<<endl;
    }

}

//Metodo para obtener un producto almacenado dentro del objeto Lista por nombre
Producto* Lista::consultar(string id)
{
    Nodo* temp=this->head;
    while(temp!= nullptr)
    {
        if(temp->getProducto()->getNombre()==id)
        {
            break;
        }
        temp=temp->getNext();
    }
    if(temp==nullptr)
    {
        return nullptr;
    }
    return temp->getProducto();
}

//Metodo para obtener un producto almacenado dentro del objeto Lista por orden dentro del objeto Lista.
Producto* Lista::consultar(int id)
{
    if(id>this->len||id<0)
    {
        cout<<"ERROR: Producto no encontrado!"<<endl;
        return nullptr;
    }
    Nodo* temp=this->head;
    int ind=1;
    while(ind!=id)
    {
        temp=temp->getNext();
        ind++;
    }
    return temp->getProducto();
}

//Metodo diseñado para mostrar de manera ordenada los objetos Producto almacenados en el objeto Lista y sus repsecctivas cantidades y precios.
void Lista::imprimirInventario()
{
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"|          Producto          |          Cantidad          |          Precio          |"<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    int ind=1;
    Nodo* temp=this->head;
    while(temp!= nullptr)
    {
        string productEspacio="";
        for(int indE=0;indE<(40-temp->getProducto()->getNombre().length());indE++)
        {
            productEspacio=productEspacio+" ";
        }
        int digitos=0;
        int num=temp->getProducto()->getCantidad();
        while(num!=0)
        {
            digitos++;
            num=num/10;
        }
        string cantidadEspacio="";
        for(int indE=0;indE<(28-digitos);indE++)
        {
            cantidadEspacio=cantidadEspacio+" ";
        }
        digitos=0;
        num=int(temp->getProducto()->getPrecio());
        while(num!=0)
        {
            digitos++;
            num=num/10;
        }
        cout<<ind<<". "<<temp->getProducto()->getNombre()<<productEspacio<<temp->getProducto()->getCantidad()<<cantidadEspacio<<temp->getProducto()->getPrecio()<<endl;
        temp=temp->getNext();
        ind++;
    }
}
