#pragma once
#include <iostream>
#include <cmath>
#include<string>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <sstream>

#include "fftw3.h"

void hanningWin(int Len, double* win, double &sum_win);

void spectrumDisp(double* data, int dataLen, int fs, int bandf, int spectrumflg, double*  pxx);

void rmsComupt(double* pxx, double fbegin, double fend, double fs, double N, double& rms);
