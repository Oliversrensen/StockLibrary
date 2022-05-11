//
// Created by olive on 11/05/2022.
//

#include <vector>
#include "../libs/doctest.h"
#include "../include/Candlestick.h"

TEST_CASE("Test the generation of candle trajectories"){
    Candlestick candle;
    std::vector<double> prices = {200, 300, 221, 450, 150};
    std::vector<int> sequence = {1, 2, 3, 4, 5};
    candle.price = prices;
    candle.sequence = sequence;
    std::vector<Candlestick> candleVector;
    candleVector.push_back(candle);
    auto finalCandles = ComputeCandlesticks(std::move(candleVector));

    CHECK(finalCandles[0].maxPrice == 450);
    CHECK(finalCandles[0].minPrice == 150);
    CHECK(finalCandles[0].openingPrice == 200);
    CHECK(finalCandles[0].closingPrice == 150);
}