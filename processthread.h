#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H
#include<QThread>

#include <QMutex>
#include <QByteArray>
#include <QFile>
#include "mathprocess.h"
#include "filter.h"
#include "fftw3.h"
#include "dialog_measure_set.h"
#include "get_measure_thread.h"
//此文本是负责从采集卡数据到语音的处理函数类
class processthread : public QThread
{
    Q_OBJECT
public:
    processthread();
    Dialog_measure_set  *Parameter_set;
    get_measure_thread *get_data;
    mathprocess* fftprocess;//计算数据的类
    filter* myfilter;//滤波的类
    double biaoding_weiyi;
    double biaoding_sudu;
    double biaoding_jiasudu;
    double last_raw_point;   double last_raw_point_B;
    double last_A_point;
    double* process_data;   double* process_B_data;
    double*process_A_data;
    double weiyi_mean;
    double * process_fliter_date;
    double* fft_date;
    double *single_data;
    double *single_fft_data;
    double *FFT_date;
    double *RMS_date;
    double*show_fft;
    double Band;
    int spectrumflg;
    double RMS_value;
    QList<double> process_num_date;






    int default_measure_num;

    int show_fft_num;
    int full_samplerate;
    int process_type;
    int measure_num;

    int fs;
    bool if_lvboqi;


    void start();
    void run();





private:

    QMutex m_Mutex;

private slots:
    //获取数据
    void receive_data(double *masterData,int len,int measure_num);
    void receive_setting(bool);
public slots:
    void setting(int len,int fs,int daikuan,int puxian,int lowflg,int highflg,int trackflg,int default_measure_num,bool,int);

signals:
    //把处理后的结果显示到主界面
    void sent_RMS_value( double);
    void save_data_over(bool save_data_over);
    void sent_save_data(QList<double>);
    void sent_time_data(double  *Data,int len,int measure_num);//第一个参数是要发送给显示的数据，第二个是数据长度，第三个参数是是否清空之前的数据，连续清空，单次不清空
    void sent_fft_data(double  *Data,int len);//第一个参数是要发送给显示的数据，第二个是数据长度，第三个参数是是否清空之前的数据，连续清空，单次不清空
};

#endif // PROCESSTHREAD_H
