/********************************************************************************
** Form generated from reading UI file 'myplot.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPLOT_H
#define UI_MYPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Myplot
{
public:

    void setupUi(QWidget *Myplot)
    {
        if (Myplot->objectName().isEmpty())
            Myplot->setObjectName(QString::fromUtf8("Myplot"));
        Myplot->resize(320, 240);

        retranslateUi(Myplot);

        QMetaObject::connectSlotsByName(Myplot);
    } // setupUi

    void retranslateUi(QWidget *Myplot)
    {
        Myplot->setWindowTitle(QCoreApplication::translate("Myplot", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Myplot: public Ui_Myplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPLOT_H
