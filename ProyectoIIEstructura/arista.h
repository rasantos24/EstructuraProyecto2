#ifndef ARISTA_H
#define ARISTA_H

#include <QGraphicsLineItem>
#include <QGraphicsTextItem>

template <class T>
class Vertice;

template <class T>
class Arista
{
public:
    Vertice<T>* origen;
    Vertice<T>* destino;
    QGraphicsLineItem* linea;
    QGraphicsTextItem* texto;
    int peso;
    bool dirigido;

    Arista(Vertice<T>* origen, Vertice<T>* destino, int peso)
    {
        this->origen = origen;
        this->destino = destino;
        this->peso = peso;
        this->linea = NULL;
        this->texto = NULL;
    }

    virtual ~Arista() {}
};

#endif // ARISTA_H
