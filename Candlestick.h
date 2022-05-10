#ifndef STOCKLIBRARY_CANDLESTICK_H
#define STOCKLIBRARY_CANDLESTICK_H


#include <string>

class Candlestick {
public:
    std::vector<double> price;
    std::vector<int> sequence;
    std::vector<std::string> time;
    double openingPrice;
    double closingPrice;
    double maxPrice;
    double minPrice;

};

std::vector<Candlestick> ComputeCandlesticks(std::vector<Candlestick>&&);


#endif //STOCKLIBRARY_CANDLESTICK_H
