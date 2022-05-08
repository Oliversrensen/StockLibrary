//
// Created by olive on 06/05/2022.
//
#include <iostream>
#include <fstream>
#include "DataLoad.h"
#include "Candlestick.h"
#include "Oscillator.h"
#include "vector"

int main(){

    std::fstream my_fileK;
    std::fstream my_fileD;

    my_fileK.open(R"(C:\Users\olive\Desktop\K_values.txt)");
    my_fileD.open(R"(C:\Users\olive\Desktop\D_values.txt)");


    std::vector<Candlestick> candles = ComputeCandlesticks(GenerateCandles());
    std::reverse(candles.begin(), candles.end());
    std::vector<double> fastIndicators = CalcFastOscillator(candles, 14);
    std::vector<double> slowIndicators = CalcSlowOscillator(fastIndicators, 3);

    for(auto in : fastIndicators){
        my_fileK << in << std::endl;
    }
    for(auto in : slowIndicators){
        my_fileD << in << std::endl;
    }

    return 0;
}