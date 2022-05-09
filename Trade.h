#ifndef STOCKLIBRARY_TRADE_H
#define STOCKLIBRARY_TRADE_H


#include <vector>
#include "Candlestick.h"

class Trade {
public:
    int sharesHeld;
    double money;
    std::vector<double> tradeWorth;
};

Trade SimulateTrade(std::vector<double>&, std::vector<double>&, std::vector<Candlestick>&, double, int);


#endif //STOCKLIBRARY_TRADE_H
