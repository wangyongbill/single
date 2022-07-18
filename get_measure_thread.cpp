#include "get_measure_thread.h"
#include <QMessageBox>
#include <QTime>
#include <QtMath>
#include <QCoreApplication>
//code by 王亚慧， 2021，8，23



get_measure_thread::get_measure_thread()
{
    capture_set=new Dialog_measure_set ();
    //选择网口接入和USB接入两种模式
    if_USB=false;//默认采用网口通讯
    if_NET=true;//默认采用网口通讯
    if_connect=false;
    if_DA=false;
    full_samplerate=160000000;//网络通讯下的采样率
    if_threadPause=false;//默认不暂停
    //默认的设置
    capture_type=2;//设置采集的数据类型，1为相位，2为速度，默认为速度
    measure_num=0;
    Last_raw_data=0;

    //biaoding_weiyi=0.024588195e-12;//    lamd/4pi/2^11，m
    biaoding_weiyi=2.401190948e-14;//    lamd/4pi/2^21，m
    double capturetime=double(capture_set->capture_time);
    real_caputure_num=full_samplerate*capturetime;//采集卡一次需要拿到的数据
    single_read_num=1024*800*2;//采集卡单次需要读取的int数据
    single_read_char_num=single_read_num*4;//采集卡单次需要读取的char数据
    single_read_char_Data=new unsigned char[single_read_char_num];//读取的原始char数据


    masterData=new  double[single_read_num];//读取的转化解析后的数据

    target_measure_num=qCeil(double(real_caputure_num)/double(single_read_num)); //一次单次采集需要读取的数据次数

    down_sample=full_samplerate/capture_set->caiyanglv;
    sent_capture_num=single_read_num/down_sample;//下采样后实际发出的数据长度
    sent_capture_Data=new  double[sent_capture_num];//下采样后实际发出的数据

    
}
void get_measure_thread::setting(int fs, double capture_time,bool if_usb_capture,int type,int DA_type)
{
    //选择网口接入和USB接入两种模式
    if (if_usb_capture)
    {
        if_USB=true;
        if_NET=false;
        full_samplerate=20000000;


    }
    else
    {
        if_USB=false;
        if_NET=true;
        full_samplerate=160000000;

    }
    set_DA_type=DA_type;
    if(DA_type!=0)
    {
        if_DA=true;
    }
    else
    {
        if_DA=false;
    }
    capture_type=type;
    real_caputure_num=double(full_samplerate)*capture_time;//采集卡一次需要拿到的数据

    single_read_char_Data=new unsigned char[single_read_char_num];//读取的原始char数据
    masterData=new  double[single_read_num];//读取的转化解析后的数据
    target_measure_num=qCeil(double(real_caputure_num)/double(single_read_num)); //一次单次采集需要读取的数据次数

    down_sample=full_samplerate/fs;
    if(capture_type==0)
    {
        sent_capture_num=single_read_num;//不抽样直接发走
        sent_capture_Data=new  double[sent_capture_num];//下采样后实际发出的数据
    }
    else
    {
        sent_capture_num=single_read_num/down_sample;//下采样后实际发出的数据长度
        sent_capture_Data=new  double[sent_capture_num];//下采样后实际发出的数据
    }
}

void get_measure_thread::close()
{
    //关闭硬件句柄
    m_Pcie.Close();
}

void get_measure_thread::SetAD(int type)
{

    m_Pcie.SetBarData(0,0x84,type);
    //vio_ufc_tx_addr
    m_Pcie.SetBarData(0,0x88,0x80);
    //vio_ufc_valid
    m_Pcie.SetBarData(0,0x80,0);
    m_Pcie.SetBarData(0,0x80,1);
    m_Pcie.SetBarData(0,0x80,0);

}

