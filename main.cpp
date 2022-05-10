#include <iostream>
#include <fstream>
#include <thread>
#include <future>
#include "DataLoad.h"
#include "Candlestick.h"
#include "Oscillator.h"
#include "vector"
#include "Trade.h"
#include "benchmark.h"

int main(){

    benchmark bm{};

    //std::fstream my_fileK;
    //std::fstream my_fileD;

   // my_fileK.open(R"(C:\Users\olive\Desktop\K_values.txt)");
    //my_fileD.open(R"(C:\Users\olive\Desktop\D_values.txt)");

    vector<std::string> fileNames = {"ALKB.json", "BAVA.json", "BO.json", "CARLA.json", "EAC.json", "PAALB.json", "RBREW.json"};

    vector<future<vector<Candlestick>>> futures;

    bm.mark();
    for(auto & file : fileNames){
        GenerateCandles(file);
    }
    bm.mark();
    futures.reserve(fileNames.size());
    for(auto & file : fileNames){
        futures.push_back(std::async(std::launch::async, GenerateCandles, file));
    }
    for(auto & future : futures){
        future.get();
    }
    bm.mark();
    bm.report();


/*
    std::cout << candles[0].openingPrice << std::endl;
    std::cout << candles2[0].openingPrice << std::endl;

    std::reverse(candles.begin(), candles.end());
    std::vector<double> fastIndicators = CalcFastOscillator(candles, 14);
    std::vector<double> slowIndicators = CalcSlowOscillator(fastIndicators, 5);

    Trade trades = SimulateTrade(fastIndicators, slowIndicators, candles, 10000, 14);

    trades = SortTrades(trades);

    for(auto & trade : trades.sellWorth) {
        std::cout << trade << std::endl;
    }

    for(auto &in : fastIndicators){
        my_fileK << in << std::endl;
    }
    for(auto &in : slowIndicators){
        my_fileD << in << std::endl;
    }


*/
    return 0;
}