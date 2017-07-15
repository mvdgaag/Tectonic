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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TectonicClass
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionSelect_All;
    QAction *actionMinimize;
    QAction *actionAbout;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSelectBrush;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QFrame *renderframe;
    QFrame *attributeframe;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TectonicClass)
    {
        if (TectonicClass->objectName().isEmpty())
            TectonicClass->setObjectName(QStringLiteral("TectonicClass"));
        TectonicClass->resize(1079, 671);
        actionNew = new QAction(TectonicClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(TectonicClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(TectonicClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(TectonicClass);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionClose = new QAction(TectonicClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionCut = new QAction(TectonicClass);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCopy = new QAction(TectonicClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(TectonicClass);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionDelete = new QAction(TectonicClass);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionSelect_All = new QAction(TectonicClass);
        actionSelect_All->setObjectName(QStringLiteral("actionSelect_All"));
        actionMinimize = new QAction(TectonicClass);
        actionMinimize->setObjectName(QStringLiteral("actionMinimize"));
        actionAbout = new QAction(TectonicClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionUndo = new QAction(TectonicClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(TectonicClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionSelectBrush = new QAction(TectonicClass);
        actionSelectBrush->setObjectName(QStringLiteral("actionSelectBrush"));
        actionSelectBrush->setCheckable(true);
        centralWidget = new QWidget(TectonicClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        renderframe = new QFrame(splitter);
        renderframe->setObjectName(QStringLiteral("renderframe"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(renderframe->sizePolicy().hasHeightForWidth());
        renderframe->setSizePolicy(sizePolicy1);
        renderframe->setMinimumSize(QSize(400, 400));
        renderframe->setMaximumSize(QSize(1920, 1080));
        renderframe->setBaseSize(QSize(400, 400));
        renderframe->setFrameShape(QFrame::Box);
        renderframe->setFrameShadow(QFrame::Raised);
        renderframe->setLineWidth(2);
        splitter->addWidget(renderframe);
        attributeframe = new QFrame(splitter);
        attributeframe->setObjectName(QStringLiteral("attributeframe"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(attributeframe->sizePolicy().hasHeightForWidth());
        attributeframe->setSizePolicy(sizePolicy2);
        attributeframe->setMinimumSize(QSize(250, 20));
        attributeframe->setLayoutDirection(Qt::LeftToRight);
        attributeframe->setFrameShape(QFrame::Box);
        attributeframe->setFrameShadow(QFrame::Raised);
        attributeframe->setLineWidth(2);
        verticalLayout_2 = new QVBoxLayout(attributeframe);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(attributeframe);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label);

        pushButton = new QPushButton(attributeframe);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        splitter->addWidget(attributeframe);

        horizontalLayout->addWidget(splitter);

        TectonicClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TectonicClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1079, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        TectonicClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TectonicClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TectonicClass->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TectonicClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TectonicClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionSelect_All);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuWindow->addAction(actionMinimize);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionSelectBrush);

        retranslateUi(TectonicClass);

        QMetaObject::connectSlotsByName(TectonicClass);
    } // setupUi

    void retranslateUi(QMainWindow *TectonicClass)
    {
        TectonicClass->setWindowTitle(QApplication::translate("TectonicClass", "Tectonic", Q_NULLPTR));
        actionNew->setText(QApplication::translate("TectonicClass", "New", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("TectonicClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("TectonicClass", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("TectonicClass", "Save As", Q_NULLPTR));
        actionClose->setText(QApplication::translate("TectonicClass", "Close", Q_NULLPTR));
        actionCut->setText(QApplication::translate("TectonicClass", "Cut", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("TectonicClass", "Copy", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("TectonicClass", "Paste", Q_NULLPTR));
        actionDelete->setText(QApplication::translate("TectonicClass", "Delete", Q_NULLPTR));
        actionSelect_All->setText(QApplication::translate("TectonicClass", "Select All", Q_NULLPTR));
        actionMinimize->setText(QApplication::translate("TectonicClass", "Minimize", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("TectonicClass", "About", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("TectonicClass", "Undo", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("TectonicClass", "Redo", Q_NULLPTR));
        actionSelectBrush->setText(QApplication::translate("TectonicClass", "SelectBrush", Q_NULLPTR));
        actionSelectBrush->setIconText(QApplication::translate("TectonicClass", "Brush", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSelectBrush->setToolTip(QApplication::translate("TectonicClass", "select the brush tool", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("TectonicClass", "Attributes", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TectonicClass", "Blabla", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("TectonicClass", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("TectonicClass", "Edit", Q_NULLPTR));
        menuWindow->setTitle(QApplication::translate("TectonicClass", "Window", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("TectonicClass", "Help", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class TectonicClass: public Ui_TectonicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TECTONIC_H
