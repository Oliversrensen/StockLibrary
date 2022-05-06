#include "library.h"
#include <iostream>
#include <fstream>
#include <string>


void hello() {
    std::cout << "Hello, World!" << std::endl;
}

void parseFile() {
    std::fstream my_file;
    std::fstream my_file2;

    my_file.open(R"(C:\Users\olive\Desktop\json-2y\ALKB.json)");
    my_file2.open(R"(C:\Users\olive\Desktop\WriteToThis.txt)");

    if (!my_file) {
        std::cout << "No such file";
    }
    else {
        char ch;
        std::string temp;

        while (!my_file.eof()) {
            my_file >> ch;
            if(ch == '\"') {
                my_file >> ch;
                while(ch != '\"') {
                    temp += ch;
                    my_file >> ch;
                }
                if(temp == "price"){
                    std::cout << "Price!";
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
                    my_file2 << temp;
                    my_file2 << "\n";
                }
                temp = "";
            }

        }

    }
    my_file.close();
    my_file2.close();
}