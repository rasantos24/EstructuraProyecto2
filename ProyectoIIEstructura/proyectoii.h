#ifndef PROYECTOII_H
#define PROYECTOII_H

#include <QMainWindow>
#include "graficar.h"
#include "ordensort.h"
#include "time.h"

namespace Ui {
class ProyectoII;
}

class ProyectoII : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProyectoII(QWidget *parent = 0);
    ~ProyectoII();

private slots:
    void on_Grafos_clicked();

    void on_Sorts_clicked();

private:
    Ui::ProyectoII *ui;
};

#endif // PROYECTOII_H
