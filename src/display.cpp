//
// Created by olive on 10/05/2022.
//

#include "../include/display.h"
#include "../libs/matplotlibcpp.h"
#include "../include/Candlestick.h"

namespace plt = matplotlibcpp;
void DisplayGraph(const std::vector<Candlestick>& candles, const std::vector<double>& K, const std::vector<double>& D){
    plt::figure_size(1400, 400);

    std::vector<double> closingPrices;
    for (int i = 14; i < candles.size(); ++i) {
        closingPrices.push_back(candles[i].closingPrice);
    }
    plt::subplot2grid(2, 1, 0, 0);
    plt::title("Closing prices for ALKB");
    plt::plot(closingPrices, "Green");
    plt::subplot2grid(2, 1, 1, 0);
    plt::title("Indicators");
    plt::plot(D, "Red");
    plt::plot(K, "Blue");

    plt::tight_layout();
    plt::show();

    //plt::save("basic.png");

}
