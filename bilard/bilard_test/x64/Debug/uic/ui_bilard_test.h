/********************************************************************************
** Form generated from reading UI file 'bilard_test.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILARD_TEST_H
#define UI_BILARD_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bilard_testClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *bilard_testClass)
    {
        if (bilard_testClass->objectName().isEmpty())
            bilard_testClass->setObjectName(QString::fromUtf8("bilard_testClass"));
        bilard_testClass->resize(600, 400);
        menuBar = new QMenuBar(bilard_testClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        bilard_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(bilard_testClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        bilard_testClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(bilard_testClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        bilard_testClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(bilard_testClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        bilard_testClass->setStatusBar(statusBar);

        retranslateUi(bilard_testClass);

        QMetaObject::connectSlotsByName(bilard_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *bilard_testClass)
    {
        bilard_testClass->setWindowTitle(QCoreApplication::translate("bilard_testClass", "bilard_test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bilard_testClass: public Ui_bilard_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILARD_TEST_H
