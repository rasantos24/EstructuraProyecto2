#ifndef GRAFO_H
#define GRAFO_H

#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include "Vertice.h"

template <class T>
class Grafo : public QGraphicsScene
{
public:
    Lista<Vertice<T>*> vertices;
    Lista<Arista<T>*> aristas;
    int tipoGrafo;

    Grafo(int tipoGrafo)
    {
        this->tipoGrafo = tipoGrafo;
    }

    bool validarVertice(T valor)
    {
        for(int i=0; i<vertices.getCantidad(); i++)
        {
            if(vertices.obtenerValor(i)->valor == valor)
                throw new std::exception;
        }
        return true;
    }

    Vertice<T>* obtenerVertice(T valor)
    {
        for(int i=0; i<vertices.getCantidad(); i++)
        {
            if(vertices.obtenerValor(i)->valor == valor)
                return vertices.obtenerValor(i);
        }
        return NULL;
    }

    Arista<T>* obtenerArista(T origen, T destino)
    {
        for(int i=0; i<aristas.getCantidad(); i++)
        {
            if(aristas.obtenerValor(i)->origen == origen && aristas.obtenerValor(i)->destino == destino)
                return aristas.obtenerValor(i);
        }
        return NULL;
    }

    void agregarVertice(T valor)
    {
        if(validarVertice(valor))
        {
            Vertice<T>* vertice = new Vertice<T>(valor, tipoGrafo);
            addItem(vertice);
            vertices.agregar(vertice);
            vertice->setFlag(QGraphicsItem::ItemIsMovable);
            vertice->setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
        }
    }

    void agregarArista(T origen, T destino, int peso, bool noDirigido)
    {
        Vertice<T>* verOrigen = obtenerVertice(origen);
        Vertice<T>* verDestino = obtenerVertice(destino);

        if(verOrigen != NULL && verDestino != NULL)
        {
            Arista<T>* arista = new Arista<T>(verOrigen, verDestino, peso);
            aristas.agregar(arista);
            verOrigen->aristasOrigen.agregar(arista);
            verDestino->aristasDestino.agregar(arista);

            if(noDirigido)
            {
                Arista<T>* arista2 = new Arista<T>(verDestino, verOrigen, peso);
                aristas.agregar(arista2);
                verDestino->aristasOrigen.agregar(arista2);
                verOrigen->aristasDestino.agregar(arista2);
                arista->linea = addLine(verOrigen->pos().x()+100, verOrigen->pos().y()+50, verDestino->pos().x(), verDestino->pos().y()+50);
            }

            else
            {
                arista->linea = addLine(verOrigen->pos().x()+100, verOrigen->pos().y()+50, verDestino->pos().x(), verDestino->pos().y()+50);
                QGraphicsEllipseItem* punto = addEllipse(verDestino->pos().x(), verDestino->pos().y()+50, 6, 6, QPen(), QBrush(Qt::SolidPattern));
                verDestino->puntos.agregar(punto);
            }

            arista->texto = addText(QString::number(peso));
            arista->texto->setPos((verOrigen->pos().x() + verDestino->pos().x())/2, (verOrigen->pos().y() + verDestino->pos().y())/2);
        }
    }

    void eliminarArista(T origen, T destino)
    {
        Vertice<T>* verOrigen = obtenerVertice(origen);
        Vertice<T>* verDestino = obtenerVertice(destino);
        Arista<T>* arista = NULL;

        for(int i=0; i<verOrigen->aristasOrigen.getCantidad(); i++)
        {
            if(verOrigen->aristasOrigen.obtenerValor(i)->destino == verDestino)
            {
                if(verOrigen->aristasOrigen.obtenerValor(i)->linea != NULL)
                    removeItem(verOrigen->aristasOrigen.obtenerValor(i)->linea);

                if(verOrigen->aristasOrigen.obtenerValor(i)->texto != NULL)
                    removeItem(verOrigen->aristasOrigen.obtenerValor(i)->texto);

                verOrigen->aristasOrigen.eliminar(i);
                break;
            }
        }

        for(int i=0; i<verDestino->aristasDestino.getCantidad(); i++)
        {
            if(verDestino->aristasDestino.obtenerValor(i)->origen == verOrigen)
            {
                verDestino->aristasDestino.eliminar(i);

                if(verDestino->puntos.getCantidad() > 0)
                {
                    removeItem(verDestino->puntos.obtenerValor(verDestino->puntos.getCantidad()-1));
                    verDestino->puntos.eliminar(verDestino->puntos.getCantidad()-1);
                }
                break;
            }
        }

        for(int i=0; i<aristas.getCantidad(); i++)
        {
            if(aristas.obtenerValor(i)->origen == verOrigen && aristas.obtenerValor(i)->destino == verDestino)
            {
                arista = aristas.obtenerValor(i);
                aristas.eliminar(i);
                break;
            }
        }
        if(arista != NULL)
            delete arista;
    }

