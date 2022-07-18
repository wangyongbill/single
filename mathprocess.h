#ifndef MATHPROCESS_H
#define MATHPROCESS_H
#include "fftw3.h"
#include <QPoint>
class mathprocess
{
public:
    mathprocess();
    double calcRMS(double* Data, int Num);
    double calcMean(int* Data, int Num);
    double calc_double_Mean(double* Data, int Num);
    double calcRMSE(double* Data,double *Data2,int Num);
    double calcSTD(double* DataR,int Num);
    double calc_MAX(double* Data, int Num);
    double * calcMAX(double* Data, int Num);
    double * calcMIN(double* Data, int Num);
    void  clacfft(double *date, int len,int samplerate,double *out_date);
    void down_resample(double* input, double* output,int down_rate,int len);

//    fftw_complex *fftin;
//     fftw_complex *fftout;

};

#endif // MATHPROCESS_H
