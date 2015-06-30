/********************************************************************************
** Form generated from reading UI file 'graficar.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFICAR_H
#define UI_GRAFICAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Graficar
{
public:
    QGraphicsView *VistaGrafo;
    QLineEdit *EditValorVer;
    QLabel *LabelValor;
    QPushButton *BtnAgregarVer;
    QLabel *LabelCosto;
    QLineEdit *EditCosto;
    QLineEdit *EditOrigen;
    QLabel *LabelOrigen;
    QLineEdit *EditDestino;
    QLabel *LabelDestino;
    QPushButton *BtnAgregarArista;
    QLineEdit *EditDestinoBo;
    QPushButton *BtnBorrarArista;
    QLabel *LabelOrigenBo;
    QPushButton *BtnBorrarVertice;
    QLineEdit *EditOrigenBo;
    QLabel *LabelDestinoBo;
    QLabel *LabelVerticeBo;
    QLineEdit *EditVerticeBo;
    QLabel *LabelTipo;
    QComboBox *CmbOrigen;
    QLabel *LabelCrearGrafo;
    QLabel *LabelEliminarGrafo;

    void setupUi(QDialog *Graficar)
    {
        if (Graficar->objectName().isEmpty())
            Graficar->setObjectName(QStringLiteral("Graficar"));
        Graficar->resize(1174, 660);
        VistaGrafo = new QGraphicsView(Graficar);
        VistaGrafo->setObjectName(QStringLiteral("VistaGrafo"));
        VistaGrafo->setGeometry(QRect(20, 10, 881, 631));
        EditValorVer = new QLineEdit(Graficar);
        EditValorVer->setObjectName(QStringLiteral("EditValorVer"));
        EditValorVer->setGeometry(QRect(950, 80, 113, 20));
        LabelValor = new QLabel(Graficar);
        LabelValor->setObjectName(QStringLiteral("LabelValor"));
        LabelValor->setGeometry(QRect(910, 80, 47, 13));
        BtnAgregarVer = new QPushButton(Graficar);
        BtnAgregarVer->setObjectName(QStringLiteral("BtnAgregarVer"));
        BtnAgregarVer->setGeometry(QRect(1070, 80, 91, 23));
        LabelCosto = new QLabel(Graficar);
        LabelCosto->setObjectName(QStringLiteral("LabelCosto"));
        LabelCosto->setGeometry(QRect(910, 110, 47, 13));
        EditCosto = new QLineEdit(Graficar);
        EditCosto->setObjectName(QStringLiteral("EditCosto"));
        EditCosto->setGeometry(QRect(950, 110, 113, 20));
        EditOrigen = new QLineEdit(Graficar);
        EditOrigen->setObjectName(QStringLiteral("EditOrigen"));
        EditOrigen->setGeometry(QRect(950, 140, 113, 20));
        LabelOrigen = new QLabel(Graficar);
        LabelOrigen->setObjectName(QStringLiteral("LabelOrigen"));
        LabelOrigen->setGeometry(QRect(910, 140, 47, 13));
        EditDestino = new QLineEdit(Graficar);
        EditDestino->setObjectName(QStringLiteral("EditDestino"));
        EditDestino->setGeometry(QRect(950, 170, 113, 20));
        LabelDestino = new QLabel(Graficar);
        LabelDestino->setObjectName(QStringLiteral("LabelDestino"));
        LabelDestino->setGeometry(QRect(910, 170, 47, 13));
        BtnAgregarArista = new QPushButton(Graficar);
        BtnAgregarArista->setObjectName(QStringLiteral("BtnAgregarArista"));
        BtnAgregarArista->setGeometry(QRect(1070, 110, 91, 81));
        EditDestinoBo = new QLineEdit(Graficar);
        EditDestinoBo->setObjectName(QStringLiteral("EditDestinoBo"));
        EditDestinoBo->setGeometry(QRect(950, 390, 113, 20));
        BtnBorrarArista = new QPushButton(Graficar);
        BtnBorrarArista->setObjectName(QStringLiteral("BtnBorrarArista"));
        BtnBorrarArista->setGeometry(QRect(1070, 350, 91, 81));
        LabelOrigenBo = new QLabel(Graficar);
        LabelOrigenBo->setObjectName(QStringLiteral("LabelOrigenBo"));
        LabelOrigenBo->setGeometry(QRect(910, 360, 47, 13));
        BtnBorrarVertice = new QPushButton(Graficar);
        BtnBorrarVertice->setObjectName(QStringLiteral("BtnBorrarVertice"));
        BtnBorrarVertice->setGeometry(QRect(1070, 320, 91, 23));
        EditOrigenBo = new QLineEdit(Graficar);
        EditOrigenBo->setObjectName(QStringLiteral("EditOrigenBo"));
        EditOrigenBo->setGeometry(QRect(950, 360, 113, 20));
        LabelDestinoBo = new QLabel(Graficar);
        LabelDestinoBo->setObjectName(QStringLiteral("LabelDestinoBo"));
        LabelDestinoBo->setGeometry(QRect(910, 390, 47, 13));
        LabelVerticeBo = new QLabel(Graficar);
        LabelVerticeBo->setObjectName(QStringLiteral("LabelVerticeBo"));
        LabelVerticeBo->setGeometry(QRect(910, 320, 47, 13));
        EditVerticeBo = new QLineEdit(Graficar);
        EditVerticeBo->setObjectName(QStringLiteral("EditVerticeBo"));
        EditVerticeBo->setGeometry(QRect(950, 320, 113, 20));
        LabelTipo = new QLabel(Graficar);
        LabelTipo->setObjectName(QStringLiteral("LabelTipo"));
        LabelTipo->setGeometry(QRect(910, 240, 47, 13));
        CmbOrigen = new QComboBox(Graficar);
        CmbOrigen->setObjectName(QStringLiteral("CmbOrigen"));
        CmbOrigen->setGeometry(QRect(950, 240, 211, 22));
        LabelCrearGrafo = new QLabel(Graficar);
        LabelCrearGrafo->setObjectName(QStringLiteral("LabelCrearGrafo"));
        LabelCrearGrafo->setGeometry(QRect(1010, 30, 61, 16));
        LabelEliminarGrafo = new QLabel(Graficar);
        LabelEliminarGrafo->setObjectName(QStringLiteral("LabelEliminarGrafo"));
        LabelEliminarGrafo->setGeometry(QRect(1010, 280, 71, 16));

        retranslateUi(Graficar);

        QMetaObject::connectSlotsByName(Graficar);
    } // setupUi

    void retranslateUi(QDialog *Graficar)
    {
        Graficar->setWindowTitle(QApplication::translate("Graficar", "Dialog", 0));
        EditValorVer->setText(QString());
        LabelValor->setText(QApplication::translate("Graficar", "Valor:", 0));
        BtnAgregarVer->setText(QApplication::translate("Graficar", "Agregar Vertice", 0));
        LabelCosto->setText(QApplication::translate("Graficar", "Costo:", 0));
        EditCosto->setText(QString());
        EditOrigen->setText(QString());
        LabelOrigen->setText(QApplication::translate("Graficar", "Origen:", 0));
        EditDestino->setText(QString());
        LabelDestino->setText(QApplication::translate("Graficar", "Destino:", 0));
        BtnAgregarArista->setText(QApplication::translate("Graficar", "Agregar Arista", 0));
        EditDestinoBo->setText(QString());
        BtnBorrarArista->setText(QApplication::translate("Graficar", "Borrar Arista", 0));
        LabelOrigenBo->setText(QApplication::translate("Graficar", "Origen:", 0));
        BtnBorrarVertice->setText(QApplication::translate("Graficar", "Borrar Vertice", 0));
        EditOrigenBo->setText(QString());
        LabelDestinoBo->setText(QApplication::translate("Graficar", "Destino:", 0));
        LabelVerticeBo->setText(QApplication::translate("Graficar", "Vertice:", 0));
        EditVerticeBo->setText(QString());
        LabelTipo->setText(QApplication::translate("Graficar", "Tipo:", 0));
        LabelCrearGrafo->setText(QApplication::translate("Graficar", "Crear Grafo", 0));
        LabelEliminarGrafo->setText(QApplication::translate("Graficar", "Eliminar Grafo", 0));
    } // retranslateUi

};

namespace Ui {
    class Graficar: public Ui_Graficar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFICAR_H
