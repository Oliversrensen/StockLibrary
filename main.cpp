#include <iostream>
#include <future>
#include "include/DataLoad.h"
#include "include/Candlestick.h"
#include "include/Oscillator.h"
#include "vector"
#include "include/Trade.h"
#include "include/benchmark.h"
#include "include/display.h"

int main(){

    benchmark bm{};

    //Benchmarking & Parallel demonstration
    if(true) {
        vector<std::string> fileNames = {"ALKB.json", "BAVA.json", "BO.json", "CARLA.json", "EAC.json"};

        vector<future<vector<Candlestick>>> futures;

        std::cout << "Benchmarking the loading of data. First sequentially, then using async" << std::endl;
        bm.mark();
        for (auto &file: fileNames) {
            GenerateCandles(file);
        }
        bm.mark();
        futures.reserve(fileNames.size());
        for (auto &file: fileNames) {
            futures.push_back(std::async( GenerateCandles, file));
        }
        for (auto &future: futures) {
            future.get();
        }
        bm.mark();
        bm.report();
        std::cout << "As shown, async is faster, nearly achieving a speedup of 2. This is running on Windows. When run on a linux system, the speedup gets closer to 3";
        std::cout << std::endl;
    }

    //Load files and compute trajectories
    auto candles = ComputeCandlesticks(GenerateCandles("ALKB.json"));

    //Reverse order of candlesticks, the dataset is backwards
    std::reverse(candles.begin(), candles.end());

    //Calculate oscillator indicators
    std::vector<double> fastIndicators = CalcFastOscillator(candles, 15);
    std::vector<double> slowIndicators = CalcSlowOscillator(fastIndicators, 5);

    //Simulating trade strategy with Indicators, candles, start money and the X-value used by the CalcFastOscillator
    Trade trades = SimulateTrade(fastIndicators, slowIndicators, candles, 10000, 15);

    std::cout << "Unsorted list of sells:" << std::endl;
    for(auto & trade : trades.sellWorth) {
        std::cout << trade << std::endl;
    }

    //Sorting using a lambda function
    trades = SortTrades(trades);

    std::cout << "Sorted list of sells:" << std::endl;
    for(auto & trade : trades.sellWorth) {
        std::cout << trade << std::endl;
    }

    //Display graph.
    DisplayGraph(candles, fastIndicators, slowIndicators);

    return 0;
}