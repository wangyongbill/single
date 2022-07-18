#include "filter.h"
#include <cstring>
#include<iostream>
using namespace std;
//200k的高通
//5Hz
double high_5Hz_200k_fenzi[3] = { 0.999218844035888,-1.998437675744407,0.999218844035888 };
double high_5Hz_200k_fenmu[3] = { 1, -1.998437065539672,0.998438298276511 };
//20Hz
double high_20Hz_200k_fenzi[5] = { 0.998566577998784,-3.994265917776853,5.991398679556158,-3.994265917776853,0.998566577998784 };
double high_20Hz_200k_fenmu[5] = { 1,-3.997130704988089,5.991396624858488,-3.991401130564653,0.997135210696200 };
//80Hz
double high_80Hz_200k_fenzi[6] = { 0.994851184749131, -4.974248068716582,9.948488282416498, -9.948488282416498,4.974248068716582, -0.994851184749131 };
double high_80Hz_200k_fenmu[6] = { 1, -4.989667890121789,9.958732778533033, -9.938190765963360,4.958854757349489, -0.989728879796749 };

//20M的高通
//5Hz
double high_5Hz_20M_fenzi[3] = { 0.999992185417477,-1.999984370833720,0.999992185417477 };
double high_5Hz_20M_fenmu[3] = { 1,-1.999984370772653,0.999984370896022 };
//20Hz
double high_20Hz_20M_fenzi[3] = { 0.999968742036317, -1.999937484052896,0.999968742036317 };
double high_20Hz_20M_fenmu[3] = { 1, -1.999937483075836,0.999937485049695 };
//80Hz
double high_80Hz_20M_fenzi[3] = { 0.999874974007817,-1.999749947699846,0.999874974007817 };
double high_80Hz_20M_fenmu[3] = { 1,-1.999749932068347,0.999749963647132 };

//160M高通
//5Hz
double high_10Hz_160M_fenzi[3] = { 0.999998046348644,-1.999996092697211,0.999998046348644 };
double high_10Hz_160M_fenmu[3] = { 1,-1.999996092693394,0.999996092701105 };
//20Hz
double high_20Hz_160M_fenzi[3] = { 0.999996092701105, -1.999992185401901,0.999996092701105 };
double high_20Hz_160M_fenmu[3] = { 1, -1.999992185386635,0.999992185417477 };
//80Hz
double high_80Hz_160M_fenzi[3] = { 0.999984370896022,-1.999968741787110,0.999984370896022 };
double high_80Hz_160M_fenmu[3] = { 1,-1.999968741542841,0.999968742036313 };


//低通 所有的采样频率下都是一样的
double low_1_fenzi[5] = { 0.00943948478695994, -0.0359537472897601, 0.0530726783961626, -0.0359537472897601, 0.00943948478695994 };
double low_1_fenmu[5] = { 1, -3.78740272814250, 5.38455481320012, -3.40553232264235, 0.808424390975283 };
double low_2_fenzi[8] = { 0.00996366756335930, -0.0347634835015765, 0.0506502301880700, -0.0251140336345510, -0.0251140336345510, 0.0506502301880700, -0.0347634835015765, 0.00996366756335930 };
double low_2_fenmu[8] = { 1, -5.13826902298320, 11.5154356750997, -14.5441834606586, 11.1581750063296, -5.19188648671532, 1.35503049088311, -0.152829440724745 };
double low_3_fenzi[7] = { 0.0164455671845972, -0.0243388699191550, 0.0375294253642836, -0.0292333289036887, 0.0375294253642836, -0.0243388699191550, 0.0164455671845972 };
double low_3_fenmu[7] = { 1, -3.57794625394294, 5.67674599613202, -4.99003654401937, 2.54672738460654, -0.710050435847804, 0.0845987694273197 };

filter::filter()
{
    //初始化为默认不滤波
    this->islow = 0;
    this->ishigh = 0;
    this->istrack = 0;
}

