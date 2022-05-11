#ifndef STOCKLIBRARY_OSCILLATOR_H
#define STOCKLIBRARY_OSCILLATOR_H

#include <vector>
#include "Candlestick.h"

double GetKValue(double, double, double);
std::vector<double> CalcFastOscillator(const std::vector<Candlestick>&, int);
std::vector<double> CalcSlowOscillator(const std::vector<double>&, int);

#endif //STOCKLIBRARY_OSCILLATOR_H
