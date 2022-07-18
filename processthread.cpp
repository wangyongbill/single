#include "processthread.h"
#include <qdebug.h>
#include <QEventLoop>
#include <QTime>
#include <QFile>
#include <QCoreApplication>
#include <QMutexLocker>
#include <QTextStream>
#include <QDataStream>
#include "spectrumDisp.h"
processthread::processthread()
{
    get_data=new get_measure_thread();
    Parameter_set=new Dialog_measure_set ();
    myfilter = new filter();
    if_lvboqi=Parameter_set->if_lvbo;
    RMS_value=0;
    biaoding_weiyi=0.024588195e-12;//    lamd/4pi/2^11，m

    //biaoding_jiasudu=1;
    last_raw_point=0;  last_raw_point_B=0;
    last_A_point=0;
    weiyi_mean=0;
    spectrumflg=0;
    process_type=2;
    fs=Parameter_set->caiyanglv;
    biaoding_sudu=fs;//   *160*10^6*lamd/4pi/2^21，m/s

    biaoding_jiasudu=fs;


    setting(get_data->sent_capture_num,Parameter_set->caiyanglv,Parameter_set->daikuan,Parameter_set->puxianshu,Parameter_set->lowflg,Parameter_set->highflg,Parameter_set->trackflg,Parameter_set->default_measure_num,false,process_type);
    RMS_date=new double[Parameter_set->puxianshu/4];


}
void processthread::setting(int len,int set_fs,int daikuan,int puixian,int lowflg,int highflg,int trackflg,int default_num,bool if_lv,int celiang_type)
{
    //len为采集卡单片取的长度，default_num为用户设置的处理长度
    Band=daikuan;
    fs=set_fs;
    if_lvboqi=if_lv;
    biaoding_sudu=fs;       biaoding_jiasudu=fs;
    default_measure_num=default_num;
    RMS_date=new double[puixian/4];
    myfilter->setfilter(fs,len,lowflg,highflg,trackflg);
    single_data=new double[len];
    process_data=new double[len];        process_B_data=new double[len];
    process_A_data=new double[len];
    process_type=celiang_type;
    process_fliter_date=new double[len];
    fft_date=new double[default_num];

    single_fft_data=new double[default_measure_num];


//    single_fft_data=new double[puixian];
    show_fft_num=puixian;
    show_fft=new double[show_fft_num];
}
void processthread::start()
{
    
    QThread::start();
    
}
void processthread::receive_data(double *raw_Data,int len,int measure_num)
{


    m_Mutex.lock();
    if(process_type==0)
    {
        for ( int i=0; i<len; i++ )
        {

            process_data[i]=((raw_Data[i])-32768)/16384;

        }
    }
    //速度
    if(process_type==2)
    {
        //        process_data[0]=(raw_Data[0]-last_raw_point)*biaoding_sudu;//*biaoding_sudu;
        for ( int i=0; i<len; i++ )
        {
            auto temp = raw_Data[i];
            process_data[i]=(raw_Data[i]-last_raw_point)*biaoding_sudu;//*biaoding_sudu;
            //            qDebug()<<i<<raw_Data[i];
            //            qDebug()<<i<<process_data[i];
            last_raw_point=temp;
        }
    }
    //位移不变
    else if(process_type==1)
    {
        if(measure_num==0)
        {
            weiyi_mean=raw_Data[0];
                    //weiyi_mean= fftprocess->calc_double_Mean(raw_Data,len);
                    //qDebug()<<weiyi_mean;
        }

        for ( int i=0; i<len; i++ )
        {
            process_data[i]=((raw_Data[i]-weiyi_mean));//*biaoding_weiyi;
            //qDebug()<<i<<raw_Data[i];
            //qDebug()<<i<<process_data[i];
        }

    }
    else if(process_type==3)
    {
        for ( int i=0; i<len; i++ )
        {
            auto temp = raw_Data[i];
            process_data[i]=(raw_Data[i]-last_raw_point)*biaoding_sudu;//*biaoding_sudu;
            //            qDebug()<<i<<raw_Data[i];
            //            qDebug()<<i<<process_data[i];
            last_raw_point=temp;
        }

        for ( int i=0; i<len; i++ )
        {
            auto temp = process_data[i];
            process_B_data[i]=(process_data[i]-last_raw_point_B)*biaoding_jiasudu;//*biaoding_sudu;
            //            qDebug()<<i<<raw_Data[i];
            //            qDebug()<<i<<process_data[i];
            last_raw_point_B=temp;
        }

        for ( int i=0; i<len; i++ )
        {
           process_data[i] = process_B_data[i];
        }

//        //先转化为速度
//        process_A_data[0]=(raw_Data[0])*biaoding_sudu-last_A_point;
//        for(int i=1; i<len; i++)
//        {
//            process_A_data[i]=((raw_Data[i]-raw_Data[i-1]))*biaoding_sudu;
//        }
//        last_A_point=process_A_data[default_measure_num-1];

        //再转化为加速度速度
        //保存上一次的最后一个值
//        process_data[0]=process_A_data[0]*biaoding_jiasudu-last_raw_point;
//        for ( int i=1; i<len; i++ )
//        {
//            process_data[i]=(process_A_data[i]-process_A_data[i-1])*biaoding_jiasudu;

//        }
//        last_raw_point=process_data[len-1];
    }


    //第四步，判断是否滤波

    if(if_lvboqi)
    {
        //调用滤波函数滤波
        myfilter->allfilter(process_data, len, process_fliter_date);  //实际滤波函数
        //        memset(myfilter->zi_high,0,sizeof(double)*myfilter->zi_high_Len);
        //        memset(myfilter->zf_high,0,sizeof(double)*myfilter->zf_high_Len);

        //, 0, sizeof(double)*this->inDataLen);
    }
    else
    {
        process_fliter_date=process_data;
    }


    emit sent_time_data( process_fliter_date,len,measure_num);

    //第五步数据累计
    if(measure_num==0)
    {
        process_num_date.clear();

    }

    for ( int i=0; i<len; i++ )
    {
        process_num_date.append(process_fliter_date[i]);
    }

    if(process_num_date.size()>=default_measure_num)
    {
        for ( int i=0; i<default_measure_num; i++ )
        {

            fft_date[i]=process_num_date.at(i);
        }

        spectrumDisp(fft_date,default_measure_num, fs, Band,spectrumflg, single_fft_data);
        if(spectrumflg==1)
        {

            //计算RMS
            for ( int i=show_fft_num/4,j=0; i<show_fft_num/2; i++,j++ )
            {

                RMS_date[j]=single_fft_data[i];

            }
            RMS_value= fftprocess->calcRMS(RMS_date,show_fft_num/4);
            emit sent_RMS_value(RMS_value);
        }
        //fftprocess->clacfft(fft_date, default_measure_num,fs,single_fft_data);
        for ( int i=0; i<show_fft_num; i++ )
        {

            show_fft[i]=single_fft_data[i];
        }

        emit sent_fft_data( show_fft,show_fft_num);
        //清空数据
        process_num_date.clear();
        //delete [] single_data;
        //delete [] single_fft_data;
    }

    m_Mutex.unlock();
}



void processthread::run()
{
    while (1)
    {


    }
}


void processthread:: receive_setting(bool if_change)
{
    //每次按100ms处理数据设置

    myfilter->setfilter(Parameter_set->caiyanglv,Parameter_set->caiyanglv/10,Parameter_set->lowflg,Parameter_set->highflg,Parameter_set->trackflg);

}
