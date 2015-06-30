#include "graficar.h"
#include "ui_graficar.h"

Graficar::Graficar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graficar)
{
    ui->setupUi(this);
    grafo = new Grafo<QString>(this->tipoGrafo);
    visual = new Vista(&(grafo->vertices), this->tipoGrafo);
    ui->VistaGrafo->setScene(grafo);
    grafo->setSceneRect(0, 0, 851, 691);
    this->matrizView = new QGraphicsScene();
    this->matrizView->setSceneRect(0, 0, 421, 361);
    this->matrizAd = NULL;
    this->caminos = NULL;
    this->warshall = false;
    ui->VistaMatriz->setScene(matrizView);
}

Graficar::~Graficar()
{
    delete ui;
}

void Graficar::on_BtnCalcularMat_clicked()
{
    if(grafo->vertices.getCantidad() == 0)
        return;

    if(matrizAd != NULL)
    {
        grafo->borrarMatriz<int>(this->matrizAd);
        this->matrizAd = NULL;
        matrizView->clear();
        matrizView->update();
    }

    if(caminos != NULL)
    {
        grafo->borrarMatriz<bool>(caminos);
        caminos = NULL;
    }

    this->matrizAd = grafo->crearMatrizAdyacencia();

    switch(ui->CmbTipos->currentIndex())
    {
        case 0:
            break;

        case 1:
        {
            grafo->Floyd(matrizAd, grafo->vertices.getCantidad());
            break;
        }

        case 2:
        {
            if(!ui->BtnAbrir->isEnabled())
                ui->BtnAbrir->setEnabled(true);

            this->dijkstraDistancias = grafo->Dijkstra(matrizAd, grafo->vertices.getCantidad(), ui->CmbOrigen->currentIndex(), matrizView);
            return;
        }

        case 3:
        {
            if(!ui->BtnAbrir->isEnabled())
                ui->BtnAbrir->setEnabled(true);

            this->listaPrim = grafo->Prim(matrizAd, grafo->vertices.getCantidad(), ui->CmbOrigen->currentIndex(), matrizView);
            return;
        }

        case 4:
        {
            if(grafo->aristas.getCantidad() == 0)
                return;

            if(!ui->BtnAbrir->isEnabled())
                ui->BtnAbrir->setEnabled(true);

            this->listaKruskal = grafo->Kruskal2(matrizAd, grafo->vertices.getCantidad(), this->tipoGrafo, matrizView);
            return;
        }
    }

    if(warshall != true)
        grafo->actualizarMatrizEscena<int>(matrizView, matrizAd);
    else
    {
        grafo->actualizarMatrizEscena<bool>(matrizView, caminos);
        warshall = false;
    }

    if(!ui->BtnAbrir->isEnabled())
        ui->BtnAbrir->setEnabled(true);
}

void Graficar::on_BtnAgregarVer_clicked()
{
    if(ui->EditValorVer->text() != "")
    {
        grafo->agregarVertice(ui->EditValorVer->text());
        ui->CmbOrigen->addItem(ui->EditValorVer->text());
    }

    ui->EditValorVer->setText("");
}

void Graficar::on_BtnAgregarAri_clicked()
{
    if(ui->EditOrigen->text() != "" && ui->EditDestino->text() != "" && ui->EditCosto->text() != "")
    {
        QString origen = ui->EditOrigen->text();
        QString destino = ui->EditDestino->text();
        int costo = ui->EditCosto->text().toInt();

        for(int i=0; i<grafo->aristas.getCantidad(); i++)
        {
            if(grafo->aristas.obtenerValor(i)->origen->valor == origen && grafo->aristas.obtenerValor(i)->destino->valor == destino)
                return;
        }

        if(tipoGrafo == 1)
            grafo->agregarArista(origen, destino, costo, false);
        else
            grafo->agregarArista(origen, destino, costo, true);
    }

    ui->EditOrigen->setText("");
    ui->EditDestino->setText("");
    ui->EditCosto->setText("");
}

void Graficar::on_BtnBorrarAri_2_clicked()
{

}

void Graficar::on_BtnBorrarAri_clicked()
{

}

void Graficar::on_BtnBorrarVer_clicked()
{

}

void Graficar::on_BtnAbrir_clicked()
{
    int index = ui->CmbTipos->currentIndex();

    switch(index)
    {
        case 0:
        {
            return;
        }

        case 1:
        {
            this->visual->show();
            this->visual->showOnScene(this->matrizAd);
            break;
        }

        case 2:
        {
            this->visual->show();
            this->visual->showOnScene(this->dijkstraDistancias, ui->CmbOrigen->currentIndex());
            break;
        }

        case 3:
        {
            this->visual->show();
            this->visual->showOnScene(this->listaPrim);
            break;
        }

        case 4:
        {
            this->visual->show();
            this->visual->showOnScene(this->listaKruskal);
            break;
        }
    }
}

void Graficar::on_CmbTipos_currentIndexChanged(int index)
{
    if((index == 4 || index == 3) && grafo->vertices.getCantidad() > 0)
        ui->CmbOrigen->setEnabled(true);
    else
        ui->CmbOrigen->setEnabled(false);
}

void Graficar::on_BtnBorrarVert_clicked()
{

}

void Graficar::on_BtnBorrarVertice_clicked()
{
    if(ui->EditVerticeBo->text() != "")
    {
        QString verticeValor = ui->EditVerticeBo->text();
        int pos = grafo->vertices.obtenerPosicion(grafo->obtenerVertice(verticeValor));
        if(pos == -1)
            return;

        grafo->eliminarVertice(verticeValor);
        ui->CmbOrigen->removeItem(pos);
    }

    ui->EditVerticeBo->setText("");
}

void Graficar::on_BtnBorrarArista_clicked()
{
    if(ui->EditOrigenBo->text() != "" && ui->EditDestinoBo->text() != "")
    {
        QString origen = ui->EditOrigenBo->text();
        QString destino = ui->EditDestinoBo->text();
        int pos = grafo->vertices.obtenerPosicion(grafo->obtenerVertice(origen));
        int posi = grafo->vertices.obtenerPosicion(grafo->obtenerVertice(destino));

        if(pos == -1 || posi == -1)
            return;

        if(tipoGrafo == 1)
            grafo->eliminarArista(origen, destino);
        else
        {
            grafo->eliminarArista(origen, destino);
            grafo->eliminarArista(destino, origen);
        }
    }

    ui->EditOrigenBo->setText("");
    ui->EditDestinoBo->setText("");
}

void Graficar::on_BtnAgregarArista_clicked()
{
    if(ui->EditOrigen->text() != "" && ui->EditDestino->text() != "" && ui->EditCosto->text() != "")
    {
        QString origen = ui->EditOrigen->text();
        QString destino = ui->EditDestino->text();
        int costo = ui->EditCosto->text().toInt();

        for(int i=0; i<grafo->aristas.getCantidad(); i++)
        {
            if(grafo->aristas.obtenerValor(i)->origen->valor == origen && grafo->aristas.obtenerValor(i)->destino->valor == destino)
                return;
        }

        if(tipoGrafo == 1)
            grafo->agregarArista(origen, destino, costo, false);
        else
            grafo->agregarArista(origen, destino, costo, true);
    }

    ui->EditOrigen->setText("");
    ui->EditDestino->setText("");
    ui->EditCosto->setText("");
}
