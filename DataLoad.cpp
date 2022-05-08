#include "DataLoad.h"
#include "Candlestick.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<Candlestick> GenerateCandles() {
    std::fstream my_file;

    std::vector<Candlestick> candles;
    Candlestick stick;

    my_file.open(R"(C:\Users\olive\Desktop\json-2y\ALKB.json)");

    if (!my_file) {
        std::cout << "No such file";
    }
    else {
        char ch;
        std::string temp;
        std::string price;

        while (!my_file.eof()) {
            my_file >> ch;
            if(ch == '\"') {
                my_file >> ch;
                while(ch != '\"') {
                    temp += ch;
                    my_file >> ch;
                }
                if(temp == "price"){
                    temp = "";
                    while(ch != '\"'){
                        my_file >> ch;
                    }
                    my_file >> ch;
                    my_file >> ch;
                    while(ch != ','){
                        temp += ch;
                        my_file >> ch;
                    }
                    price = temp;
                }
                if(temp == "seq"){
                    temp = "";
                    while(ch != '\"'){
                        my_file >> ch;
                    }
                    my_file >> ch;
                    my_file >> ch;
                    while(ch != ','){
                        temp += ch;
                        my_file >> ch;
                    }
                    if(std::stoi(temp) == 1){
                        if(!stick.price.empty()){
                            candles.push_back(stick);
                        }
                        stick.price.clear();
                        stick.sequence.clear();
                    }
                    stick.price.push_back(std::stod(price));
                    stick.sequence.push_back(std::stoi(temp));
                }
                temp = "";
            }
        }

    }
    candles.push_back(stick);

    my_file.close();

    return candles;
}

