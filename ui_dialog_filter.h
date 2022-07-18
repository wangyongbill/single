/********************************************************************************
** Form generated from reading UI file 'dialog_filter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FILTER_H
#define UI_DIALOG_FILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_filter
{
public:
    QPushButton *design_filter_pushButton;
    QLineEdit *up_dB_lineEdit;
    QLineEdit *down_dB_lineEdit;
    QLabel *down_weight_label;
    QLabel *dB1_label;
    QLabel *up_weight_label;
    QLabel *dB2_label;
    QLineEdit *edge2_lineEdit;
    QLabel *down_edge_label;
    QLineEdit *edge1_lineEdit;
    QLabel *up_edge_label;
    QComboBox *edge2_Hz_Box;
    QComboBox *edge1_Hz_Box;
    QLabel *design_label;
    QComboBox *design_Box;
    QLabel *response_label;
    QComboBox *respone_Box;

    void setupUi(QDialog *Dialog_filter)
    {
        if (Dialog_filter->objectName().isEmpty())
            Dialog_filter->setObjectName(QString::fromUtf8("Dialog_filter"));
        Dialog_filter->resize(845, 608);
        design_filter_pushButton = new QPushButton(Dialog_filter);
        design_filter_pushButton->setObjectName(QString::fromUtf8("design_filter_pushButton"));
        design_filter_pushButton->setGeometry(QRect(350, 570, 94, 28));
        design_filter_pushButton->setCheckable(false);
        up_dB_lineEdit = new QLineEdit(Dialog_filter);
        up_dB_lineEdit->setObjectName(QString::fromUtf8("up_dB_lineEdit"));
        up_dB_lineEdit->setGeometry(QRect(445, 505, 171, 21));
        down_dB_lineEdit = new QLineEdit(Dialog_filter);
        down_dB_lineEdit->setObjectName(QString::fromUtf8("down_dB_lineEdit"));
        down_dB_lineEdit->setGeometry(QRect(445, 532, 171, 21));
        down_weight_label = new QLabel(Dialog_filter);
        down_weight_label->setObjectName(QString::fromUtf8("down_weight_label"));
        down_weight_label->setGeometry(QRect(378, 532, 61, 20));
        dB1_label = new QLabel(Dialog_filter);
        dB1_label->setObjectName(QString::fromUtf8("dB1_label"));
        dB1_label->setGeometry(QRect(622, 505, 16, 16));
        up_weight_label = new QLabel(Dialog_filter);
        up_weight_label->setObjectName(QString::fromUtf8("up_weight_label"));
        up_weight_label->setGeometry(QRect(378, 505, 61, 20));
        dB2_label = new QLabel(Dialog_filter);
        dB2_label->setObjectName(QString::fromUtf8("dB2_label"));
        dB2_label->setGeometry(QRect(622, 532, 16, 16));
        edge2_lineEdit = new QLineEdit(Dialog_filter);
        edge2_lineEdit->setObjectName(QString::fromUtf8("edge2_lineEdit"));
        edge2_lineEdit->setGeometry(QRect(113, 532, 171, 21));
        down_edge_label = new QLabel(Dialog_filter);
        down_edge_label->setObjectName(QString::fromUtf8("down_edge_label"));
        down_edge_label->setGeometry(QRect(39, 532, 68, 16));
        edge1_lineEdit = new QLineEdit(Dialog_filter);
        edge1_lineEdit->setObjectName(QString::fromUtf8("edge1_lineEdit"));
        edge1_lineEdit->setGeometry(QRect(113, 505, 171, 21));
        up_edge_label = new QLabel(Dialog_filter);
        up_edge_label->setObjectName(QString::fromUtf8("up_edge_label"));
        up_edge_label->setGeometry(QRect(39, 505, 68, 16));
        edge2_Hz_Box = new QComboBox(Dialog_filter);
        edge2_Hz_Box->addItem(QString());
        edge2_Hz_Box->addItem(QString());
        edge2_Hz_Box->addItem(QString());
        edge2_Hz_Box->setObjectName(QString::fromUtf8("edge2_Hz_Box"));
        edge2_Hz_Box->setGeometry(QRect(290, 532, 52, 21));
        edge1_Hz_Box = new QComboBox(Dialog_filter);
        edge1_Hz_Box->addItem(QString());
        edge1_Hz_Box->addItem(QString());
        edge1_Hz_Box->addItem(QString());
        edge1_Hz_Box->setObjectName(QString::fromUtf8("edge1_Hz_Box"));
        edge1_Hz_Box->setGeometry(QRect(290, 505, 51, 21));
        design_label = new QLabel(Dialog_filter);
        design_label->setObjectName(QString::fromUtf8("design_label"));
        design_label->setGeometry(QRect(44, 468, 60, 16));
        design_Box = new QComboBox(Dialog_filter);
        design_Box->addItem(QString());
        design_Box->addItem(QString());
        design_Box->setObjectName(QString::fromUtf8("design_Box"));
        design_Box->setGeometry(QRect(110, 468, 87, 21));
        response_label = new QLabel(Dialog_filter);
        response_label->setObjectName(QString::fromUtf8("response_label"));
        response_label->setGeometry(QRect(44, 441, 60, 16));
        respone_Box = new QComboBox(Dialog_filter);
        respone_Box->addItem(QString());
        respone_Box->addItem(QString());
        respone_Box->setObjectName(QString::fromUtf8("respone_Box"));
        respone_Box->setGeometry(QRect(110, 441, 87, 21));

        retranslateUi(Dialog_filter);

        QMetaObject::connectSlotsByName(Dialog_filter);
    } // setupUi

    void retranslateUi(QDialog *Dialog_filter)
    {
        Dialog_filter->setWindowTitle(QCoreApplication::translate("Dialog_filter", "Dialog", nullptr));
        design_filter_pushButton->setText(QCoreApplication::translate("Dialog_filter", "\347\224\237\346\210\220\346\273\244\346\263\242\345\231\250", nullptr));
        down_weight_label->setText(QCoreApplication::translate("Dialog_filter", "\351\230\273\345\270\246\350\241\260\345\207\217", nullptr));
        dB1_label->setText(QCoreApplication::translate("Dialog_filter", "dB", nullptr));
        up_weight_label->setText(QCoreApplication::translate("Dialog_filter", "\351\200\232\351\201\223\346\263\242\345\212\250", nullptr));
        dB2_label->setText(QCoreApplication::translate("Dialog_filter", "dB", nullptr));
        down_edge_label->setText(QCoreApplication::translate("Dialog_filter", "\350\276\271\347\274\230\351\242\221\347\216\2072", nullptr));
        up_edge_label->setText(QCoreApplication::translate("Dialog_filter", "\350\276\271\347\274\230\351\242\221\347\216\2071", nullptr));
        edge2_Hz_Box->setItemText(0, QCoreApplication::translate("Dialog_filter", "Hz", nullptr));
        edge2_Hz_Box->setItemText(1, QCoreApplication::translate("Dialog_filter", "KHz", nullptr));
        edge2_Hz_Box->setItemText(2, QCoreApplication::translate("Dialog_filter", "MHz", nullptr));

        edge1_Hz_Box->setItemText(0, QCoreApplication::translate("Dialog_filter", "Hz", nullptr));
        edge1_Hz_Box->setItemText(1, QCoreApplication::translate("Dialog_filter", "KHz", nullptr));
        edge1_Hz_Box->setItemText(2, QCoreApplication::translate("Dialog_filter", "MHz", nullptr));

        design_label->setText(QCoreApplication::translate("Dialog_filter", "\350\256\276\350\256\241\346\226\271\346\263\225", nullptr));
        design_Box->setItemText(0, QCoreApplication::translate("Dialog_filter", "fir", nullptr));
        design_Box->setItemText(1, QCoreApplication::translate("Dialog_filter", "iir", nullptr));

        response_label->setText(QCoreApplication::translate("Dialog_filter", "\345\223\215\345\272\224\347\261\273\345\236\213", nullptr));
        respone_Box->setItemText(0, QCoreApplication::translate("Dialog_filter", "\344\275\216\351\200\232\346\273\244\346\263\242\345\231\250", nullptr));
        respone_Box->setItemText(1, QCoreApplication::translate("Dialog_filter", "\351\253\230\351\200\232\346\273\244\346\263\242\345\231\250", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Dialog_filter: public Ui_Dialog_filter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FILTER_H
