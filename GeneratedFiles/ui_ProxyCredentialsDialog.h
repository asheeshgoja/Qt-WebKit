/********************************************************************************
** Form generated from reading UI file 'ProxyCredentialsDialog.ui'
**
** Created: Tue Mar 8 09:41:16 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROXYCREDENTIALSDIALOG_H
#define UI_PROXYCREDENTIALSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProxyCredentialsDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QPushButton *cancelButton;
    QPushButton *okButton;
    QLineEdit *userName;
    QLineEdit *password;
    QLabel *label_2;
    QLabel *label;
    QLabel *introLabel;

    void setupUi(QDialog *ProxyCredentialsDialog)
    {
        if (ProxyCredentialsDialog->objectName().isEmpty())
            ProxyCredentialsDialog->setObjectName(QString::fromUtf8("ProxyCredentialsDialog"));
        ProxyCredentialsDialog->resize(283, 160);
        layoutWidget = new QWidget(ProxyCredentialsDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 100, 251, 41));
        hboxLayout = new QHBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        userName = new QLineEdit(ProxyCredentialsDialog);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setGeometry(QRect(81, 50, 181, 20));
        password = new QLineEdit(ProxyCredentialsDialog);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(81, 71, 181, 20));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy);
        password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        password->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(ProxyCredentialsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(19, 71, 50, 16));
        label_2->setLayoutDirection(Qt::RightToLeft);
        label = new QLabel(ProxyCredentialsDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(19, 50, 56, 16));
        label->setLayoutDirection(Qt::RightToLeft);
        introLabel = new QLabel(ProxyCredentialsDialog);
        introLabel->setObjectName(QString::fromUtf8("introLabel"));
        introLabel->setGeometry(QRect(20, 0, 308, 47));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(introLabel->sizePolicy().hasHeightForWidth());
        introLabel->setSizePolicy(sizePolicy1);

        retranslateUi(ProxyCredentialsDialog);
        QObject::connect(okButton, SIGNAL(clicked()), ProxyCredentialsDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), ProxyCredentialsDialog, SLOT(reject()));
        QObject::connect(password, SIGNAL(returnPressed()), ProxyCredentialsDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(ProxyCredentialsDialog);
    } // setupUi

    void retranslateUi(QDialog *ProxyCredentialsDialog)
    {
        ProxyCredentialsDialog->setWindowTitle(QApplication::translate("ProxyCredentialsDialog", "UPS Smart Client - Proxy Credentials", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("ProxyCredentialsDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("ProxyCredentialsDialog", "OK", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ProxyCredentialsDialog", "Password:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ProxyCredentialsDialog", "User Name:", 0, QApplication::UnicodeUTF8));
        introLabel->setText(QApplication::translate("ProxyCredentialsDialog", "INTRO TEXT DUMMY", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProxyCredentialsDialog: public Ui_ProxyCredentialsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROXYCREDENTIALSDIALOG_H
