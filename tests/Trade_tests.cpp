//
// Created by olive on 11/05/2022.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../libs/doctest.h"
#include "../include/Trade.h"

TEST_CASE("Test sorting lambda"){
    Trade trade{};
    trade.sellWorth = {1, 2, 4, 5, 1, 2, -1};
    std::vector<double> sorted = {5, 4, 2, 2, 1, 1, -1};
    trade = SortTrades(trade);
    CHECK(trade.sellWorth == sorted);
}