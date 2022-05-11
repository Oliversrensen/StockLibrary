#include <iostream>
#include "../include/Trade.h"
#include <cmath>

Trade SimulateTrade(std::vector<double>& K, std::vector<double>& D, std::vector<Candlestick>& candles, double money, int X){
    Trade trade{};
    trade.money = money;

    bool K_above = false;
    double boughtAt;

    for (int i = 0; i < K.size(); ++i) {
        if(K[i] > D[i]){
            if(!K_above && K[i] <= 20){
                //BUY
                boughtAt = candles[i+X].openingPrice;
                trade.sharesHeld = floor(trade.money / boughtAt);
                trade.money = fmod(trade.money, boughtAt);
                std::cout << "Day " << i << " at " << candles[i+X].time[0] << " bought: " << trade.sharesHeld
                << " shares for a total of: " << trade.sharesHeld * boughtAt << " current worth: "
                << (trade.sharesHeld * boughtAt) + trade.money << std::endl;
                K_above = true;
            }
        }
        if(K[i] < D[i]){
            if(K_above && K[i] >= 80){
                //SELL
                trade.sellWorth.push_back((candles[i + X].openingPrice - boughtAt) * trade.sharesHeld);
                trade.money += trade.sharesHeld * candles[i+X].openingPrice;
                std::cout << "Day " << i << " at " << candles[i+X].time[0] << " sold: " << trade.sharesHeld
                << " shares for a total of: " << trade.sharesHeld * candles[i+X].openingPrice <<
                " current worth: " << trade.money << std::endl;
                trade.sharesHeld = 0;
                K_above = false;
            }
        }
    }
    if(trade.sharesHeld > 0){
        trade.sellWorth.push_back((candles.back().openingPrice - boughtAt) * trade.sharesHeld);
        trade.money += trade.sharesHeld * candles.back().openingPrice;
    }

    std::cout << "Final profits: " << trade.money - money << std::endl << std::endl;

    return trade;
}

Trade SortTrades(Trade& trade){
    std::sort(trade.sellWorth.begin(), trade.sellWorth.end(),
              [](const auto& a, const auto& b){return a > b;});

    return trade;
}