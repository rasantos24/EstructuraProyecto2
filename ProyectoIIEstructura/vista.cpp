#include "vista.h"
#include "ui_vista.h"

Vista::Vista(Lista<Vertice<QString>*>* lista, int tipoGrafo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vista)
{
    ui->setupUi(this);
    this->listaTemporal = lista;
    this->escena = new QGraphicsScene();
    this->escena->setSceneRect(0, 0, 851, 691);
    this->tipoGrafo = tipoGrafo;
    ui->Vista_2->setScene(escena);
}

Vista::~Vista()
{
    delete ui;
}

void Vista::floyd(int** matrizAd)
{
    for(int origen=0; origen<listaTemporal->getCantidad(); origen++)
    {
        for(int destino=0; destino<listaTemporal->getCantidad(); destino++)
        {
            if(matrizAd[origen][destino] != 999 && matrizAd[origen][destino] != 0)
            {
                int posOrigenX = vertices.obtenerValor(origen)->posSceneX;
                int posOrigenY = vertices.obtenerValor(origen)->posSceneY;
                int posDestinoX = vertices.obtenerValor(destino)->posSceneX;
                int posDestinoY = vertices.obtenerValor(destino)->posSceneY;

                this->escena->addLine(posOrigenX, posOrigenY, posDestinoX, posDestinoY);
                QGraphicsTextItem* texto;
                texto = escena->addText(QString::number(matrizAd[origen][destino]));
                texto->setPos((vertices.obtenerValor(origen)->pos().x() + vertices.obtenerValor(destino)->pos().x())/2,
                             (vertices.obtenerValor(origen)->pos().y() + vertices.obtenerValor(destino)->pos().y())/2);
            }
        }
    }
}

void Vista::dijkstra(int* distancias, int origen)
{
    for(int destino=0; destino<listaTemporal->getCantidad(); destino++)
    {
        Vertice<QString>* verOrigen = vertices.obtenerValor(origen);
        if(distancias[destino] != 0)
        {
            int posOrigenX = verOrigen->posSceneX;
            int posOrigenY = verOrigen->posSceneY;
            int posDestinoX = vertices.obtenerValor(destino)->posSceneX;
            int posDestinoY = vertices.obtenerValor(destino)->posSceneY;

            this->escena->addLine(posOrigenX, posOrigenY, posDestinoX, posDestinoY);
            QGraphicsTextItem* texto;
            texto = escena->addText(QString::number(distancias[destino]));
            texto->setPos((posOrigenX + posDestinoX)/2, (posOrigenY + posDestinoY)/2);
        }
    }
    delete []distancias;
}

void Vista::prim(Lista<Arista<QString>*>* lista)
{
    Vertice<QString>* verOrigen;
    Vertice<QString>* verDestino;

    for(int k=0; k<lista->getCantidad(); k++)
    {
        for(int i=0; i<vertices.getCantidad(); i++)
        {
            if(vertices.obtenerValor(i)->valor == lista->obtenerValor(k)->origen->valor)
            {
                verOrigen = vertices.obtenerValor(i);
                break;
            }
        }

        for(int i=0; i<vertices.getCantidad(); i++)
        {
            if(vertices.obtenerValor(i)->valor == lista->obtenerValor(k)->destino->valor)
            {
                verDestino = vertices.obtenerValor(i);
                break;
            }
        }

        int posOrigenX = verOrigen->posSceneX;
        int posOrigenY = verOrigen->posSceneY;
        int posDestinoX = verDestino->posSceneX;
        int posDestinoY = verDestino->posSceneY;

        this->escena->addLine(posOrigenX, posOrigenY, posDestinoX, posDestinoY);
        QGraphicsTextItem* texto = escena->addText(QString::number(lista->obtenerValor(k)->peso));
        texto->setPos((posOrigenX + posDestinoX)/2, (posOrigenY + posDestinoY)/2);
    }

    Arista<QString>* arista;

    for(int i=0; i<lista->getCantidad(); i++)
    {
        arista = lista->obtenerValor(i);
        lista->eliminar(i);
        delete arista;
        i--;
    }

    delete lista;
}

void Vista::buildScene()
{
    for(int i=0; i<this->listaTemporal->getCantidad(); i++)
    {
        Vertice<QString>* vertice = new Vertice<QString>(this->listaTemporal->obtenerValor(i)->valor, this->tipoGrafo);
        vertice->posSceneX = this->listaTemporal->obtenerValor(i)->posSceneX;
        vertice->posSceneY = this->listaTemporal->obtenerValor(i)->posSceneY;
        vertices.agregar(vertice);
        this->escena->addItem(vertice);
        vertice->setPos(listaTemporal->obtenerValor(i)->posSceneX, listaTemporal->obtenerValor(i)->posSceneY);
    }
}

void Vista::showOnScene(int** matriz)
{
    this->buildScene();
    floyd(matriz);
}

void Vista::showOnScene(int* distancias, int origen)
{
    this->buildScene();
    dijkstra(distancias, origen);
}

void Vista::showOnScene(Lista<Arista<QString>*>* lista)
{
    this->buildScene();
    prim(lista);
}

void Vista::on_BtnSalir_clicked()
{
    Vertice<QString>* vertice;
    for(int i=0; i<vertices.getCantidad(); i++)
    {
        vertice = vertices.obtenerValor(i);
        vertices.eliminar(i);
        delete vertice;
        i--;
    }

    escena->clear();
    escena->update();
    this->hide();
}
