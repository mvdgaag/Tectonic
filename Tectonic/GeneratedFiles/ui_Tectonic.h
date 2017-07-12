/********************************************************************************
** Form generated from reading UI file 'Tectonic.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TECTONIC_H
#define UI_TECTONIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TectonicClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TectonicClass)
    {
        if (TectonicClass->objectName().isEmpty())
            TectonicClass->setObjectName(QStringLiteral("TectonicClass"));
        TectonicClass->resize(600, 400);
        menuBar = new QMenuBar(TectonicClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TectonicClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TectonicClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TectonicClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TectonicClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TectonicClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TectonicClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TectonicClass->setStatusBar(statusBar);

        retranslateUi(TectonicClass);

        QMetaObject::connectSlotsByName(TectonicClass);
    } // setupUi

    void retranslateUi(QMainWindow *TectonicClass)
    {
        TectonicClass->setWindowTitle(QApplication::translate("TectonicClass", "Tectonic", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TectonicClass: public Ui_TectonicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TECTONIC_H
