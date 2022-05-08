//
// Created by olive on 07/05/2022.
//

#ifndef STOCKLIBRARY_CANDLESTICK_H
#define STOCKLIBRARY_CANDLESTICK_H


class Candlestick {
public:
    std::vector<double> price;
    std::vector<int> sequence;
    double openingPrice;
    double closingPrice;
    double maxPrice;
    double minPrice;

};

std::vector<Candlestick> ComputeCandlesticks(std::vector<Candlestick>&&);


#endif //STOCKLIBRARY_CANDLESTICK_H
