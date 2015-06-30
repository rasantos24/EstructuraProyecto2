/********************************************************************************
** Form generated from reading UI file 'ordensort.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDENSORT_H
#define UI_ORDENSORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OrdenSort
{
public:
    QListWidget *ListaDesOrd;
    QPushButton *BtnQS;
    QPushButton *BtnMS;
    QPushButton *BtnBS;
    QPushButton *BtnBS_2;
    QPushButton *BtnHS;
    QLineEdit *EditBubble;
    QLineEdit *EditHS;
    QLineEdit *EditBinSort;
    QLineEdit *EditMS;
    QLineEdit *EditQS;
    QLabel *LabelDesOr;
    QListWidget *ListaQS;
    QLabel *LabelTiempo;
    QListWidget *ListaMS;
    QListWidget *ListaBubble;
    QListWidget *ListaBinSort;
    QListWidget *ListaHS;
    QLabel *LabelOrden;

    void setupUi(QDialog *OrdenSort)
    {
        if (OrdenSort->objectName().isEmpty())
            OrdenSort->setObjectName(QStringLiteral("OrdenSort"));
        OrdenSort->resize(698, 586);
        ListaDesOrd = new QListWidget(OrdenSort);
        ListaDesOrd->setObjectName(QStringLiteral("ListaDesOrd"));
        ListaDesOrd->setGeometry(QRect(20, 30, 91, 511));
        BtnQS = new QPushButton(OrdenSort);
        BtnQS->setObjectName(QStringLiteral("BtnQS"));
        BtnQS->setGeometry(QRect(150, 480, 75, 23));
        BtnMS = new QPushButton(OrdenSort);
        BtnMS->setObjectName(QStringLiteral("BtnMS"));
        BtnMS->setGeometry(QRect(260, 480, 75, 23));
        BtnBS = new QPushButton(OrdenSort);
        BtnBS->setObjectName(QStringLiteral("BtnBS"));
        BtnBS->setGeometry(QRect(370, 480, 75, 23));
        BtnBS_2 = new QPushButton(OrdenSort);
        BtnBS_2->setObjectName(QStringLiteral("BtnBS_2"));
        BtnBS_2->setGeometry(QRect(480, 480, 75, 23));
        BtnHS = new QPushButton(OrdenSort);
        BtnHS->setObjectName(QStringLiteral("BtnHS"));
        BtnHS->setGeometry(QRect(590, 480, 75, 23));
        EditBubble = new QLineEdit(OrdenSort);
        EditBubble->setObjectName(QStringLiteral("EditBubble"));
        EditBubble->setGeometry(QRect(250, 520, 91, 20));
        EditHS = new QLineEdit(OrdenSort);
        EditHS->setObjectName(QStringLiteral("EditHS"));
        EditHS->setGeometry(QRect(470, 520, 91, 20));
        EditBinSort = new QLineEdit(OrdenSort);
        EditBinSort->setObjectName(QStringLiteral("EditBinSort"));
        EditBinSort->setGeometry(QRect(360, 520, 91, 20));
        EditMS = new QLineEdit(OrdenSort);
        EditMS->setObjectName(QStringLiteral("EditMS"));
        EditMS->setGeometry(QRect(140, 520, 91, 20));
        EditQS = new QLineEdit(OrdenSort);
        EditQS->setObjectName(QStringLiteral("EditQS"));
        EditQS->setGeometry(QRect(580, 520, 91, 20));
        LabelDesOr = new QLabel(OrdenSort);
        LabelDesOr->setObjectName(QStringLiteral("LabelDesOr"));
        LabelDesOr->setGeometry(QRect(30, 10, 71, 16));
        ListaQS = new QListWidget(OrdenSort);
        ListaQS->setObjectName(QStringLiteral("ListaQS"));
        ListaQS->setGeometry(QRect(580, 30, 91, 431));
        LabelTiempo = new QLabel(OrdenSort);
        LabelTiempo->setObjectName(QStringLiteral("LabelTiempo"));
        LabelTiempo->setGeometry(QRect(380, 550, 47, 13));
        ListaMS = new QListWidget(OrdenSort);
        ListaMS->setObjectName(QStringLiteral("ListaMS"));
        ListaMS->setGeometry(QRect(140, 30, 91, 431));
        ListaBubble = new QListWidget(OrdenSort);
        ListaBubble->setObjectName(QStringLiteral("ListaBubble"));
        ListaBubble->setGeometry(QRect(250, 30, 91, 431));
        ListaBinSort = new QListWidget(OrdenSort);
        ListaBinSort->setObjectName(QStringLiteral("ListaBinSort"));
        ListaBinSort->setGeometry(QRect(360, 30, 91, 431));
        ListaHS = new QListWidget(OrdenSort);
        ListaHS->setObjectName(QStringLiteral("ListaHS"));
        ListaHS->setGeometry(QRect(470, 30, 91, 431));
        LabelOrden = new QLabel(OrdenSort);
        LabelOrden->setObjectName(QStringLiteral("LabelOrden"));
        LabelOrden->setGeometry(QRect(380, 10, 61, 16));

        retranslateUi(OrdenSort);

        QMetaObject::connectSlotsByName(OrdenSort);
    } // setupUi

    void retranslateUi(QDialog *OrdenSort)
    {
        OrdenSort->setWindowTitle(QApplication::translate("OrdenSort", "Dialog", 0));
        BtnQS->setText(QApplication::translate("OrdenSort", "QuickSort", 0));
        BtnMS->setText(QApplication::translate("OrdenSort", "MergeSort", 0));
        BtnBS->setText(QApplication::translate("OrdenSort", "BubbleSort", 0));
        BtnBS_2->setText(QApplication::translate("OrdenSort", "BinSort", 0));
        BtnHS->setText(QApplication::translate("OrdenSort", "HeapSort", 0));
        LabelDesOr->setText(QApplication::translate("OrdenSort", "Desordenados", 0));
        LabelTiempo->setText(QApplication::translate("OrdenSort", "Tiempos", 0));
        LabelOrden->setText(QApplication::translate("OrdenSort", "Ordenados", 0));
    } // retranslateUi

};

namespace Ui {
    class OrdenSort: public Ui_OrdenSort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDENSORT_H
