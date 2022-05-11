//
// Created by olive on 11/05/2022.
//

#include <iostream>
#include <cmath>
#include "../libs/doctest.h"
#include "../include/Oscillator.h"

TEST_CASE("Test fast oscillator"){
    std::vector<Candlestick> candles;

    Candlestick candle1;
    candle1.closingPrice = 200;
    candle1.maxPrice = 220;
    candle1.minPrice = 180;
    candles.push_back(candle1);

    Candlestick candle2;
    candle2.closingPrice = 240;
    candle2.maxPrice = 280;
    candle2.minPrice = 180;
    candles.push_back(candle2);

    auto indicators = CalcFastOscillator(candles, 1);

    CHECK(indicators[0] == 50);
}

TEST_CASE("Test slow oscillator"){
    std::vector<double> Kvalues = {30, 20, 50, 60, 80};

    auto indicators = CalcSlowOscillator(Kvalues, 3);
    std::vector<double> acceptValues = {30, 20, 50, 33.34, 43.34};

    for (int i = 0; i < indicators.size(); ++i) {
        CHECK(std::ceil(indicators[i] * 100.0) / 100.0 == acceptValues[i]);
    }
}