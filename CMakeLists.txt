cmake_minimum_required(VERSION 3.21)
project(StockLibrary)

set(CMAKE_CXX_STANDARD 20)

add_library(StockLibrary DataLoad.cpp Candlestick.cpp Candlestick.h Oscillator.cpp Oscillator.h Trade.cpp Trade.h benchmark.cpp benchmark.h matplotlibcpp.h display.cpp display.h)
add_executable(main DataLoad.cpp main.cpp Candlestick.cpp Candlestick.h Oscillator.cpp Oscillator.h Trade.cpp Trade.h benchmark.cpp benchmark.h matplotlibcpp.h display.cpp display.h)

include_directories(C:\\Users\\olive\\AppData\\Local\\Programs\\Python\\Python310)
include_directories(C:\\Users\\olive\\AppData\\Local\\Programs\\Python\\Python310\\lib\\site-packages\\numpy\\core\\include)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(main ${PYTHON_LIBRARIES})