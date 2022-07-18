#include "spectrumDisp.h"
#include <fstream>


#define pi (4*atan(1))

/*
	����
	  ��������    double* data
	  �����ܳ���  int     dataLen
	  ����Ƶ��    double  fs
	  ����        double  band
	  ѡ���־    int     spectrumflg    Ϊ0������Ƶ�ף�Ϊ1�����㹦����

	���
	  �������  double* pxx       ������ʾ��������  ����ΪoutLen
	  ���Ƶ��  double* f         ������ʾ�ĺ�����  ����ΪoutLen
	  �������  int     outLen    ���ε���ʾ���ȣ���0~outLen-1
	*/

void rmsComupt(double* pxx, double fbegin, double fend, double fs, double N, double& rms)
{
	double sumpxx = 0;
	int fbeignN = (double)fbegin / (double)fs * (double)N;
	int fendN = (double)fend / (double)fs * (double)N;

	for (int ii = fbeignN; ii < fendN; ii++)
	{
		sumpxx += pxx[ii] * pxx[ii];
	}
	sumpxx = sumpxx / (fendN - fbeignN);
	rms = sqrt(sumpxx);
}

/*
spectrumDisp(double* data,int dataLen,int fs,int bandf,int spectrumflg,double*  pxx,double* f,int &dispLen)
����
  ��������    double* data
  �����ܳ���  int     dataLen
  ����Ƶ��    double  fs
  ����        double  band
  ѡ���־    int     spectrumflg    Ϊ0������Ƶ�ף�Ϊ1�����㹦����

���
  �������  double* pxx
  ���Ƶ��  double* f
  �������  int     outLen
*/

void spectrumDisp(double* data, int dataLen, int fs, int bandf, int spectrumflg, double*  pxx)
{

//    std::ofstream dataout("dataout.txt");

//    for(int i=0;i<dataLen;i++)
//    {
//        dataout<<data[i]<<std::endl;
//    }
//    dataout.close();

	int N = dataLen;
	int bandN = (double)bandf / (double)fs * (double)N;
    //dispLen = bandN;

	if (0 == spectrumflg)
	{
		fftw_complex *din, *out;
		fftw_plan p;
		din = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N);
		out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N);
		if ((din == NULL) || (out == NULL))
		{
			printf("Error:insufficient available memory\n");
			return;
		}
		else
		{
			for (int i = 0; i < N; i++)/*��������*/
			{
				din[i][0] = data[i];
				din[i][1] = 0;
			}
		}

		p = fftw_plan_dft_1d(N, din, out, FFTW_FORWARD, FFTW_ESTIMATE);
		fftw_execute(p); /* repeat as needed */


		pxx[0] = sqrt(out[0][0] * out[0][0] + out[0][1] * out[0][1]) / (double)N;
        for (int i = 1; i < N; i++)/*��������*/
		{
			pxx[i] = 2 * sqrt((out[i][0] * out[i][0] + out[i][1] * out[i][1])) / (double)N;
		}

		fftw_destroy_plan(p);
		fftw_cleanup();

		if (din != NULL) fftw_free(din);
		if (out != NULL) fftw_free(out);
	}

	if (1 == spectrumflg)
	{
		fftw_complex *din, *out;
		fftw_plan p;
		din = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N);
		out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N);

		double sum_win = 0;
		double delf = (double)fs / (double)dataLen;
		double* win = new double[dataLen]();
		double* win_data = new double[dataLen]();

		hanningWin(dataLen, win, sum_win);
		for (int ii = 0; ii < dataLen; ii++)
		{
			win_data[ii] = win[ii] * data[ii];
		}

		if ((din == NULL) || (out == NULL))
		{
			printf("Error:insufficient available memory\n");
			return;
		}
		else
		{
			for (int i = 0; i < N; i++)/*��������*/
			{
				din[i][0] = win_data[i];
				din[i][1] = 0;
			}
		}
		p = fftw_plan_dft_1d(N, din, out, FFTW_FORWARD, FFTW_ESTIMATE);
		fftw_execute(p); /* repeat as needed */

		pxx[0] = sqrt((out[0][0] * out[0][0] + out[0][1] * out[0][1]) / (sum_win*sum_win) / delf);
        for (int i = 1; i < N; i++)/*��������*/
		{
			pxx[i] = sqrt(2 * (out[i][0] * out[i][0] + out[i][1] * out[i][1]) / (sum_win*sum_win) / delf);
		}
		delete[] win_data;
		delete[] win;

		fftw_destroy_plan(p);
		fftw_cleanup();

		if (din != NULL) fftw_free(din);
		if (out != NULL) fftw_free(out);
	}

//	for (int ii = 0; ii < bandN; ii++)
//	{
//		f[ii] = (double)ii * (double)fs / (double)N;

//	}
}

void hanningWin(int Len, double* win, double &sum_win)
{
	int m = 0;
	if (Len % 2)
	{
		m = (Len + 1) / 2;
	}
	else
	{
		m = (Len) / 2;
	}

	for (int ii = 0; ii < m; ii++)
	{
		win[ii] = 0.5*(1 - cos(2 * pi*(double)(ii) / (double)(Len + 1)));
		win[Len - 1 - ii] = win[ii];
	}
	sum_win = 0;
	for (int ii = 0; ii < Len; ii++)
	{
		sum_win += win[ii];
	}
}
