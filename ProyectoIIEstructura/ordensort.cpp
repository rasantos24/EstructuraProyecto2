#include "ordensort.h"
#include "ui_ordensort.h"

OrdenSort::OrdenSort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrdenSort)
{
    ui->setupUi(this);
    tgmr = new IniciarSort();
    generar(1);
}

OrdenSort::~OrdenSort()
{
    delete ui;
}

void OrdenSort::generar(int opcion)
{
    if(opcion == 1)
    {
        for(int i=0; i<tgmr->size; i++)
            ui->ListaDesOrd->addItem(QString::number(tgmr->arreglo[i]));
    }

    if(opcion == 2)
    {
        for(int i=0; i<tgmr->size; i++)
            ui->ListaQS->addItem(QString::number(tgmr->Quick->a[i]));
    }

    if(opcion == 3)
    {
        for(int i=0; i<tgmr->size; i++)
            ui->ListaMS->addItem(QString::number(tgmr->Merge->a[i]));
    }

    if(opcion == 4)
    {
        for(int i=0; i<tgmr->size; i++)
            ui->ListaBubble->addItem(QString::number(tgmr->Bubble->a[i]));
    }

    if(opcion == 5)
    {
        for(int i=0; i<tgmr->size; i++)
            ui->ListaBinSort->addItem(QString::number(tgmr->Bin->a[i]));
    }

    if(opcion == 6)
    {
        for(int i=2; i<tgmr->size; i++)
            ui->ListaHS->addItem(QString::number(tgmr->Heap->a[i]));
    }
}

void OrdenSort::on_BtnQS_clicked()
{
    QS.start();
    tgmr->iniciaQuickSort();
    double inicia = (double(QS.elapsed()))/1000;
    ui->EditQS->setText(QString::number(inicia));
    generar(2);
}

void OrdenSort::on_BtnMS_clicked()
{
    MS.start();
    tgmr->iniciaMergeSort();
    double inicia = (double(MS.elapsed()))/1000;
    ui->EditMS->setText(QString::number(inicia));
    generar(3);
}

void OrdenSort::on_BtnBS_clicked()
{
    BuS.start();
    tgmr->iniciaBubbleSort();
    double inicia = (double(BuS.elapsed()))/1000;
    ui->EditBubble->setText(QString::number(inicia));
    generar(4);
}

void OrdenSort::on_BtnBS_2_clicked()
{
    BS.start();
    tgmr->iniciaBinSort();
    double inicia = (double(BS.elapsed()))/1000;
    ui->EditBinSort->setText(QString::number(inicia));
    generar(5);
}

void OrdenSort::on_BtnHS_clicked()
{
    HS.start();
    tgmr->iniciaHeapSort();
    double inicia = (double(HS.elapsed()))/1000;
    ui->EditHS->setText(QString::number(inicia));
    generar(6);
}

void OrdenSort::on_BtnGenerar_clicked()
{

}
