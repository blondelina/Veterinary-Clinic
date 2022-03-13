/********************************************************************************
** Form generated from reading UI file 'Qt_Project2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_PROJECT2_H
#define UI_QT_PROJECT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_Project2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt_Project2Class)
    {
        if (Qt_Project2Class->objectName().isEmpty())
            Qt_Project2Class->setObjectName(QString::fromUtf8("Qt_Project2Class"));
        Qt_Project2Class->resize(600, 400);
        menuBar = new QMenuBar(Qt_Project2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Qt_Project2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt_Project2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Qt_Project2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Qt_Project2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Qt_Project2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Qt_Project2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Qt_Project2Class->setStatusBar(statusBar);

        retranslateUi(Qt_Project2Class);

        QMetaObject::connectSlotsByName(Qt_Project2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_Project2Class)
    {
        Qt_Project2Class->setWindowTitle(QCoreApplication::translate("Qt_Project2Class", "Qt_Project2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_Project2Class: public Ui_Qt_Project2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_PROJECT2_H
