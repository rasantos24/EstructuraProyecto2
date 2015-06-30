#ifndef ORDENSORT_H
#define ORDENSORT_H

#include <QDialog>
#include "time.h"
#include <QTime>
#include "iniciarsort.h"

using namespace std;

namespace Ui {
class OrdenSort;
}

class OrdenSort : public QDialog
{
    Q_OBJECT

public:
    QTime QS, MS, BS, BuS, HS;
    IniciarSort* tgmr;
    void generar(int op);
    explicit OrdenSort(QWidget *parent = 0);
    ~OrdenSort();

private slots:
    void on_pushButton_2_clicked();

    void on_BtnQS_clicked();

    void on_BtnMS_clicked();

    void on_BtnBS_clicked();

    void on_BtnBS_2_clicked();

    void on_BtnHS_clicked();

    void on_BtnGenerar_clicked();

private:
    Ui::OrdenSort *ui;
};

#endif // ORDENSORT_H
