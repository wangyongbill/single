#include "dialog_filter.h"
#include "ui_dialog_filter.h"

Dialog_filter::Dialog_filter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_filter)
{
    ui->setupUi(this);
    filter_plot->move(50,50);
    filter_plot->resize(750,350);
}

QVector<double> Dialog_filter::design_fir(const std::string&,
                                  const std::string&,
                                  int,
                                  float_type,
                                  float_type,
                                  float_type,
                                  float_type)
{
    QVector<double> coeff;
    return coeff;

}

Dialog_filter::~Dialog_filter()
{
    delete ui;
}

void Dialog_filter::on_design_filter_pushButton_clicked()
{


}

void Dialog_filter::on_respone_Box_activated(const QString &arg1)
{
    if(arg1.compare("低通滤波器"))
    {
        ui->up_weight_label->setText("阻带衰减");
        ui->down_weight_label->setText("通带波动");
    }
    else
    {
        ui->up_weight_label->setText("通带波动");
        ui->down_weight_label->setText("阻带衰减");
    }

}

void Dialog_filter::set_filter_ui()
{
    ui->respone_Box->setCurrentIndex(0);
    ui->up_weight_label->setText("通带波动");
    ui->down_weight_label->setText("阻带衰减");
}
