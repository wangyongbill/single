#include "ele_machinery.h"
#include <QMessageBox>
#include <QTime>
#include <QCoreApplication>
ele_machinery::ele_machinery()
{

    m_serialPort= new QSerialPort();
    ele_state=false;

}

QString ele_machinery::getPortNameList()
{
    QString m_serialPortName;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        if (info.description().compare("USB Serial Port") == 0)//USB-SERIAL CH340//Prolific USB-to-Serial Comm Port

        {
            m_serialPortName == info.portName();
            // qDebug() << "serialPortName:" << info.portName();
            return info.portName();
        }
        else if(info.description().compare("USB-SERIAL CH340") == 0)
        {
            m_serialPortName == info.portName();
            // qDebug() << "serialPortName:" << info.portName();
            return info.portName();
        }


    }
    return "";

}

QString ele_machinery::on_open()
{
    QString  m_portNameList = getPortNameList();
    if(m_portNameList=="")
    {

        QMessageBox::question(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("未找到电机"),  QMessageBox::Yes);
        return "";
    }
    else
    {
        //设置波特率
        m_serialPort->setBaudRate(QSerialPort::Baud115200);//Baud115200//Baud9600
        //设置数据位
        m_serialPort->setDataBits(QSerialPort::Data8);
        //设置是否奇偶校验
        m_serialPort->setParity(QSerialPort::NoParity);
        //设置停止位
        m_serialPort->setStopBits(QSerialPort::OneStop);
        //设置是否流控制
        m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
        m_serialPort->setPortName(m_portNameList);
    }
    //打开串口—可读可写地打开
    if (! m_serialPort->open(QIODevice::ReadWrite) )
    {
        QMessageBox::question(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("电机打开失败"),  QMessageBox::Yes);

        ele_state=false;

    }

    else
    {

        //初始化电流/速度/细分
        char Byte_sudu[10];//电机初始化速度
        Byte_sudu[0]=0xAA;
        Byte_sudu[1]=0x02;
        Byte_sudu[2]=0x30;
        Byte_sudu[3]=0xDC;
        char Byte_xifen[10];//电机初始化细分
        Byte_xifen[0]=0xAA;
        Byte_xifen[1]=0x04;
        Byte_xifen[2]=0x02;
        Byte_xifen[3]=0xB0;
        char Byte_dianliu[10];//电机初始化电流
        Byte_dianliu[0]=0xAA;
        Byte_dianliu[1]=0x03;
        Byte_dianliu[2]=0x1A;
        Byte_dianliu[3]=0xC7;

        m_serialPort->write(Byte_sudu, 4);
        //时间间隔需要改进
        Delay_MSec(100);
        m_serialPort->write(Byte_dianliu, 4);

        Delay_MSec(100);
        m_serialPort->write(Byte_xifen, 4);
        ele_state=true;
        QMessageBox::information(NULL, "right", QString::fromLocal8Bit("电机初始化完成"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return m_portNameList;
    }
}










void ele_machinery::on_star()
{

    //启动：AA  01  01  AC
    QTime dieTime = QTime::currentTime().addMSecs(20);//启动之前睡500ms
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    char Byte[4];
    Byte[0]=0xAA;
    Byte[1]=0x01;
    Byte[2]=0x01;
    Byte[3]=0xAC;

    m_serialPort->write(Byte, 4);



}

void ele_machinery::on_stop()
{
    //停止：AA  01  02  AD
    char Byte[10];
    Byte[0]=0xAA;
    Byte[1]=0x01;
    Byte[2]=0x02;
    Byte[3]=0xAD;
    m_serialPort->write(Byte, 4);

}

void ele_machinery::on_inversion_one()
{
    //正转：AA  01  03
    char Byte[10];
    Byte[0]=0xAB;
    Byte[1]=0x03;
    Byte[2]=0x03;
    Byte[3]=0x30;
    Byte[4]=0x01;
    Byte[5]=0x01;
    Byte[6]=0xE3;

    m_serialPort->write(Byte, 7);


}
void ele_machinery::on_foreward_one()
{

    //正转：AA  01  03
    char Byte[10];
    Byte[0]=0xAB;
    Byte[1]=0x03;
    Byte[2]=0x04;
    Byte[3]=0x30;
    Byte[4]=0x01;
    Byte[5]=0x01;
    Byte[6]=0xE4;

    m_serialPort->write(Byte, 7);



}
void ele_machinery::on_inversion()
{

    //正转：AA  01  03  AE
    char Byte[10];
    Byte[0]=0xAA;
    Byte[1]=0x01;
    Byte[2]=0x03;
    Byte[3]=0xAE;

    m_serialPort->write(Byte, 4);

}
void ele_machinery::on_num_inversion(int step)
{
    QString sent_0="AB";
    QString sent_1="03";
    QString sent_2="03";
    QString sent_3="30";
    QString sent_4="01";
    QString sent_5=QString::number(step,16);

    if(sent_5.length ()>2)
    {
        //大于2，去掉前面的几位
        sent_5=sent_5.mid(sent_5.length ()-2,2);
    }
    else if(sent_5.length ()<2)
    {
        //小于2，补一维
        sent_5="0"+sent_5;
    }

    QByteArray sendData;


    bool ok;

    int all_sum=sent_0.toInt(&ok,16)+sent_1.toInt(&ok,16)+sent_2.toInt(&ok,16)+sent_3.toInt(&ok,16)+sent_4.toInt(&ok,16)+sent_5.toInt(&ok,16);

    QString all_sum_qq=QString::number(all_sum,16);
    QString sent_6=all_sum_qq.mid(all_sum_qq.length ()-2,2);

    QString sent="";
    sent.append(sent_0);
    sent.append(" ");
    sent.append(sent_1);
    sent.append(" ");
    sent.append(sent_2);
    sent.append(" ");
    sent.append(sent_3);
    sent.append(" ");
    sent.append(sent_4);
    sent.append(" ");
    sent.append(sent_5);
    sent.append(" ");
    sent.append(sent_6);
    sent.append(" ");
    sendData = QByteArray::fromHex(sent.toUtf8()).data();
    m_serialPort->write(sendData);



}
void ele_machinery::on_num_foreward(int step)
{

    QString sent_0="AB";
    QString sent_1="03";
    QString sent_2="04";
    QString sent_3="30";
    QString sent_4="01";
    QString sent_5=QString::number(step,16);
    if(sent_5.length ()>2)
    {
        //大于2，去掉前面的几位
        sent_5=sent_5.mid(sent_5.length ()-2,2);
    }
    else if(sent_5.length ()<2)
    {
        //小于2，补一维
        sent_5="0"+sent_5;
    }

    QByteArray sendData;


    bool ok;

    int all_sum=sent_0.toInt(&ok,16)+sent_1.toInt(&ok,16)+sent_2.toInt(&ok,16)+sent_3.toInt(&ok,16)+sent_4.toInt(&ok,16)+sent_5.toInt(&ok,16);

    QString all_sum_qq=QString::number(all_sum,16);
    QString sent_6=all_sum_qq.mid(all_sum_qq.length ()-2,2);

    QString sent="";
    sent.append(sent_0);
    sent.append(" ");
    sent.append(sent_1);
    sent.append(" ");
    sent.append(sent_2);
    sent.append(" ");
    sent.append(sent_3);
    sent.append(" ");
    sent.append(sent_4);
    sent.append(" ");
    sent.append(sent_5);
    sent.append(" ");
    sent.append(sent_6);
    sent.append(" ");
    sendData = QByteArray::fromHex(sent.toUtf8()).data();
    m_serialPort->write(sendData);


}
void ele_machinery::on_foreward()
{

    //反转：AA  01  04  AF
    char Byte[10];
    Byte[0]=0xAA;
    Byte[1]=0x01;
    Byte[2]=0x04;
    Byte[3]=0xAF;

    m_serialPort->write(Byte, 4);

}

void ele_machinery::on_expedite()
{
    //加速：AA  01  05  B0
    char Byte[10];
    Byte[0]=0xAA;
    Byte[1]=0x01;
    Byte[2]=0x05;
    Byte[3]=0xB0;

    m_serialPort->write(Byte, 4);

}

void ele_machinery::on_retard()
{

    //减速：AA  01  06  B1
    char Byte[10];
    Byte[0]=0xAA;
    Byte[1]=0x01;
    Byte[2]=0x06;
    Byte[3]=0xB1;

    m_serialPort->write(Byte, 4);

}

void ele_machinery::on_speed(const QString &arg1)
{

    QString str =" ui->speed_comboBox->currentText()";
    QStringList strList = str.split(":");
    QString sel=strList[1];

    //定速：AA  02  NN  MM
    char Byte[10];
    Byte[0]=0xAA;
    Byte[1]=0x02;
    if(sel=="0")
    {
        Byte[2]=0x00;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="1")
    {
        Byte[2]=0x01;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="2")
    {
        Byte[2]=0x02;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="3")
    {
        Byte[2]=0x03;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="4")
    {
        Byte[2]=0x04;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="5")
    {
        Byte[2]=0x05;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="6")
    {
        Byte[2]=0x06;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="7")
    {
        Byte[2]=0x07;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="8")
    {
        Byte[2]=0x08;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="9")
    {
        Byte[2]=0x09;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="A")
    {
        Byte[2]=0x0A;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="B")
    {
        Byte[2]=0x0B;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="C")
    {
        Byte[2]=0x0C;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="D")
    {
        Byte[2]=0x0D;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="E")
    {
        Byte[2]=0x0E;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="F")
    {
        Byte[2]=0x0F;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="10")
    {
        Byte[2]=0x10;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="11")
    {
        Byte[2]=0x11;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="12")
    {
        Byte[2]=0x12;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="13")
    {
        Byte[2]=0x13;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }

    if(sel=="14")
    {
        Byte[2]=0x14;
        Byte[3]=Byte[0]^Byte[1]^Byte[2];
    }


    m_serialPort->write(Byte, 4);

}

void ele_machinery::on_query()
{

    //查询：AA  00  00  AA
    char Byte[10];
    Byte[0]=0xAA;
    Byte[1]=0x00;
    Byte[2]=0x00;
    Byte[3]=0xAA;

    m_serialPort->write(Byte, 4);

}
QString ele_machinery::ReadData()
{
    //串口可读数据长度
    int byteLen = m_serialPort->bytesAvailable();
    if(byteLen < 0)
    {
        return "";
    }

    QString uart_rec_ss=m_serialPort->readAll();  //读取数据
    return  uart_rec_ss;
}
void ele_machinery::Delay_MSec(unsigned int msec)
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < _Timer )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
