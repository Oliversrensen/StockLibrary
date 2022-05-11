#include <vector>
#include "../include/Candlestick.h"

//This class is for computing the trajectories of the candles.
std::vector<Candlestick> ComputeCandlesticks(std::vector<Candlestick>&& candles) {
    for (auto & candle : candles) {
        candle.openingPrice = candle.price[0];
        candle.closingPrice = candle.price[candle.sequence.size()-1];
        candle.minPrice = *std::min_element(candle.price.begin(), candle.price.end());
        candle.maxPrice = *std::max_element(candle.price.begin(), candle.price.end());
    }

    return candles;
}

