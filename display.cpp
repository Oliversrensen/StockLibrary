//
// Created by olive on 10/05/2022.
//

#include "display.h"
#include "matplotlibcpp.h"
#include "Candlestick.h"

namespace plt = matplotlibcpp;
void DisplayGraph(const std::vector<Candlestick>& candles, const std::vector<double>& K, const std::vector<double>& D){
    plt::figure_size(1500, 400);
    plt::subplot2grid(2, 1, 0, 0);
    plt:
    plt::subplot2grid(2, 1, 1, 0);
    plt::plot(K, "Red");
    plt::plot(D, "Blue");


    plt::tight_layout();
    plt::show();

    //plt::save("basic.png");

}