void filter::setfilter(int fs, int inputDataLen,int low, int high, int track)
{
    this->samplerate = fs;
    this->islow = low;
    this->ishigh = high;
    this->istrack = track;

    //
    // 输入、输出数据和数据长度储存

    this->inDataLen = inputDataLen;
    this->inData = new double[this->inDataLen];

    this->outDataLen = inputDataLen;
    this->outData = new double[this->outDataLen];


    //低通滤波器输入和输出
    this->lowFilterInData = new double[this->inDataLen];
    this->lowFilterOutData = new double[this->outDataLen];

    // 高通滤波器输入和输出
    this->highFilterInData = new double[this->inDataLen];
    this->highFilterOutData = new double[this->outDataLen];

    //追踪滤波器输入
    this->trackFilterInData = new double[this->inDataLen];
    this->trackFilterOutData = new double[this->outDataLen];

    // 跟踪滤波器参数
    this->M = 32;
    this->mu = 0.01;
    this->omg = 0.001;
    this->W = new double[this->M];
    this->last_frame_M = new double[this->M];
    this->dn = new double[this->inDataLen];
    this->all_frame = new double[this->M + this->inDataLen];

    memset(this->W, 0, sizeof(double)*M);
    memset(this->last_frame_M, 0, sizeof(double)*M);
    memset(this->dn, 0, sizeof(double)*this->inDataLen);


    if (0 != low)
    {
        if (1 == low)
        {
            LowFilter_b = low_1_fenzi;
            LowFilter_a = low_1_fenmu;
            LowFilter_b_len = 5;
            LowFilter_a_len = 5;
        }
        else if (2 == low)
        {
            LowFilter_b = low_2_fenzi;
            LowFilter_a = low_2_fenmu;
            LowFilter_b_len = 8;
            LowFilter_a_len = 8;
        }
        else if (3 == low)
        {
            LowFilter_b = low_3_fenzi;
            LowFilter_a = low_3_fenmu;
            LowFilter_b_len = 7;
            LowFilter_a_len = 7;
        }
        zi_low_Len = LowFilter_b_len - 1;
        zi_low = new double[zi_low_Len];
        memset(zi_low, 0, zi_low_Len * sizeof(double));

        zf_low_Len = LowFilter_b_len - 1;
        zf_low = new double[zf_low_Len];
        memset(zf_low, 0, zf_low_Len * sizeof(double));

    }

    if (0 != high)
    {
        //不同采样频率下的高通滤波器
        switch (fs)
        {
        case 200000:        // 200k的采样频率
            if (1 == high)  //5Hz高通
            {
                HighFilter_b = high_5Hz_200k_fenzi;
                HighFilter_a = high_5Hz_200k_fenmu;
                HighFilter_b_len = 3;
                HighFilter_a_len = 3;
            }
            else if (2 == high) //20Hz高通
            {
                HighFilter_b = high_20Hz_200k_fenzi;
                HighFilter_a = high_20Hz_200k_fenmu;

                HighFilter_b_len = 5;
                HighFilter_a_len = 5;
            }
            else if (3 == high)  //80Hz高通
            {
                HighFilter_b = high_80Hz_200k_fenzi;
                HighFilter_a = high_80Hz_200k_fenmu;

                HighFilter_b_len = 6;
                HighFilter_a_len = 6;
            }
            zi_high_Len = HighFilter_b_len - 1;
            zi_high = new double[zi_high_Len];
            memset(zi_high, 0, zi_high_Len * sizeof(double));

            zf_high_Len = HighFilter_b_len - 1;
            zf_high = new double[zf_high_Len];
            memset(zf_high, 0, zf_high_Len * sizeof(double));
            break;
        case 20000000:       // 20M的采样频率
            if (1 == high)   // 5Hz高通
            {
                HighFilter_b = high_5Hz_20M_fenzi;
                HighFilter_a = high_5Hz_20M_fenmu;

                HighFilter_b_len = 3;
                HighFilter_a_len = 3;
            }
            else if (2 == high) //20Hz高通
            {
                HighFilter_b = high_20Hz_20M_fenzi;
                HighFilter_a = high_20Hz_20M_fenmu;

                HighFilter_b_len = 3;
                HighFilter_a_len = 3;
            }
            else if (3 == high)  //80Hz高通
            {
                HighFilter_b = high_80Hz_20M_fenzi;
                HighFilter_a = high_80Hz_20M_fenmu;

                HighFilter_b_len = 3;
                HighFilter_a_len = 3;
            }
            zi_high_Len = HighFilter_b_len - 1;
            zi_high = new double[zi_high_Len];
            memset(zi_high, 0, zi_high_Len * sizeof(double));

            zf_high_Len = HighFilter_b_len - 1;
            zf_high = new double[zf_high_Len];
            memset(zf_high, 0, zf_high_Len * sizeof(double));
            break;
            //        case 160000000:     //160M采样频率
        case 80000000:     //160M采样频率
            if (1 == high)  //10Hz高通
            {
                HighFilter_b = high_10Hz_160M_fenzi;
                HighFilter_a = high_10Hz_160M_fenmu;

                HighFilter_b_len = 3;
                HighFilter_a_len = 3;
            }
            else if (2 == high)  //20Hz高通
            {
                HighFilter_b = high_20Hz_160M_fenzi;
                HighFilter_a = high_20Hz_160M_fenmu;

                HighFilter_b_len = 3;
                HighFilter_a_len = 3;
            }
            else if (3 == high)  //80Hz高通
            {
                HighFilter_b = high_80Hz_160M_fenzi;
                HighFilter_a = high_80Hz_160M_fenmu;

                HighFilter_b_len = 3;
                HighFilter_a_len = 3;
            }
            zi_high_Len = HighFilter_b_len - 1;
            zi_high = new double[zi_high_Len];
            memset(zi_high, 0, zi_high_Len * sizeof(double));
            zf_high_Len = HighFilter_b_len - 1;
            zf_high = new double[zf_high_Len];
            memset(zf_high, 0, zf_high_Len * sizeof(double));
            break;
        default:
            break;
        }
    }

    if (0 != track)
    {
        memset(this->W, 0, sizeof(double)*this->M);
        memset(this->last_frame_M, 0, sizeof(double)*this->M);
        memset(this->dn, 0, sizeof(double)*this->inDataLen);
    }
}

