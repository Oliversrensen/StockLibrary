#include <iostream>
#include "Trade.h"
#include "Candlestick.h"
#include <cmath>

Trade SimulateTrade(std::vector<double>& K, std::vector<double>& D, std::vector<Candlestick>& candles, double money, int X){
    Trade trade{};
    trade.money = money;

    bool K_above = false;
    double boughtAt;

    for (int i = 0; i < K.size(); ++i) {
        if(K[i] > D[i]){
            if(!K_above && K[i] >= 80){
                //BUY
                boughtAt = candles[i+X].openingPrice;
                trade.sharesHeld = floor(trade.money / candles[i+X].openingPrice);
                trade.money = fmod(trade.money, candles[i+X].openingPrice);
                std::cout << "Day " << i << ": " << "bought: " << trade.sharesHeld << " shares at a value of: "
                << candles[i+X].openingPrice << " for a total of: " << trade.sharesHeld * candles[i+X].openingPrice
                << " current worth: " << (trade.sharesHeld * candles[i+X].openingPrice) + trade.money << std::endl;
                K_above = true;
            }
        }
        if(K[i] < D[i]){
            if(K_above && K[i] <= 20){
                //SELL
                trade.tradeWorth.push_back((candles[i+X].openingPrice - boughtAt) * trade.sharesHeld);
                trade.money += trade.sharesHeld * candles[i+X].openingPrice;
                std::cout << "Day " << i << ": " << "sold: " << trade.sharesHeld << " shares at a value of: "
                << candles[i+X].openingPrice << " for a total of: " << trade.sharesHeld * candles[i+X].openingPrice <<
                " current worth: " << trade.money << std::endl;
                trade.sharesHeld = 0;
                K_above = false;
            }
        }
    }
    if(trade.sharesHeld > 0){
        trade.tradeWorth.push_back((candles.back().openingPrice - boughtAt) * trade.sharesHeld);
        trade.money += trade.sharesHeld * candles.back().openingPrice;
    }

    std::cout << "Final profits: " << trade.money - money << std::endl;

    return trade;
}