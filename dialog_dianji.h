#ifndef DIALOG_DIANJI_H
#define DIALOG_DIANJI_H

#include <QDialog>
#include "ele_machinery.h"

namespace Ui {
class Dialog_dianji;
}

class Dialog_dianji : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_dianji(QWidget *parent = nullptr);
    ~Dialog_dianji();
    ele_machinery* machinery_1;//电机

private slots:
    void on_pushButton_clicked();



    void on_buttonBox_accepted();

public:

    Ui::Dialog_dianji *ui;
};

#endif // DIALOG_DIANJI_H
