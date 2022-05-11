cmake_minimum_required(VERSION 3.21)
project(StockLibrary)

set(CMAKE_CXX_STANDARD 20)
enable_testing()
add_library(StockLibrary src/DataLoad.cpp src/Candlestick.cpp include/Candlestick.h src/Oscillator.cpp include/Oscillator.h src/Trade.cpp include/Trade.h src/benchmark.cpp include/benchmark.h libs/matplotlibcpp.h src/display.cpp include/display.h)
add_executable(main src/DataLoad.cpp main.cpp src/Candlestick.cpp include/Candlestick.h src/Oscillator.cpp include/Oscillator.h src/Trade.cpp include/Trade.h src/benchmark.cpp include/benchmark.h libs/matplotlibcpp.h src/display.cpp include/display.h)
add_executable(runTest tests/Trade_tests.cpp libs/doctest.h include/Trade.h src/Trade.cpp tests/Oscillator_tests.cpp include/Oscillator.h src/Oscillator.cpp tests/Candlestick_tests.cpp include/Candlestick.h src/Candlestick.cpp)
add_test(NAME runTests COMMAND runTest)

include_directories(C:\\Users\\olive\\AppData\\Local\\Programs\\Python\\Python310)
include_directories(C:\\Users\\olive\\AppData\\Local\\Programs\\Python\\Python310\\lib\\site-packages\\numpy\\core\\include)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(main ${PYTHON_LIBRARIES})