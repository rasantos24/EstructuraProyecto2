#include "MiLista.h"

template<class T>
Lista<T>::Lista()
{
    this->temporal = NULL;
    this->inicio = NULL;
    this->cantidad = 0;
}

template<class T>
void Lista<T>::insertar(int posicion, T valor)
{
    if(posicion<0 || posicion>cantidad)
        return;
    else
    {
        Nodo<T>* nodo = new Nodo<T>(valor);
        this->temporal = inicio;

        if(posicion == 0)
        {
            inicio = nodo;
            inicio->siguiente = temporal;
            cantidad++;
            return;
        }

        for(int i = 0; i < posicion-1; i++)
            temporal = temporal->siguiente;

        Nodo<T>* tempo = temporal->siguiente;
        temporal->siguiente = nodo;
        temporal->siguiente->siguiente = tempo;
        cantidad++;
    }
}

template<class T>
void Lista<T>::agregar(T valor)
{
    insertar(cantidad, valor);
}

template<class T>
int Lista<T>::getCantidad()
{
    return this->cantidad;
}

template<class T>
T Lista<T>::obtenerValor(int posicion)
{
    temporal=inicio;
    for(int i=0; i<cantidad; i++)
    {
        if(i == posicion)
            return temporal->valor;

        temporal=temporal->siguiente;
    }
}

template<class T>
int Lista<T>::obtenerPosicion(T valor)
{
    temporal=inicio;
    for(int i=0; i<cantidad; i++)
    {
        if(temporal->valor == valor)
            return i;
        temporal = temporal->siguiente;
    }
    return -1;
}

template<class T>
void Lista<T>::eliminar(int posicion)
{
    if(posicion<0 || posicion>cantidad)
        return;

    if(posicion == 0)
    {
        Nodo<T>* tempo = inicio;
        inicio = inicio->siguiente;
        delete tempo;
        cantidad--;
        return;
    }
    temporal=inicio;

    for(int i=0; i<posicion-1; i++)
        temporal = temporal->siguiente;

    Nodo<T>* tempo = temporal->siguiente;
    temporal->siguiente = temporal->siguiente->siguiente;
    delete tempo;
    cantidad--;
}

template<class T>
void Lista<T>::mostrarLista()
{
    this->temporal=inicio;

    for(int i=0; i<cantidad; i++)
    {
        std::cout << temporal->valor << std::endl;
        temporal = temporal->siguiente;
    }
}

template<class T>
bool Lista<T>::existe(T valor)
{
    temporal=inicio;
    for(int i=0; i<cantidad; i++)
    {
        if(temporal->valor == valor)
            return true;
        temporal=temporal->siguiente;
    }
    return false;
}

template<class T>
Lista<T>::~Lista()
{
    //dtor
}
