/********************************************************************************
** Form generated from reading UI file 'dialog_dianji.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_DIANJI_H
#define UI_DIALOG_DIANJI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_dianji
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_dianji)
    {
        if (Dialog_dianji->objectName().isEmpty())
            Dialog_dianji->setObjectName(QString::fromUtf8("Dialog_dianji"));
        Dialog_dianji->resize(320, 240);
        buttonBox = new QDialogButtonBox(Dialog_dianji);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Dialog_dianji);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 68, 15));
        lineEdit = new QLineEdit(Dialog_dianji);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 20, 113, 21));
        pushButton = new QPushButton(Dialog_dianji);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 70, 111, 28));

        retranslateUi(Dialog_dianji);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_dianji, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_dianji, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_dianji);
    } // setupUi

    void retranslateUi(QDialog *Dialog_dianji)
    {
        Dialog_dianji->setWindowTitle(QCoreApplication::translate("Dialog_dianji", "\347\224\265\346\234\272", nullptr));
        label->setText(QCoreApplication::translate("Dialog_dianji", "\345\275\223\345\211\215\344\270\262\345\217\243", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog_dianji", "\351\207\215\350\277\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_dianji: public Ui_Dialog_dianji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_DIANJI_H