void filter::allfilter(double *inputdata, int inDataLen, double* outputdata)
{
    for (int j = 0; j < this->inDataLen; j++)
    {
        this->inData[j] = inputdata[j];
    }

    if (0 != this->islow)
    {
        this->filt(LowFilter_b, LowFilter_b_len, LowFilter_a, LowFilter_a_len, this->inData, this->inDataLen,
                   this->zi_low, this->zi_low_Len, this->outData, this->zf_low, this->zf_low_Len);

        for (int j = 0; j < zf_low_Len; j++)
        {
            this->zi_low[j] = this->zf_low[j];
        }

        for (int j = 0; j < this->inDataLen; j++)
        {
            this->inData[j] = this->outData[j];
        }
    }
    if (0 != this->ishigh)
    {
        this->filt(HighFilter_b, HighFilter_b_len, HighFilter_a, HighFilter_a_len, this->inData, this->inDataLen,
                   this->zi_high, this->zi_high_Len, this->outData, this->zf_high, this->zf_high_Len);

        for (int j = 0; j < this->zf_high_Len; j++)
        {
            this->zi_high[j] = this->zf_high[j];
        }

        for (int j = 0; j < this->inDataLen; j++)
        {
            this->inData[j] = this->outData[j];
        }
    }
    if (0 != this->istrack)
    {
        this->trackfilt(this->inData,this->outData);
    }

    for (int j = 0; j < this->inDataLen; j++)
    {
        outputdata[j] = this->outData[j];
    }
}

//void filter::filt(const double b[4], const double a[4], const double indata[1024],
//	const double zi[3], double outdata[1024], double zf[3])
//{

//	int k;
//	double a1;
//	double b_b[4];
//	double b_a[4];
//	int naxpy;
//	int j;
//	for (k = 0; k < 4; k++)
//	{
//		b_b[k] = b[k];
//		b_a[k] = a[k];
//	}

//	a1 = a[0];
//	//分子和分母相对于a1进行归一化
//	if ((!(a[0] == 0.0)) && (a[0] != 1.0))
//	{
//		for (k = 0; k < 4; k++)
//		{
//			b_b[k] /= a1;
//		}

//		for (k = 0; k < 3; k++)
//		{
//			b_a[k + 1] /= a1;
//		}

//		b_a[0] = 1.0;
//	}

//	//滤波后的条件为zf，上次的滤波反馈到本次的初始条件是zi，初始化为0，两者的长度均为分子和分母长度的最大值减1
//	// 滤波后的输出的前len-1个值初始化为zi
//	for (k = 0; k < 3; k++)
//	{
//		zf[k] = 0.0;
//		outdata[k] = zi[k];
//	}

//	//初始化输出的后面所有值为0；
//	memset(&outdata[3], 0, 1021U * sizeof(double));

//	//滤波操作
//	for (k = 0; k < 1024; k++)
//	{
//		naxpy = 1024 - k;
//		if (!(naxpy < 4))
//		{
//			naxpy = 4;
//		}

//		for (j = 0; j < naxpy; j++)
//		{
//			outdata[k + j] += indata[k] * b_b[j];
//		}

//		naxpy = 1023 - k;
//		if (!(naxpy < 3))
//		{
//			naxpy = 3;
//		}

//		a1 = -outdata[k];
//		for (j = 1; j <= naxpy; j++)
//		{
//			outdata[k + j] += a1 * b_a[j];
//		}
//	}

//	for (k = 0; k < 3; k++)
//	{
//		for (j = 0; j < k + 1; j++)
//		{
//			zf[j] += indata[k + 1021] * b_b[(j - k) + 3];
//		}
//	}