    void eliminarVertice(T valor)
    {
        Vertice<T>* vertice = obtenerVertice(valor);

        for(int i=0; i<vertices.getCantidad(); i++)
        {
            if(vertices.obtenerValor(i) == vertice)
                continue;
            eliminarArista(vertice->valor, vertices.obtenerValor(i)->valor);
        }

        for(int i=0; i<vertices.getCantidad(); i++)
        {
            if(vertices.obtenerValor(i) == vertice)
                continue;
            eliminarArista(vertices.obtenerValor(i)->valor, vertice->valor);
        }

        for(int i=0; i<vertices.getCantidad(); i++)
        {
            if(vertices.obtenerValor(i) == vertice)
            {
                vertices.eliminar(i);
                break;
            }
        }
        removeItem(vertice);
        delete vertice;
    }

    int** crearMatrizAdyacencia()
    {
        int cantidad = vertices.getCantidad();
        int** matriz = new int*[cantidad];

        if(cantidad == 0 && aristas.getCantidad() == 0)
            return NULL;

        for(int i=0; i<cantidad; i++)
            matriz[i] = new int[cantidad];

        for(int i=0; i<cantidad; i++)
        {
            for(int j=0; j<cantidad; j++)
                matriz[i][j] = 0;
        }

        for(int i = 0; i < aristas.getCantidad(); i++)
        {
            int origen = vertices.obtenerPosicion(aristas.obtenerValor(i)->origen);
            int destino = vertices.obtenerPosicion(aristas.obtenerValor(i)->destino);
            matriz[origen][destino] = aristas.obtenerValor(i)->peso;
        }
        return matriz;
    }

    template <typename U>
    void borrarMatriz(U** matriz)
    {
        int cantidad = vertices.getCantidad();

        for(int i=0; i<cantidad; i++)
        {
            for(int j=0; j<cantidad; j++)
                delete[] matriz[i];
        }
        delete[] matriz;
    }

    template <class U>
    void actualizarMatrizEscena(QGraphicsScene* scene, U** matriz)
    {
        QGraphicsTextItem* peso;
        int posX = 0;
        int posY = 0;

        for(int i=0; i <vertices.getCantidad(); i++)
        {
            for(int j=0; j<vertices.getCantidad(); j++)
            {
                peso = scene->addText(QString::number(matriz[i][j]));
                peso->setFlag(QGraphicsItem::ItemIsMovable);
                peso->setPos(posX, posY);
                peso->setFont(QFont("Arial", 12, QFont::Bold));
                posX+= 25;
            }
            posY+= 25;
            posX = 0;
        }
    }

    void Floyd(int** matriz, int cantidad)
    {
        for(int k=0; k<cantidad; k++)
        {
            for(int i=0; i<cantidad; i++)
            {
                for(int j=0; j<cantidad; j++)
                {
                    if((matriz[i][k] * matriz[k][j] != 0) && (i != j))
                    {
                        if(matriz[i][k] + matriz[k][j] < matriz[i][j] || matriz[i][j] == 0)
                            matriz[i][j] = matriz[i][k] + matriz[k][j];
                    }
                }
            }
        }
    }

