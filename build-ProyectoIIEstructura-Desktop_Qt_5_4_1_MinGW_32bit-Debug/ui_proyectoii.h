/********************************************************************************
** Form generated from reading UI file 'proyectoii.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROYECTOII_H
#define UI_PROYECTOII_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProyectoII
{
public:
    QWidget *centralWidget;
    QLabel *Titulo;
    QPushButton *Grafos;
    QPushButton *Sorts;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProyectoII)
    {
        if (ProyectoII->objectName().isEmpty())
            ProyectoII->setObjectName(QStringLiteral("ProyectoII"));
        ProyectoII->resize(400, 300);
        centralWidget = new QWidget(ProyectoII);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Titulo = new QLabel(centralWidget);
        Titulo->setObjectName(QStringLiteral("Titulo"));
        Titulo->setGeometry(QRect(120, 40, 161, 16));
        Grafos = new QPushButton(centralWidget);
        Grafos->setObjectName(QStringLiteral("Grafos"));
        Grafos->setGeometry(QRect(160, 80, 75, 23));
        Sorts = new QPushButton(centralWidget);
        Sorts->setObjectName(QStringLiteral("Sorts"));
        Sorts->setGeometry(QRect(160, 120, 75, 23));
        ProyectoII->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProyectoII);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        ProyectoII->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProyectoII);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProyectoII->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProyectoII);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProyectoII->setStatusBar(statusBar);

        retranslateUi(ProyectoII);

        QMetaObject::connectSlotsByName(ProyectoII);
    } // setupUi

    void retranslateUi(QMainWindow *ProyectoII)
    {
        ProyectoII->setWindowTitle(QApplication::translate("ProyectoII", "ProyectoII", 0));
        Titulo->setText(QApplication::translate("ProyectoII", "Proyecto II Estructura de Datos", 0));
        Grafos->setText(QApplication::translate("ProyectoII", "Parte 1", 0));
        Sorts->setText(QApplication::translate("ProyectoII", "Parte 2", 0));
    } // retranslateUi

};

namespace Ui {
    class ProyectoII: public Ui_ProyectoII {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROYECTOII_H