//	for (k = 0; k < 3; k++)
//	{
//		for (j = 0; j < k + 1; j++)
//		{
//			zf[j] += -outdata[k + 1021] * b_a[(j - k) + 3];
//		}
//	}

//}

void filter::filt(double* fenzi, int fenziLen, double* fenmu, int fenmuLen, double* indata,
                  int indataLen, double* zi, int ziLen, double* outdata, double* zf, int zfLen)
{
    double a1;
    //double b_b[10];
    //double b_a[10];
    double* b_b = fenzi;
    double* b_a = fenmu;
    int naxpy;

    //for (int k = 0; k < fenziLen; k++)
    //{
    //	b_b[k] = fenzi[k];
    //	b_a[k] = fenmu[k];
    //}

    a1 = fenmu[0];
    //分子和分母相对于a1进行归一化
    if ((!(fenmu[0] == 0.0)) && (fenmu[0] != 1.0))
    {
        for (int k = 0; k < fenziLen; k++)
        {
            b_b[k] /= a1;
        }

        for (int k = 0; k < fenmuLen - 1; k++)
        {
            b_a[k + 1] /= a1;
        }

        b_a[0] = 1.0;
    }

    //滤波后的条件为zf，上次的滤波反馈到本次的初始条件是zi，初始化为0，两者的长度均为分子和分母长度的最大值减1
    // 滤波后的输出的前len-1个值初始化为zi
    for (int k = 0; k < ziLen; k++)
    {
        zf[k] = 0.0;
        outdata[k] = zi[k];
    }

    //初始化输出的后面所有值为0；
    for (int i = ziLen; i < inDataLen; i++)
    {
        outdata[i] = 0;
    }
    //滤波操作
    for (int k = 0; k < inDataLen; k++)
    {
        naxpy = inDataLen - k;
        if (!(naxpy < fenziLen))
        {
            naxpy = fenziLen;
        }

        for (int j = 0; j < naxpy; j++)
        {
            outdata[k + j] += indata[k] * b_b[j];
        }

        naxpy = inDataLen - 1 - k;
        if (!(naxpy < zfLen))
        {
            naxpy = zfLen;
        }

        a1 = -outdata[k];
        for (int j = 1; j <= naxpy; j++)
        {
            outdata[k + j] += a1 * b_a[j];
        }
    }

    //for (int i = 0; i < indataLen; i++)
    //{
    //	cout << 1 + i << " " << outdata[i] << endl;
    //}

    for (int k = 0; k < zfLen; k++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            zf[j] += indata[k + inDataLen - zfLen] * b_b[(j - k) + zfLen];
        }
    }

    for (int k = 0; k < zfLen; k++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            zf[j] += -outdata[k + inDataLen - zfLen] * b_a[(j - k) + zfLen];
        }
    }

    //for (int i = 0; i < zfLen; i++)
    //{
    //	cout << 1 + i << " " << zf[i] << endl;
    //}
}

void filter::trackfilt(double* indata,double* outdata)
{
    for (int i = 0; i < this->M; i++)
    {
        this->all_frame[i] = this->last_frame_M[i];
    }
    for (int i = 0; i < this->inDataLen; i++)
    {
        this->all_frame[this->M + i] = indata[i];
        this->dn[i] = indata[i];
    }

    int itr = this->M + this->inDataLen;  //迭代的总次数
    double y = 0.0; //滤波器输出点
    double en = 0;  //误差
    double x_sum = 0;
    for (int k = this->M-1; k < itr-1; k++)
    {
        x_sum = 0;
        y = 0;
        for (int j = 0; j < this->M; j++)
        {
            y += this->all_frame[k - j] * this->W[j];
            x_sum += this->all_frame[k - j] * this->all_frame[k - j];
        }
        en = this->dn[k+1-this->M] - y;
        for (int j = 0; j < this->M; j++)
        {
            this->W[j] += this->mu / (x_sum + this->omg)*en*this->all_frame[k - j];
        }
        outdata[k - this->M + 1] = y;
    }

    for (int i = 0; i < this->M; i++)
    {
        this->last_frame_M[i] = this->inData[this->inDataLen - this->M + i];
    }
}


filter::~filter()
{
    delete[] inData;

    //输出数据和数据长度
    delete[] outData;

    //低通滤波器输入和输出
    delete[] lowFilterInData;
    delete[] lowFilterOutData;

    delete[] zi_low;
    delete[] zf_low;

    // 高通滤波器输入
    delete[] highFilterInData;
    delete[] highFilterOutData;
    delete[] zi_high;
    delete[] zf_high;


    //追踪滤波器输入
    delete[] trackFilterInData;
    delete[] trackFilterOutData;

    delete[] last_frame_M;
    delete[] W;
    delete[] dn;
    delete[] all_frame;
}
