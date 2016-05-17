/********************************************************************************
** Form generated from reading UI file 'idchybridcontainer.ui'
**
** Created: Tue Mar 8 09:41:16 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDCHYBRIDCONTAINER_H
#define UI_IDCHYBRIDCONTAINER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IdcHybridContainerClass
{
public:
    QAction *actionRead;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IdcHybridContainerClass)
    {
        if (IdcHybridContainerClass->objectName().isEmpty())
            IdcHybridContainerClass->setObjectName(QString::fromUtf8("IdcHybridContainerClass"));
        IdcHybridContainerClass->resize(600, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ups_smart_client.ico"), QSize(), QIcon::Normal, QIcon::Off);
        IdcHybridContainerClass->setWindowIcon(icon);
        actionRead = new QAction(IdcHybridContainerClass);
        actionRead->setObjectName(QString::fromUtf8("actionRead"));
        centralWidget = new QWidget(IdcHybridContainerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        IdcHybridContainerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(IdcHybridContainerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        IdcHybridContainerClass->setStatusBar(statusBar);

        retranslateUi(IdcHybridContainerClass);

        QMetaObject::connectSlotsByName(IdcHybridContainerClass);
    } // setupUi

    void retranslateUi(QMainWindow *IdcHybridContainerClass)
    {
        IdcHybridContainerClass->setWindowTitle(QApplication::translate("IdcHybridContainerClass", "IdcHybridContainer", 0, QApplication::UnicodeUTF8));
        actionRead->setText(QApplication::translate("IdcHybridContainerClass", "Read", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IdcHybridContainerClass: public Ui_IdcHybridContainerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDCHYBRIDCONTAINER_H
