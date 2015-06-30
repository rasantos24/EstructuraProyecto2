#ifndef VISTA_H
#define VISTA_H

#include <QDialog>
#include <QGraphicsScene>
#include "vertice.h"

namespace Ui {
class Vista;
}

class Vista : public QDialog
{
    Q_OBJECT

public:
    explicit Vista(Lista<Vertice<QString>*>* lista, int tipoGrafo, QWidget *parent = 0);

    void showOnScene(int** matriz);
    void showOnScene(bool** caminos);
    void showOnScene(int* distancias, int origen);
    void showOnScene(Lista<Arista<QString>*>* lista);

    ~Vista();

private slots:
    void on_BtnSalir_clicked();

private:
    Ui::Vista *ui;
    Lista<Vertice<QString>*>* listaTemporal;
    Lista<Vertice<QString>*> vertices;
    QGraphicsScene* escena;
    int tipoGrafo;

    void buildScene();
    void floyd(int** matrizAdyacencia);
    void dijkstra(int* distancias, int origen);
    void prim(Lista<Arista<QString>*>* lista);
};

#endif // VISTA_H