void get_measure_thread::SetFiberReg(int type)
{
    //vio_ufc_tx_data
    //相位
    if(type==2||type==1)
    {
        m_Pcie.SetBarData(0,0x84,0);
        //vio_ufc_tx_addr
        m_Pcie.SetBarData(0,0x88,0x8C);
        //vio_ufc_valid
        m_Pcie.SetBarData(0,0x80,0);
        m_Pcie.SetBarData(0,0x80,1);
        m_Pcie.SetBarData(0,0x80,0);


        Sleep(10);
        m_Pcie.SetBarData(0,0x84,0);
        //vio_ufc_tx_addr
        m_Pcie.SetBarData(0,0x88,0x50);
        //vio_ufc_valid
        m_Pcie.SetBarData(0,0x80,0);
        m_Pcie.SetBarData(0,0x80,1);
        m_Pcie.SetBarData(0,0x80,0);
        Sleep(10);
    }
    if(type==3)
    {
        //这个数据是为AD转化设置的
        m_Pcie.SetBarData(0,0x84,0);
        //vio_ufc_tx_addr
        m_Pcie.SetBarData(0,0x88,0x8C);
        //vio_ufc_valid
        m_Pcie.SetBarData(0,0x80,0);
        m_Pcie.SetBarData(0,0x80,1);
        m_Pcie.SetBarData(0,0x80,0);


        Sleep(10);
        m_Pcie.SetBarData(0,0x84,1);
        //vio_ufc_tx_addr
        m_Pcie.SetBarData(0,0x88,0x50);
        //vio_ufc_valid
        m_Pcie.SetBarData(0,0x80,0);
        m_Pcie.SetBarData(0,0x80,1);
        m_Pcie.SetBarData(0,0x80,0);
        Sleep(10);
    }
    else if(type==0)//原始波形
    {
        m_Pcie.SetBarData(0,0x84,1);
        //vio_ufc_tx_addr
        m_Pcie.SetBarData(0,0x88,0x8C);
        //vio_ufc_valid
        m_Pcie.SetBarData(0,0x80,0);
        m_Pcie.SetBarData(0,0x80,1);
        m_Pcie.SetBarData(0,0x80,0);


    }

}

//建立连接
void get_measure_thread::reset()
{
    //关闭采集
    m_Pcie.SetBarData(0,0x68,0);
    //复位内存
    //wr_stop_en_r0 <= WReg0x00000078[0];
    //wr_stop_en_r1 <= WReg0x0000007c[0];
    m_Pcie.SetBarData(0,0x78,0);
    m_Pcie.SetBarData(0,0x78,1);
    m_Pcie.SetBarData(0,0x78,0);
    m_Pcie.SetBarData(0,0x7c,0);
    m_Pcie.SetBarData(0,0x7c,1);
    m_Pcie.SetBarData(0,0x7c,0);

    m_Pcie.SetBarData(0,0x48,4);
    m_Pcie.SetBarData(0,0x48,0);
    Sleep(100);


}
void get_measure_thread::start_capture()
{

    if(if_USB)//打开USB
    {
    }
    else//打开网口
    {

        int state= m_Pcie.SetBarData(0,0x70,1);
        //关闭采集
        state= m_Pcie.SetBarData(0,0x68,0);

        state= m_Pcie.SetBarData(0,0x78,0);
        state= m_Pcie.SetBarData(0,0x78,1);
        state= m_Pcie.SetBarData(0,0x78,0);
        state= m_Pcie.SetBarData(0,0x7c,0);
        state= m_Pcie.SetBarData(0,0x7c,1);
        state= m_Pcie.SetBarData(0,0x7c,0);
        //==0内部测试数据  ==1光纤数据
        state= m_Pcie.SetBarData(0,0x100,1);
        //光纤接收使能
        state= m_Pcie.SetBarData(0,0x104,1);
        //DDR读使能
        state= m_Pcie.SetBarData(0,0x70,1);
        Sleep(10);
        //设置DA
        if(if_DA)
        {
            SetAD(set_DA_type);
            SetFiberReg(3);
        }
        //3,设置采集类型
        else
        {
            SetFiberReg(capture_type);//默认设置为2速度，1位移
        }
        Sleep(10);
        //4,启动采集
        state= m_Pcie.SetBarData(0,0x68,1);
        //5，打开PCIe开关
        state= m_Pcie.SetBarData(0,0x74,1);
        Sleep(10);

        //舍弃一次
        int i=0;
        while (i<1)
        {
            unsigned int Size0=0;
            state= m_Pcie.GetBarData(0,0x14,&Size0);
            if(single_read_char_num<Size0*3)//要读的数据要小于内存里现有数据，否则读不到，需要等待一下再读
            {

                unsigned int LenRead=0;
                state=m_Pcie.C2HDMAData (0,single_read_char_Data,single_read_char_num,&LenRead,0);//0句柄，1，读数据放char数组，2数组长度，3，实际读到的长度，4，0
                if(LenRead<single_read_char_num&&(state!=0))
                {
                    qDebug(QStringLiteral("采集失败").toStdString().c_str());

                }
                else
                {
                    QString  data_time = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss.zzz ");
                    qDebug(QStringLiteral("舍弃一次成功").toStdString().c_str());
                    qDebug(data_time.toStdString().c_str());
                    i++;
                }
            }
            else
            {
                Delay_MSec(10);

                //qDebug(QStringLiteral("舍弃一次失败").toStdString().c_str());
            }
        }
    }
}