    bool** Warshall(int** matriz, int cantidad)
    {
        bool** caminos = new bool*[cantidad];

        for(int i=0; i<cantidad; i++)
            caminos[i] = new bool[cantidad];

        for(int i=0; i<cantidad; i++)
        {
            for(int j=0; j<cantidad; j++)
            {
                if(matriz[i][j] == 0)
                    caminos[i][j] = false;
                else
                    caminos[i][j] = true;
            }
        }

        for(int k=0; k<cantidad; k++)
        {
            for(int i=0; i<cantidad; i++)
            {
                for(int j=0; j<cantidad; j++)
                {
                    if(caminos[i][k] && caminos[k][j] || caminos[i][j])
                        caminos[i][j] = true;
                }
            }
        }

        return caminos;
    }

    Lista<Arista<T>*>* Prim(int** matriz, int cantidad, int posOrigen, QGraphicsScene* scene)
    {
        int visitados[cantidad];
        int minimo;
        int u = 0;
        int v = 0;
        int total = 0;
        int posYScene = 0;
        QGraphicsTextItem* texto;
        QString textPrim;
        Lista<Arista<T>*>* lista = new Lista<Arista<T>*>();

        for(int i=0; i<cantidad; i++)
        {
            visitados[i] = 0;
            for(int j=0; j<cantidad; j++)
            {
                if(matriz[i][j] == 0)
                    matriz[i][j] = 999;
            }
        }

        visitados[posOrigen] = 1;

        //start of algorithm
        for(int counter=0; counter<cantidad-1; counter++)
        {
            minimo = 999;

            for(int i=0; i<cantidad; i++)
            {
                if(visitados[i] == 1)
                {
                    for(int j=0; j<cantidad; j++)
                    {
                        if(visitados[j] != 1)
                        {
                            if(minimo > matriz[i][j])
                            {
                                minimo = matriz[i][j];
                                u = i;
                                v = j;
                            }
                        }
                    }
                }
            }

            if(visitados[v] != 1 && minimo != 999)
            {
                visitados[v] = 1;
                total += minimo;
                textPrim = "Vertice encontrado: " + vertices.obtenerValor(u)->valor + "->" + vertices.obtenerValor(v)->valor + ": Longitud:" + QString::number(minimo);
                texto = scene->addText(textPrim);
                texto->setPos(0, posYScene);
                texto->setFont(QFont("Arial", 12, QFont::Bold));
                posYScene+= 25;
                lista->agregar(new Arista<T>(vertices.obtenerValor(u), vertices.obtenerValor(v), minimo));
            }
        }

        textPrim = "El peso del Arbol Abarcador de Costo Minimo: " + QString::number(total);
        posYScene += 10;
        texto = scene->addText(textPrim);
        texto->setPos(0, posYScene);
        texto->setFont(QFont("Arial", 12, QFont::Bold));

        return lista;
    }

