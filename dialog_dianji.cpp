#include "dialog_dianji.h"
#include "ui_dialog_dianji.h"

Dialog_dianji::Dialog_dianji(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_dianji)
{
    ui->setupUi(this);

    machinery_1=new ele_machinery();
}

Dialog_dianji::~Dialog_dianji()
{
    delete ui;
}

void Dialog_dianji::on_pushButton_clicked()
{
    //重新获取串口
    QString  dianji_name=machinery_1->on_open();
    ui->lineEdit->setText(dianji_name);

}


void Dialog_dianji::on_buttonBox_accepted()
{
    //退出当前窗口
    ui->~Dialog_dianji();
}