bool get_measure_thread::on_connection(bool if_connect_USB)
{

    if(if_connect_USB)//打开USB
    {
        
        if_connect=true;
        QMessageBox::information(NULL, QStringLiteral("USB设备连接成功").toStdString().c_str(), QStringLiteral("异常").toStdString().c_str(),
                                 QMessageBox::Yes , QMessageBox::Yes);
        return true;
    }
    else//打开网口
    {
        int Num=DeviceCount(0x10ee,0x0008);
        if(Num<1)
        {
            QMessageBox::information(NULL, QStringLiteral("异常").toStdString().c_str(), QStringLiteral("未找到采集卡").toStdString().c_str(),
                                     QMessageBox::Yes , QMessageBox::Yes);
            return false;
        }

        else if(Num==1)
        {
            unsigned int Value=0;
            m_Pcie.Open(0);
            int state1= m_Pcie.GetBarData(0, 0x0, &Value);
            //1,初始化
            int state2= m_Pcie.SetBarData(0, 0x70,1);
            //关闭采集
            int state3= m_Pcie.SetBarData(0,0x68,0);


            if(state1!=0||state2!=0||state3!=0)
            {

                QMessageBox::information(NULL, QStringLiteral("异常").toStdString().c_str(), QStringLiteral("采集卡初始化失败").toStdString().c_str(),
                                         QMessageBox::Yes , QMessageBox::Yes);
                return false;

            }
            else
            {
                if_connect=true;
                reset();
                QMessageBox::information(NULL, QStringLiteral("提示").toStdString().c_str(), QStringLiteral("采集卡初始化成功").toStdString().c_str(),
                                         QMessageBox::Yes , QMessageBox::Yes);
                return true;
            }
        }


    }

}

