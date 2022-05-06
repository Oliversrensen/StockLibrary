cmake_minimum_required(VERSION 3.21)
project(StockLibrary)

set(CMAKE_CXX_STANDARD 20)

add_library(StockLibrary library.cpp)
add_executable(main library.cpp main.cpp)
