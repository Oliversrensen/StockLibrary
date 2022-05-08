cmake_minimum_required(VERSION 3.21)
project(StockLibrary)

set(CMAKE_CXX_STANDARD 20)

add_library(StockLibrary DataLoad.cpp Candlestick.cpp Candlestick.h Oscillator.cpp Oscillator.h)
add_executable(main DataLoad.cpp main.cpp Candlestick.cpp Candlestick.h Oscillator.cpp Oscillator.h)