    Lista<Arista<T>*>* Kruskal2(int** matriz, int cantidad, int tipoGrafo, QGraphicsScene* scene)
    {
        int minimo;
        int u = 0;
        int v = 0;
        int noOfEdges = 1;
        int total = 0;
        int posYScene = 0;
        Lista<Lista<Vertice<T>*>*> lista;
        QString textKruskal;
        QGraphicsTextItem* texto;
        Lista<Arista<T>*>* listaAristas = new Lista<Arista<T>*>();

        for(int i=0; i<cantidad; i++)
            lista.agregar(new Lista<Vertice<T>*>());

        for(int i=0; i<cantidad; i++)
            lista.obtenerValor(i)->agregar(vertices.obtenerValor(i));

        for(int i=0; i<cantidad; i++)
        {
            for(int j=0; j<cantidad; j++)
            {
                if(matriz[i][j] == 0)
                    matriz[i][j] = 999;
            }
        }
        //start of algorithm
        while(noOfEdges < cantidad)
        {
            minimo = 999;
            bool ciclo = false;

            for(int i=0; i<cantidad; i++)
            {
                for(int j=0; j<cantidad; j++)
                {
                    ciclo = false;
                    if(matriz[i][j] < minimo)
                    {
                        for(int x=0; x<lista.getCantidad(); x++)
                        {
                            if(lista.obtenerValor(x)->existe(vertices.obtenerValor(i)))
                            {
                                if(lista.obtenerValor(x)->existe(vertices.obtenerValor(j)))
                                {
                                    ciclo = true;
                                    break;
                                }
                                else
                                    break;
                            }
                        }

                        if(ciclo != true)
                        {
                            minimo = matriz[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }

            if(v != u)
            {
                noOfEdges++;
                if(minimo == 999)
                    continue;
                textKruskal = "Arista encontrada: " + vertices.obtenerValor(u)->valor + "->" + vertices.obtenerValor(v)->valor + "Minimo: " + QString::number(minimo);
                texto = scene->addText(textKruskal);
                texto->setPos(0, posYScene);
                texto->setFont(QFont("Arial", 12, QFont::Bold));
                total+= minimo;
                posYScene+= 25;
                listaAristas->agregar(new Arista<T>(vertices.obtenerValor(u), vertices.obtenerValor(v), minimo));

                Lista<Vertice<T>*> listaTempo;
                int posListaBorrar;

                for(int i=0; i<lista.getCantidad(); i++)
                {
                    if(lista.obtenerValor(i)->existe(vertices.obtenerValor(v)))
                    {
                        posListaBorrar = i;
                        for(int j = 0; j < lista.obtenerValor(i)->getCantidad(); j++)
                            listaTempo.agregar(lista.obtenerValor(i)->obtenerValor(j));
                        break;
                    }
                }

                for(int i=0; i<lista.getCantidad(); i++)
                {
                    if(lista.obtenerValor(i)->existe(vertices.obtenerValor(u)))
                    {
                        for(int j = 0; j < listaTempo.getCantidad(); j++)
                            lista.obtenerValor(i)->agregar(listaTempo.obtenerValor(j));
                        break;
                    }
                }

                lista.eliminar(posListaBorrar);
            }

            if(tipoGrafo == 1)
                matriz[u][v] = 999;
            else
                matriz[u][v] = matriz[v][u] = 999;
        }

        textKruskal = "El peso del Arbol Abarcador de Costo Minimo: " + QString::number(total);
        texto = scene->addText(textKruskal);
        texto->setPos(0, posYScene);
        texto->setFont(QFont("Arial", 12, QFont::Bold));

        return listaAristas;
    }

    int* Dijkstra(int** matriz, int cantidad, int origen, QGraphicsScene* scene)
    {
        int* distancia = new int[cantidad];
        int visitados[cantidad];
        int preD[cantidad];
        int minimo;
        int nextNode = 0;
        QString textDijkstra;
        QGraphicsTextItem* texto;
        int posXScene = 0;

        for(int i=0; i<cantidad; i++)
        {
            visitados[i] = 0;
            preD[i] = 0;

            for(int j=0; j<cantidad; j++)
            {
                if(matriz[i][j] == 0)
                    matriz[i][j] = 999;
            }
        }

        for(int i = 0; i < cantidad; i++)
            distancia[i] = matriz[origen][i];

        distancia[origen] = 0;
        visitados[origen] = 1;

        //start with the algorithm
        for(int i=0; i<cantidad; i++)
        {
            minimo = 999;

            for(int j=0; j<cantidad; j++)
            {
                if(minimo > distancia[j] && visitados[j] != 1)
                {
                    minimo = distancia[j];
                    nextNode = j;
                }
            }

            visitados[nextNode] = 1;

            //actual start of the algorithm
            for(int c=0; c<cantidad; c++)
            {
                if(visitados[c] != 1)
                {
                    if(minimo + matriz[nextNode][c] < distancia[c])
                    {
                        distancia[c] = minimo + matriz[nextNode][c];
                        preD[c] = nextNode;
                    }
                }
            }
        }

        for(int i=0; i<cantidad; i++)
        {
            textDijkstra = "|" + QString::number(distancia[i]);
            texto = scene->addText(textDijkstra);
            texto->setPos(posXScene, 0);
            texto->setFont(QFont("Arial", 12, QFont::Bold));
            posXScene+= 35;
        }

        return distancia;
    }

    virtual ~Grafo() {}
};

#endif // GRAFO_H
