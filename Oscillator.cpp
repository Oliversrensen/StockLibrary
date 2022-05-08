//
// Created by olive on 08/05/2022.
//

#include "Oscillator.h"
#include "Candlestick.h"
#include <vector>
#include <iostream>

std::vector<double> CalcFastOscillator(const std::vector<Candlestick>& candles, const int X){

    std::vector<double> indicators;

    double C, L, H;
    
    for (int i = X; i < candles.size(); i++) {

        C = candles[i-1].closingPrice;
        L = candles[i-1].minPrice;
        H = candles[i-1].maxPrice;

        for (int j = i-X; j < i; j++) {
            if(L > candles[j].minPrice){
                L = candles[j].minPrice;
            }
            if(H < candles[j].maxPrice){
                H = candles[j].maxPrice;
            }
        }

        indicators.push_back(GetKValue(C, H, L));
        //std::cout << "C: " << C << " H: " << H << " L: " << L << " K: " << GetKValue(C, H, L) << std::endl;
        //std::cout << GetKValue(C, H, L) << std::endl;

    }
    return indicators;
}

std::vector<double> CalcSlowOscillator(const std::vector<double>& KValues, const int Y) {
    std::vector<double> indicators;

    double temp = 0;

    for (int i = 0; i < KValues.size(); i++) {
        if(i < Y) {
            indicators.push_back(KValues[i]);
            //std::cout << "IF: " << KValues[i]<< std::endl;
        }
        else{
            for (int j = i-Y; j < i; j++) {
                temp += KValues[j];
            }
            temp /= Y;
            //std::cout << "TEMP: " << temp << std::endl;
            indicators.push_back(temp);
            temp = 0;
        }
    }

    return indicators;
}

double GetKValue(const double C, const double H, const double L){
    return ((C-L)/(H-L))*100;
}