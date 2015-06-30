#ifndef VERTICE_H
#define VERTICE_H

#include <QGraphicsItem>
#include <QPainter>
#include "MiLista.h"
#include "MiLista.cpp"
#include "Arista.h"

template <class T>
class Vertice : public QGraphicsItem
{
public:
    T valor;
    Lista<Arista<T>*> aristasOrigen;
    Lista<Arista<T>*> aristasDestino;
    Lista<QGraphicsEllipseItem*> puntos;
    int tipoGrafo;
    int posSceneX;
    int posSceneY;

    Vertice(T valor, int tipoGrafo)
    {
        this->valor = valor;
        this->tipoGrafo = tipoGrafo;
        this->posSceneX = 0;
        this->posSceneY = 0;
    }

    QRectF boundingRect() const
    {
        return QRectF(0, 0, 100, 100);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QBrush brush(Qt::red);
        QRectF rect = boundingRect();
        painter->fillRect(rect, brush);
        painter->drawRect(rect);
        painter->setFont(QFont("Arial", 12, QFont::Bold));
        painter->drawText(rect, valor);
    }

    QVariant itemChange(GraphicsItemChange change, const QVariant &value)
    {
        if(change == ItemPositionHasChanged)
        {
            for(int i=0; i<aristasOrigen.getCantidad(); i++)
            {
                Arista<T>* arista = aristasOrigen.obtenerValor(i);
                if(tipoGrafo == 1)
                    arista->linea->setLine(pos().x()+100, pos().y()+50, arista->destino->pos().x(), arista->destino->pos().y()+50);
                else
                {
                    if(arista->linea != NULL)
                        arista->linea->setLine(pos().x()+100, pos().y()+50, arista->destino->pos().x(), arista->destino->pos().y()+50);
                }

                if(arista->texto != NULL)
                    arista->texto->setPos((pos().x() + arista->destino->pos().x())/2, (pos().y() + arista->destino->pos().y())/2);
            }

            for(int i=0; i<aristasDestino.getCantidad(); i++)
            {
                Arista<T>* arista = aristasDestino.obtenerValor(i);
                if(arista->linea != NULL)
                {
                    if(tipoGrafo == 1)
                        arista->linea->setLine(arista->origen->pos().x()+50, arista->origen->pos().y()+50, pos().x(), pos().y()+50);
                    else
                        arista->linea->setLine(arista->origen->pos().x()+100, arista->origen->pos().y()+50, pos().x(), pos().y()+50);
                    arista->texto->setPos((arista->origen->pos().x() + pos().x())/2, (arista->origen->pos().y() + pos().y())/2);
                }
            }

            for(int i=0; i<puntos.getCantidad(); i++)
                puntos.obtenerValor(i)->setRect( pos().x(), pos().y()+50, 6, 6);

            this->posSceneX = pos().x();
            this->posSceneY = pos().y();
        }

        return QGraphicsItem::itemChange(change, value);
    }

    virtual ~Vertice() {}
};

#endif // VERTICE_H
