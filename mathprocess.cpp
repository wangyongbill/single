#include "mathprocess.h"
#include "math.h"

#include <limits>
mathprocess::mathprocess()
{

}
double mathprocess::calcMean(int* Data, int Num)
{

    double fSum = 0;
    for (int i = 0; i < Num; ++i)
    {
        fSum += Data[i];
    }
    return (fSum/double(Num));
}
double mathprocess::calc_double_Mean(double* Data, int Num)
{

    double fSum = 0;
    for (int i = 0; i < Num; ++i)
    {
        fSum += Data[i];
    }
    return (fSum/double(Num));
}
//求数据的均方根值
double mathprocess::calcRMS(double* Data, int Num)
{

    double fSum = 0;
    for (int i = 0; i < Num; ++i)
    {
        fSum += Data[i] * Data[i];
    }
    return sqrt(fSum/Num)/1.5;
}
//求数据的均方根误差
double mathprocess:: calcRMSE(double* Data,double *Data2,int Num)
{
    double fSum = 0;
    for (int i = 0; i < Num; ++i)
    {
        fSum += (Data[i] - Data2[i]) *(Data[i] - Data2[i]);
    }
    return sqrt(fSum / Num);
}
//求数据的标准差
double mathprocess::calcSTD(double* DataR,int Num)
{
    double fSum = 0;
    double meanValue = 0;
    for (int i = 0; i < Num; ++i)
    {
        meanValue += DataR[i];
    }
    meanValue = meanValue / Num;

    for (int i = 0; i < Num; ++i)
    {
        fSum += (DataR[i] - meanValue) *(DataR[i] - meanValue);
    }
    return sqrt(fSum / Num); //STD
}
//求数据的最大值
double mathprocess::calc_MAX(double* Data, int Num)
{

    double fmax = (std::numeric_limits<double>::min)();
    double weizhi_max=0;
    for (int i = 0; i < Num; ++i)
    {
        if(Data[i]>fmax)
        {

            fmax=Data[i];

        }
    }



    return (fmax);
}
double * mathprocess::calcMAX(double* Data, int Num)
{
    double * outMAX=new double[2];

    double fmax = (std::numeric_limits<double>::min)();
    double weizhi_max=0;
    for (int i = 0; i < Num; ++i)
    {
        if(Data[i]>fmax)
        {

            fmax=Data[i];
            weizhi_max=i;
        }
    }
    outMAX[0]=fmax;
    outMAX[1]=weizhi_max;

    return (outMAX);
}
//求数据的最小值
double * mathprocess::calcMIN(double* Data, int Num)
{
    double *outMIN=new double [2];
    double fmin = (std::numeric_limits<double>::max)();
    double weizhi_min=0;
    for (int i = 0; i < Num; ++i)
    {
        double temp=Data[i];
        if(Data[i]<fmin)
        {

            fmin=Data[i];
            weizhi_min=i;
        }
    }
    outMIN[0]=fmin;
    outMIN[1]=weizhi_min;
    return (outMIN);
}
//求数据的FFT
//date为输入数据，len为输入数据的长度，samplerate为数据的采样率
//out 为输出的数据
void mathprocess::clacfft(double *date, int len,int samplerate,double *outdate)
{



    fftw_complex *fftin= (fftw_complex *)malloc(len * sizeof(fftw_complex));
    fftw_complex *fftout= (fftw_complex *)malloc(len * sizeof(fftw_complex));
    for (int i=0; i<len;i++)
    {

        fftin[i][0]=date[i];
        fftin[i][1]=0;


    }

    fftw_plan pp = fftw_plan_dft_1d(len, fftin, fftout, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(pp); // 执行变换
    outdate[0] = sqrt((fftout[0][0] * fftout[0][0] +fftout[0][1] * fftout[0][1]))/double(len);
    for (int jj = 1; jj < len; jj++)
    {


        double Yr = fftout[jj][0];
        double Yi = fftout[jj][1];
        outdate[jj] = sqrt((Yr * Yr + Yi * Yi))/double(len)*2;
    }

    fftw_destroy_plan(pp);

    //    delete [] date;
    //    delete [] outdate;
    delete [] fftin;
    delete [] fftout;

}
void mathprocess::down_resample(double* input, double* output,int down_rate,int len)
{

    int j=0;
    for(int var=0; var<len;var++)
    {
        if( var%down_rate==0 )
        {
            output[j]=input[var];
            j++;
        }
    }
}


