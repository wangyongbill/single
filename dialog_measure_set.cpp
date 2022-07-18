#include "dialog_measure_set.h"
#include "ui_dialog_measure_set.h"
#include <QMessageBox>
#include <QStringLiteral>
Dialog_measure_set::Dialog_measure_set(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_measure_set)
{
    ui->setupUi(this);
    if_lvbo=false;
    if_USB=false;
    if_NET=true;
    ui->NET->setChecked(true);
    if_A=false;
    if_D=true;//默认测速
    if_S=false;
    if_O=false;
    DA_type=0;
    ui->if_D->setChecked(true);
    daikuan=30000000;
    ui->checkBox_17->setChecked(true);
    caiyanglv=80000000;
    puxianshu=50000;
    ui->fft_5->setChecked(true);
    capture_time=double(puxianshu)/double(daikuan);
    default_measure_num=int(caiyanglv*capture_time);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    lowflg = 0;
    highflg = 0;
    trackflg = 0;
}

Dialog_measure_set::~Dialog_measure_set()
{
    delete ui;
}


//换了量程以后，没有更新对应的时间
void Dialog_measure_set::on_checkBox_15_clicked()
{
    //0-25Khz被选中，此时采样率为200khz
    caiyanglv=200000;
    //加速度最后两个三不可选
    daikuan=50000;
    capture_time=double(puxianshu)/double(daikuan);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    default_measure_num=int(caiyanglv*capture_time);
    //高通滤波器10hz不可选
    ui->hf_2->setCheckable(true);
    ui->hf_3->setCheckable(false);

    //低通滤波器200khz-12Mhz不可选
    ui->lf_5->setCheckable(false);
    ui->lf_6->setCheckable(false);
    ui->lf_7->setCheckable(false);
    ui->lf_8->setCheckable(false);
    ui->lf_9->setCheckable(false);

    ui->lf_10->setCheckable(false);
    //剩下的可选
    ui->lf_2->setCheckable(true);
    ui->lf_3->setCheckable(true);

    ui->lf_4->setCheckable(true);

}

void Dialog_measure_set::on_checkBox_16_clicked()
{
    caiyanglv=20000000;//20M
    daikuan=3000000;
    capture_time=double(puxianshu)/double(daikuan);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    default_measure_num=int(caiyanglv*capture_time);
    //高通滤波器10hz不可选
    ui->hf_2->setCheckable(true);
    ui->hf_3->setCheckable(false);
    //低通滤波器2Khz-15Khz不可选
    ui->lf_2->setCheckable(false);
    ui->lf_3->setCheckable(false);

    ui->lf_4->setCheckable(false);
    //低通滤波器1.6Mhz-12Mhz不可选
    ui->lf_8->setCheckable(false);
    ui->lf_9->setCheckable(false);

    ui->lf_10->setCheckable(false);
    //剩下的可选
    ui->lf_5->setCheckable(true);
    ui->lf_6->setCheckable(true);

    ui->lf_7->setCheckable(true);
}

void Dialog_measure_set::on_checkBox_17_clicked()
{
    caiyanglv=80000000;
    daikuan=30000000;
    capture_time=double(puxianshu)/double(daikuan);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    default_measure_num=int(caiyanglv*capture_time);
    //高通滤波器5hz不可选
    ui->hf_2->setCheckable(false);
    ui->hf_3->setCheckable(true);
    //低通滤波器2Khz-1.5Mhz不可选
    ui->lf_2->setCheckable(false);
    ui->lf_3->setCheckable(false);

    ui->lf_4->setCheckable(false);
    ui->lf_5->setCheckable(false);
    ui->lf_6->setCheckable(false);

    ui->lf_7->setCheckable(false);
    //剩下的可选
    ui->lf_8->setCheckable(true);
    ui->lf_9->setCheckable(true);

    ui->lf_10->setCheckable(true);

}

void Dialog_measure_set::on_fft_1_clicked()
{
    //设置谱线数
    puxianshu=25000;
    capture_time=double(puxianshu)/double(daikuan);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    default_measure_num=int(caiyanglv*capture_time);
}

void Dialog_measure_set::on_fft_2_clicked()
{
    //设置谱线数
    puxianshu=12500;
    capture_time=double(puxianshu)/double(daikuan);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    default_measure_num=int(caiyanglv*capture_time);
}

void Dialog_measure_set::on_fft_3_clicked()
{
    //设置谱线数
    puxianshu=6250;
    capture_time=double(puxianshu)/double(daikuan);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    default_measure_num=int(caiyanglv*capture_time);
}

