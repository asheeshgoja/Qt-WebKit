/********************************************************************************
** Form generated from reading UI file 'networkaccessviewer.ui'
**
** Created: Tue Mar 8 09:41:16 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKACCESSVIEWER_H
#define UI_NETWORKACCESSVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkAccessViewer
{
public:
    QTreeWidget *responseDetails;
    QTreeWidget *requestDetails;
    QLabel *label_2;
    QLabel *label;
    QTreeWidget *requestList;
    QPushButton *clearButton;
    QLabel *label_3;
    QPlainTextEdit *textEditResponseData;

    void setupUi(QWidget *NetworkAccessViewer)
    {
        if (NetworkAccessViewer->objectName().isEmpty())
            NetworkAccessViewer->setObjectName(QString::fromUtf8("NetworkAccessViewer"));
        NetworkAccessViewer->resize(912, 534);
        responseDetails = new QTreeWidget(NetworkAccessViewer);
        responseDetails->setObjectName(QString::fromUtf8("responseDetails"));
        responseDetails->setGeometry(QRect(360, 281, 256, 217));
        requestDetails = new QTreeWidget(NetworkAccessViewer);
        requestDetails->setObjectName(QString::fromUtf8("requestDetails"));
        requestDetails->setGeometry(QRect(13, 281, 341, 217));
        label_2 = new QLabel(NetworkAccessViewer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(13, 262, 341, 13));
        label = new QLabel(NetworkAccessViewer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(13, 10, 341, 23));
        requestList = new QTreeWidget(NetworkAccessViewer);
        requestList->setObjectName(QString::fromUtf8("requestList"));
        requestList->setGeometry(QRect(13, 39, 891, 217));
        requestList->setAlternatingRowColors(true);
        requestList->setRootIsDecorated(false);
        clearButton = new QPushButton(NetworkAccessViewer);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(491, 10, 125, 23));
        label_3 = new QLabel(NetworkAccessViewer);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(360, 262, 125, 13));
        textEditResponseData = new QPlainTextEdit(NetworkAccessViewer);
        textEditResponseData->setObjectName(QString::fromUtf8("textEditResponseData"));
        textEditResponseData->setGeometry(QRect(620, 280, 281, 221));

        retranslateUi(NetworkAccessViewer);

        QMetaObject::connectSlotsByName(NetworkAccessViewer);
    } // setupUi

    void retranslateUi(QWidget *NetworkAccessViewer)
    {
        NetworkAccessViewer->setWindowTitle(QApplication::translate("NetworkAccessViewer", "NetworkAccessViewer", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = responseDetails->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("NetworkAccessViewer", "Value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("NetworkAccessViewer", "Name", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = requestDetails->headerItem();
        ___qtreewidgetitem1->setText(1, QApplication::translate("NetworkAccessViewer", "Value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("NetworkAccessViewer", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NetworkAccessViewer", "Request Details", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NetworkAccessViewer", "Network Requests", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = requestList->headerItem();
        ___qtreewidgetitem2->setText(5, QApplication::translate("NetworkAccessViewer", "Info", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(4, QApplication::translate("NetworkAccessViewer", "Content Type", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(3, QApplication::translate("NetworkAccessViewer", "Length", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(2, QApplication::translate("NetworkAccessViewer", "Response", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(1, QApplication::translate("NetworkAccessViewer", "URL", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("NetworkAccessViewer", "Method", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("NetworkAccessViewer", "&Clear", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NetworkAccessViewer", "Response Details", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NetworkAccessViewer: public Ui_NetworkAccessViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKACCESSVIEWER_H
