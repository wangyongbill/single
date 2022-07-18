#ifndef GET_MEASURE_THREAD_H
#define GET_MEASURE_THREAD_H

// code by wangyaui 2021,8,20
//获取数据的类

#include <QThread>
#include <QMutex>
#include "xdmapcie.h"
#include "dialog_measure_set.h"

class get_measure_thread : public QThread
{
    Q_OBJECT
public:
    XDMaPcie m_Pcie;
    get_measure_thread();
    Dialog_measure_set  *capture_set;
    bool on_connection(bool);//建立通讯
    void close();//关闭设备
    void start();//开启线程
    void reset();
    void SetFiberReg(int type);//设置数据采集类型
    void SetAD(int type);//设置AD的类型
    void start_capture();
    void run();
    void threadPause();//暂停线程
    void threadResume();//继续线程
    void threadStop();//结束线程
    void Delay_MSec(unsigned int msec);
    void setting(int fs, double capturenum,bool if_usb_capture,int type,int DA_type);
    //获取能量
    double get_one_energy();


    bool if_USB;
    bool if_NET;//默认采用USB通讯
    bool if_lianxu_celiang;
    int capture_type;//设置采集的数据类型，1为相位，2为速度
    int single_read_num;//每次单次读取的数据量
    int single_read_char_num;
    unsigned char *single_read_char_Data;
    int measure_num;
    double Last_raw_data;
    double * masterData;//每次采集卡读取的数据
    int target_measure_num;//一次单次采集需要读取的数据次数
    bool if_danci_celiang;
    bool if_connect;
    bool if_threadPause;
    bool if_DA;
    int set_DA_type;
    int  full_samplerate;
    int  real_caputure_num;//单次测量需要获得的数据总量
    int  down_sample;//根据用户设置的采样率下采样
    int sent_capture_num;
    double * sent_capture_Data;//下采样后的实际数据
double biaoding_weiyi;



private:

    QMutex m_Mutex;


signals:
    void sent_capture_data(double *Data,int len,int);
    void clear_data(bool);
    void sent_neicun(int);
    void danci_over();


};

#endif // GET_MEASURE_THREAD_H