void Dialog_measure_set::on_fft_4_clicked()
{
    //设置谱线数
    puxianshu=3125;
    capture_time=double(puxianshu)/double(daikuan);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    default_measure_num=int(caiyanglv*capture_time);
}

void Dialog_measure_set::on_fft_5_clicked()
{
    //设置谱线数
    puxianshu=50000;
    capture_time=double(puxianshu)/double(daikuan);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    default_measure_num=int(caiyanglv*capture_time);
}

void Dialog_measure_set::on_fft_6_clicked()
{
    //设置谱线数
    puxianshu=250000;
    capture_time=double(puxianshu)/double(daikuan);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    default_measure_num=int(caiyanglv*capture_time);
}

void Dialog_measure_set::on_fft_7_clicked()
{
    //设置谱线数
    puxianshu=250;
    capture_time=double(puxianshu)/double(daikuan);
    QString line=QString::number(capture_time, 'f', 5);
    ui->lineEdit->setText(line);
    default_measure_num=int(caiyanglv*capture_time);
}
//低通滤波器
void Dialog_measure_set::on_hf_1_clicked()
{
    //没有滤波器
    highflg = 0;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_hf_2_clicked()
{
    highflg = 1;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_hf_3_clicked()
{
    highflg = 1;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}
void Dialog_measure_set::on_hf_4_clicked()
{
    highflg = 2;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_hf_5_clicked()
{
    highflg = 3;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}
//低通滤波器
void Dialog_measure_set::on_lf_1_clicked()
{
    lowflg = 0;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_lf_2_clicked()
{
    lowflg = 1;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_lf_3_clicked()
{
    lowflg = 2;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_lf_4_clicked()
{
    lowflg = 3;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_lf_5_clicked()
{
    lowflg = 1;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_lf_6_clicked()
{
    lowflg = 2;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_lf_7_clicked()
{
    lowflg = 3;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_lf_8_clicked()
{
    lowflg = 1;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}
void Dialog_measure_set::on_lf_9_clicked()
{
    lowflg = 2;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}
void Dialog_measure_set::on_lf_10_clicked()
{
    lowflg = 3;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}


void Dialog_measure_set::on_tf_1_clicked()
{
    trackflg = 0;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_tf_2_clicked()
{
    trackflg = 1;
    if(highflg==0&&lowflg==0&&trackflg==0)
    {
    if_lvbo=false;
    }
    else
    {

       if_lvbo=true;
    }
}

void Dialog_measure_set::on_set_ok_clicked()
{

    QMessageBox::information(NULL, QStringLiteral("提示").toStdString().c_str(), QStringLiteral("设置成功").toStdString().c_str(),
                             QMessageBox::Yes , QMessageBox::Yes);
    Setting_changed(true);


}



void Dialog_measure_set::on_NET_clicked()
{
    if_USB=false;
    if_NET=true;
    ui->NET->setCheckable(true);
}

void Dialog_measure_set::on_USB_clicked()
{
    if_USB=true;
    if_NET=false;
    ui->USB->setCheckable(true);
    ui->checkBox_17->setCheckable(false);
}

void Dialog_measure_set::on_if_A_clicked()
{
    if_A=true;
    if_D=false;
    if_S=false;
    if_O=false;
    ui->if_A->setCheckable(true);
    ui->checkBox_15->setCheckable(true);
    ui->checkBox_16->setCheckable(true);
    ui->checkBox_17->setCheckable(true);
}

void Dialog_measure_set::on_if_D_clicked()
{
    if_A=false;
    if_D=true;
    if_S=false;
    if_O=false;
    ui->if_D->setCheckable(true);
    ui->checkBox_15->setCheckable(true);
    ui->checkBox_16->setCheckable(true);
    ui->checkBox_17->setCheckable(true);
}

void Dialog_measure_set::on_if_S_clicked()
{
    if_A=false;
    if_D=false;
    if_O=false;
    if_S=true;
    ui->if_S->setCheckable(true);
    ui->checkBox_15->setCheckable(true);
    ui->checkBox_16->setCheckable(true);
    ui->checkBox_17->setCheckable(true);
}





void Dialog_measure_set::on_if_O_clicked()
{
    if_A=false;
    if_D=false;
    if_S=false;
    if_O=true;
    caiyanglv=1600000000;

    ui->if_O->setCheckable(true);
    ui->checkBox_15->setCheckable(false);
    ui->checkBox_16->setCheckable(false);
    ui->checkBox_17->setCheckable(false);
}

void Dialog_measure_set::on_horizontalSlider_valueChanged(int value)
{
    DA_type=value;
    QString line=QString::number(value);
    ui->lineEdit_2->setText(line);

}