void get_measure_thread::start()
{


    start_capture();//开启数据读取线程
    //舍弃一次
    int i=0;
    while (i<1)
    {


        unsigned int Size0=0;
        int state= m_Pcie.GetBarData(0,0x14,&Size0);
        if(single_read_char_num<Size0*3)//要读的数据要小于内存里现有数据，否则读不到，需要等待一下再读
        {

            unsigned int LenRead=0;
            state=m_Pcie.C2HDMAData (0,single_read_char_Data,single_read_char_num,&LenRead,0);//0句柄，1，读数据放char数组，2数组长度，3，实际读到的长度，4，0
            if(LenRead<single_read_char_num&&(state!=0))
            {
                qDebug(QStringLiteral("采集失败").toStdString().c_str());

            }
            else
            {
                QString  data_time = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss.zzz ");
                qDebug(QStringLiteral("舍弃一次成功").toStdString().c_str());
                qDebug(data_time.toStdString().c_str());
                i++;
                if(i==1)
                {
                    QThread::start();
                    //开始线程读显
                    moveToThread(this);
                }
            }
        }

        else
        {
            Delay_MSec(10);

            qDebug(QStringLiteral("舍弃一次失败").toStdString().c_str());
        }
    }





}
void get_measure_thread::run()
{
    measure_num=0;//实际测量的次数
    if(if_lianxu_celiang&&if_connect)
    {

        while(1)
        {

            if(if_USB)
            {
                //不断的获取数据
                //仿真每次生成16M个

                //对实际获得的数据下采样
                for(int var =0,j=0;var < real_caputure_num;var=var+down_sample,j++)
                {
                    masterData[j]=qrand()%20;
                }
                Delay_MSec(1);//100ms发送一次
            }

            if(if_NET)
            {
                if(if_DA)
                {

                    unsigned int Size0=0;
                    int state= m_Pcie.GetBarData(0,0x14,&Size0);
                    sent_neicun(Size0);
                    if(single_read_char_num<Size0*3)//要读的数据要小于内存里现有数据，否则读不到，需要等待一下再读
                    {
                        //打开PCIe开关
                        // state= m_Pcie.SetBarData(0,0x74,1);

                        unsigned int LenRead=0;
                        state=m_Pcie.C2HDMAData (0,single_read_char_Data,single_read_char_num,&LenRead,0);//0句柄，1，读数据放char数组，2数组长度，3，实际读到的长度，4，0
                        if(LenRead<=0)
                        {
                            qDebug(QStringLiteral("采集失败").toStdString().c_str());

                        }
                        else
                        {
                            QString  data_time = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss.zzz ");
                            qDebug(QStringLiteral("采集成功").toStdString().c_str());
                            qDebug(data_time.toStdString().c_str());
                        }

                    }
                    else
                    {

                        Delay_MSec(10);
                    }
                }
                else
                {
                    unsigned int Size0=0;
                    int state= m_Pcie.GetBarData(0,0x14,&Size0);
                    sent_neicun(Size0);
                    if(single_read_char_num<Size0*3)//要读的数据要小于内存里现有数据，否则读不到，需要等待一下再读
                    {
                        //打开PCIe开关
                        // state= m_Pcie.SetBarData(0,0x74,1);

                        unsigned int LenRead=0;
                        state=m_Pcie.C2HDMAData (0,single_read_char_Data,single_read_char_num,&LenRead,0);//0句柄，1，读数据放char数组，2数组长度，3，实际读到的长度，4，0
                        if(LenRead<=0)
                        {
                            qDebug(QStringLiteral("采集失败").toStdString().c_str());

                        }
                        else
                        {
                            QString  data_time = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss.zzz ");
                            qDebug(QStringLiteral("采集成功").toStdString().c_str());
                            qDebug(data_time.toStdString().c_str());


                            int m_SampleCHNum=1;//单通道
                            if(capture_type==0)
                            {
                                for(int var =0,j=0;var<single_read_char_num;var=var+4,j++)
                                {
                                    // long Data1=((Data[(j*m_SampleCHNum)*4+0]+Data[(j*m_SampleCHNum)*4+1]*256+Data[(j*m_SampleCHNum)*4+2]*256*256+Data[(j*m_SampleCHNum)*4+3]*256*256*256));//-32768.0

                                    sent_capture_Data[j]=((single_read_char_Data[(var*m_SampleCHNum)+0]+single_read_char_Data[(var*m_SampleCHNum)+1]*256));//-32768.0


                                }

                            }
                            else
                            {
                                masterData[0]=Last_raw_data+biaoding_weiyi*(single_read_char_Data[0]+single_read_char_Data[1]*256+single_read_char_Data[2]*256*256+single_read_char_Data[3]*256*256*256);
                                for(int var =4,j=1;var<single_read_char_num;var=var+4,j++)
                                {
                                    // long Data1=((Data[(j*m_SampleCHNum)*4+0]+Data[(j*m_SampleCHNum)*4+1]*256+Data[(j*m_SampleCHNum)*4+2]*256*256+Data[(j*m_SampleCHNum)*4+3]*256*256*256));//-32768.0

                                    masterData[j]=masterData[j-1]+biaoding_weiyi*((single_read_char_Data[(var*m_SampleCHNum)+0]+single_read_char_Data[(var*m_SampleCHNum)+1]*256+single_read_char_Data[(var*m_SampleCHNum)+2]*256*256+single_read_char_Data[(var*m_SampleCHNum)+3]*256*256*256));//-32768.0


                                }
                                Last_raw_data= masterData[single_read_num-1];
                                for(int j=0,i=0;j<single_read_num;j=j+down_sample,i++)
                                {
                                    // long Data1=((Data[(j*m_SampleCHNum)*4+0]+Data[(j*m_SampleCHNum)*4+1]*256+Data[(j*m_SampleCHNum)*4+2]*256*256+Data[(j*m_SampleCHNum)*4+3]*256*256*256));//-32768.0

                                    sent_capture_Data[i]=masterData[j];//-32768.0


                                }

                            }

                            //m_Mutex.lock();
                            sent_capture_data(sent_capture_Data,sent_capture_num,measure_num);
                            // m_Mutex.unlock();
                            measure_num++;
                            if(measure_num>=target_measure_num)
                            {

                                measure_num=0;

                                Delay_MSec(500);


                                emit clear_data(true);
                                start_capture();

                            }

                        }
                    }
                    else
                    {

                        Delay_MSec(1);
                    }


                }
            }
        }
    }
    else
    {


        while(measure_num<target_measure_num&&if_connect)
        {

            if(if_USB)
            {
                //不断的获取数据
                //仿真每次生成16M个

                //对实际获得的数据下采样
                for(int var =0,j=0;var<single_read_num;var=var+down_sample,j++)
                {
                    //sent_capture_Data[j]=qrand()%2;
                    sent_capture_Data[j]=sin(j);

                }

            }

            if(if_NET)
            {

                unsigned int Size0=0;
                int state= m_Pcie.GetBarData(0,0x14,&Size0);
                sent_neicun(Size0);
                if(single_read_char_num<Size0*3)//要读的数据要小于内存里现有数据，否则读不到，需要等待一下再读
                {

                    unsigned int LenRead=0;
                    state=m_Pcie.C2HDMAData (0,single_read_char_Data,single_read_char_num,&LenRead,0);//0句柄，1，读数据放char数组，2数组长度，3，实际读到的长度，4，0
                    if(LenRead<single_read_char_num&&(state!=0))
                    {
                        qDebug(QStringLiteral("采集失败").toStdString().c_str());

                    }
                    else
                    {
                        QString  data_time = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss.zzz ");
                        qDebug(QStringLiteral("采集成功").toStdString().c_str());
                        qDebug(data_time.toStdString().c_str());



                        if(capture_type==0)
                        {
                            int m_SampleCHNum=1;//单通道
                            for(int var =0,j=0;var<single_read_char_num;var=var+4,j++)
                            {
                                // long Data1=((Data[(j*m_SampleCHNum)*4+0]+Data[(j*m_SampleCHNum)*4+1]*256+Data[(j*m_SampleCHNum)*4+2]*256*256+Data[(j*m_SampleCHNum)*4+3]*256*256*256));//-32768.0

                                sent_capture_Data[j]=((single_read_char_Data[(var*m_SampleCHNum)+0]+single_read_char_Data[(var*m_SampleCHNum)+1]*256));//-32768.0


                            }

                        }
                        else
                        {
                            int m_SampleCHNum=1;//单通道
                            masterData[0]=Last_raw_data+biaoding_weiyi*(single_read_char_Data[0]+single_read_char_Data[1]*256+single_read_char_Data[2]*256*256+single_read_char_Data[3]*256*256*256);
                            for(int var =4,j=1;var<single_read_char_num;var=var+4,j++)
                            {
                                // long Data1=((Data[(j*m_SampleCHNum)*4+0]+Data[(j*m_SampleCHNum)*4+1]*256+Data[(j*m_SampleCHNum)*4+2]*256*256+Data[(j*m_SampleCHNum)*4+3]*256*256*256));//-32768.0

                                masterData[j]=masterData[j-1]+biaoding_weiyi*((single_read_char_Data[(var*m_SampleCHNum)+0]+single_read_char_Data[(var*m_SampleCHNum)+1]*256+single_read_char_Data[(var*m_SampleCHNum)+2]*256*256+single_read_char_Data[(var*m_SampleCHNum)+3]*256*256*256));//-32768.0


                            }
                            Last_raw_data= masterData[single_read_num-1];
                            for(int j=0,i=0;j<single_read_num;j=j+down_sample,i++)
                            {
                                // long Data1=((Data[(j*m_SampleCHNum)*4+0]+Data[(j*m_SampleCHNum)*4+1]*256+Data[(j*m_SampleCHNum)*4+2]*256*256+Data[(j*m_SampleCHNum)*4+3]*256*256*256));//-32768.0

                                sent_capture_Data[i]=masterData[j];//-32768.0


                            }

                        }


                        QString show=QString::number(measure_num);
                        qDebug(show.toStdString().c_str());
                        sent_capture_data(sent_capture_Data,sent_capture_num,measure_num);

                        measure_num++;
                    }

                }
                else
                {

                    Delay_MSec(1);
                }
            }
        }




        measure_num=0;
        danci_over();

    }
}

