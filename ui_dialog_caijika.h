/********************************************************************************
** Form generated from reading UI file 'dialog_caijika.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CAIJIKA_H
#define UI_DIALOG_CAIJIKA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_caijika
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *Dialog_caijika)
    {
        if (Dialog_caijika->objectName().isEmpty())
            Dialog_caijika->setObjectName(QString::fromUtf8("Dialog_caijika"));
        Dialog_caijika->resize(320, 240);
        buttonBox = new QDialogButtonBox(Dialog_caijika);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(Dialog_caijika);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 90, 93, 28));
        lineEdit = new QLineEdit(Dialog_caijika);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 20, 113, 21));
        label = new QLabel(Dialog_caijika);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 91, 21));

        retranslateUi(Dialog_caijika);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_caijika, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_caijika, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_caijika);
    } // setupUi

    void retranslateUi(QDialog *Dialog_caijika)
    {
        Dialog_caijika->setWindowTitle(QCoreApplication::translate("Dialog_caijika", "\351\207\207\351\233\206\345\215\241", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog_caijika", "\351\207\215\350\277\236", nullptr));
        label->setText(QCoreApplication::translate("Dialog_caijika", "\351\207\207\351\233\206\345\215\241\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_caijika: public Ui_Dialog_caijika {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CAIJIKA_H
