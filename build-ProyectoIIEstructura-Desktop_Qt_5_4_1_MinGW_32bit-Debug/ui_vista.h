/********************************************************************************
** Form generated from reading UI file 'vista.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISTA_H
#define UI_VISTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Vista
{
public:
    QGraphicsView *Vista_2;
    QPushButton *BtnSalir;

    void setupUi(QDialog *Vista)
    {
        if (Vista->objectName().isEmpty())
            Vista->setObjectName(QStringLiteral("Vista"));
        Vista->resize(910, 684);
        Vista_2 = new QGraphicsView(Vista);
        Vista_2->setObjectName(QStringLiteral("Vista_2"));
        Vista_2->setGeometry(QRect(10, 10, 881, 521));
        BtnSalir = new QPushButton(Vista);
        BtnSalir->setObjectName(QStringLiteral("BtnSalir"));
        BtnSalir->setGeometry(QRect(370, 560, 161, 61));

        retranslateUi(Vista);

        QMetaObject::connectSlotsByName(Vista);
    } // setupUi

    void retranslateUi(QDialog *Vista)
    {
        Vista->setWindowTitle(QApplication::translate("Vista", "Dialog", 0));
        BtnSalir->setText(QApplication::translate("Vista", "Salir", 0));
    } // retranslateUi

};

namespace Ui {
    class Vista: public Ui_Vista {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISTA_H
