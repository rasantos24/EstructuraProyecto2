#include "proyectoii.h"
#include "ui_proyectoii.h"

ProyectoII::ProyectoII(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProyectoII)
{
    ui->setupUi(this);
}

ProyectoII::~ProyectoII()
{
    delete ui;
}

void ProyectoII::on_Grafos_clicked()
{
    Graficar tgmr;
    tgmr.exec();
}

void ProyectoII::on_Sorts_clicked()
{
    OrdenSort tgmr;
    tgmr.exec();
}
