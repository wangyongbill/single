#ifndef ELE_MACHINERY_H
#define ELE_MACHINERY_H

//#include "SerialPort.h"//有线连接的类
#include <QSerialPort>
#include <QSerialPortInfo>
class ele_machinery
{
public:


    ele_machinery();

    QSerialPort *m_serialPort;


    bool ele_state;

    QString getPortNameList();//获取串口
    QString on_open();
    void on_star();
    void on_stop();
    void on_foreward();
    void  on_inversion();
    void on_expedite();
    void on_retard();
    void on_speed(const QString &arg1);
    void  on_query();
    void on_foreward_one();
    void on_inversion_one();
    void on_num_foreward(int);
    void on_num_inversion(int);
    QString ReadData();
    void Delay_MSec(unsigned int msec);
};

#endif // ELE_MACHINERY_H
