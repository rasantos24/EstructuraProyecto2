#ifndef GRAFICAR_H
#define GRAFICAR_H

#include <QDialog>
#include "grafos.h"
#include "vista.h"

namespace Ui {
class Graficar;
}

class Graficar : public QDialog
{
    Q_OBJECT

public:
    int tipoGrafo;

    explicit Graficar(QWidget *parent = 0);
    ~Graficar();

private slots:
    void on_BtnCalcularMat_clicked();

    void on_BtnAgregarVer_clicked();

    void on_BtnAgregarAri_clicked();

    void on_BtnBorrarAri_2_clicked();

    void on_BtnBorrarAri_clicked();

    void on_BtnBorrarVer_clicked();

    void on_BtnAbrir_clicked();

    void on_CmbTipos_currentIndexChanged(int index);

    void on_BtnBorrarVert_clicked();

    void on_BtnBorrarVertice_clicked();

    void on_BtnBorrarArista_clicked();

    void on_BtnAgregarArista_clicked();

private:
    Ui::Graficar *ui;
    Grafo<QString>* grafo;
    QGraphicsScene* matrizView;
    Vista* visual;
    int** matrizAd;
    bool** caminos;
    bool warshall;
    int* dijkstraDistancias;
    Lista<Arista<QString>*>* listaPrim;
    Lista<Arista<QString>*>* listaKruskal;
};

#endif // GRAFICAR_H
