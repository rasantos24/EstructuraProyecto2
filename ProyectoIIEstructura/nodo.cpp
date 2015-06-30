#include "Nodo.h"
#include <iostream>

template<class T>
Nodo<T>::Nodo(T valor)
{
    this->valor = valor;
    this->siguiente = NULL;
}

template <class T>
Nodo<T>::~Nodo()
{
    //dtor
}
