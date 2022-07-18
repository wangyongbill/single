#include "dialog_caijika.h"
#include "ui_dialog_caijika.h"

Dialog_caijika::Dialog_caijika(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_caijika)
{
    ui->setupUi(this);
    caijika_1=new get_measure_thread( );
}

Dialog_caijika::~Dialog_caijika()
{
    delete ui;
}

void Dialog_caijika::on_buttonBox_accepted()
{
    //退出当前窗口
    ui->~Dialog_caijika();
}

void Dialog_caijika::on_pushButton_clicked()
{
    bool if_caijika=caijika_1->on_connection(false);
    if(if_caijika)
    {
        ui->lineEdit->setText("1");
    }
}
