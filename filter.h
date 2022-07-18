#pragma once


class filter
{
public:
	int samplerate;

	int islow, ishigh, istrack;

	//输入数据和数据长度
	double* inData;
	int inDataLen;

	//输出数据和数据长度
	double* outData;
	int outDataLen;

	//低通滤波器输入和输出
	double* lowFilterInData;
	double* lowFilterOutData;

	// 高通滤波器输入
	double* highFilterInData;
	double* highFilterOutData;

	//追踪滤波器输入
	double* trackFilterInData;
	double* trackFilterOutData;

	//跟踪滤波器的参数设置
	int M;     //  阶数
	double* W; //  滤波器系数
	double mu;    //  步长系数，越小时最终收敛后的误差越小，收敛越慢
	double omg;   //  增量因子，避免分母过小引起的无穷
	double* last_frame_M; //储存上一帧的最后M个数据

	double* all_frame;  // 本帧前拼接上一帧保留的M点
	double* dn;         // 期望的数据，用原始数据代替

	//高通滤波器的分子、分母、分子长度、分母长度
	double* HighFilter_b; double* HighFilter_a; int HighFilter_a_len, HighFilter_b_len;
	
	//高通初始状态和最终状态，本帧的最终状态作为下一帧滤波的初始状态输入到滤波函数中
	double* zi_high; int zi_high_Len;
	double* zf_high; int zf_high_Len;

	//低通滤波器的分子、分母、分子长度、分母长度
	double* LowFilter_b;  double* LowFilter_a; int LowFilter_a_len, LowFilter_b_len;

	//低通初始状态和最终状态，本帧的最终状态作为下一帧滤波的初始状态输入到滤波函数中
	double* zi_low; int zi_low_Len;
	double* zf_low; int zf_low_Len;

	
	double* TrackingFilter;

public:
	filter();
	~filter();
	          // 采样频率  //3个低通  //3个高通  // 跟踪滤波
	void setfilter(int fs, int,int low, int high, int track);//设置是否滤波函数

	void allfilter(double*,int, double*);// 整体滤波函数
	          
//	void filt(const double b[4], const double a[4], const double indata[1024],
//		const double zi[3], double outdata[1024], double zf[3]);
	void filt(double* fenzi,int fenziLen,double* fenmu,int fenmuLen, double* indata,int indataLen, 
		double* zi,int ziLen,double* outdata,double* zf,int zfLen);
	void trackfilt(double*,double*);

};