//此函数的目的是获取一次能量，用于自动对焦
double get_measure_thread::get_one_energy()
{
    //1，确保在通讯正常的基础上进行对焦,//需确保自动对焦运行在单次测量结束完且不在连续测量的进程中
    if(if_connect)
    {


        if(if_NET)
        {
            int state= m_Pcie.SetBarData(0,0x70,1);
            //关闭采集
            state= m_Pcie.SetBarData(0,0x68,0);

            state= m_Pcie.SetBarData(0,0x78,0);
            state= m_Pcie.SetBarData(0,0x78,1);
            state= m_Pcie.SetBarData(0,0x78,0);
            state= m_Pcie.SetBarData(0,0x7c,0);
            state= m_Pcie.SetBarData(0,0x7c,1);
            state= m_Pcie.SetBarData(0,0x7c,0);
            //==0内部测试数据  ==1光纤数据
            state= m_Pcie.SetBarData(0,0x100,1);
            //光纤接收使能
            state= m_Pcie.SetBarData(0,0x104,1);
            //DDR读使能
            state= m_Pcie.SetBarData(0,0x70,1);
            Sleep(10);

            //2,设置采集类型
            SetFiberReg(0);//默认设置为2速度，1位移，0原始数据
            Sleep(10);
            //3,启动采集
            state= m_Pcie.SetBarData(0,0x68,1);
            //4，打开PCIe开关
            state= m_Pcie.SetBarData(0,0x74,1);
            Sleep(10);
            //开始采集
            //扔掉前三次
            measure_num=0;//实际测量的次数
            double energy=0;
            while(measure_num<1)
            {
                unsigned int Size0=0;
                int state= m_Pcie.GetBarData(0,0x14,&Size0);
                if(single_read_char_num<Size0)//要读的数据要小于内存里现有数据，否则读不到，需要等待一下再读
                {

                    unsigned int LenRead=0;
                    state=m_Pcie.C2HDMAData (0,single_read_char_Data,single_read_char_num,&LenRead,0);//0句柄，1，读数据放char数组，2数组长度，3，实际读到的长度，4，0
                    if(LenRead<single_read_char_num)
                    {
                        qDebug("读取失败");

                    }
                    else
                    {

                        QString  data_time = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss.zzz ");
                        qDebug(QStringLiteral("采集成功").toStdString().c_str());
                        qDebug(data_time.toStdString().c_str());
                        int m_SampleCHNum=1;//单通道

                        for(int var =single_read_num/4;var<single_read_num;var=var+4)
                        {
                            // long Data1=((Data[(j*m_SampleCHNum)*4+0]+Data[(j*m_SampleCHNum)*4+1]*256+Data[(j*m_SampleCHNum)*4+2]*256*256+Data[(j*m_SampleCHNum)*4+3]*256*256*256));//-32768.0

                            double one_date=(double(single_read_char_Data[(var*m_SampleCHNum)*2+0]+single_read_char_Data[(var*m_SampleCHNum)*2+1]*256)-32768)/16384;//-32768.0
                            //sent_capture_Data[j]=10000*sin(2*3.1415926*1000*j/capture_set->caiyanglv)+10000*sin(2*3.1415926*10000*j/capture_set->caiyanglv);
                            energy=energy+one_date*one_date;
                        }
                        measure_num++;

                    }
                }
                else
                {

                    Delay_MSec(1);
                }
            }
            return  energy;

        }
        //计算下第四次的能量值




    }
}
void get_measure_thread::threadPause()//暂停线程
{

    this->m_Mutex.lock();
    QMessageBox::information(NULL, QStringLiteral("提示").toStdString().c_str(), QStringLiteral("暂停测量").toStdString().c_str(),
                             QMessageBox::Yes , QMessageBox::Yes);

    if_threadPause=true;

    //qDebug()<<QString("pause");//停止测量
}

void get_measure_thread::threadResume()//继续线程
{

    this->m_Mutex.unlock();
    QMessageBox::information(NULL, QStringLiteral("提示").toStdString().c_str(), QStringLiteral("继续测量").toStdString().c_str(),
                             QMessageBox::Yes , QMessageBox::Yes);
    if_threadPause=false;
    // qDebug()<<QString("resume");//继续测量

}
void get_measure_thread::threadStop()
{
    this->terminate();

}
void get_measure_thread::Delay_MSec(unsigned int msec)
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < _Timer )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

