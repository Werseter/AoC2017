#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        std::string line;
        std::string regOut, regIn, op;
        int sign, valOut, valIn, max = 0;
        std::map<std::string, int> reg;
        while(std::getline(input, line)) {
            std::istringstream stream(line);
            stream >> regOut;
            reg.insert(std::make_pair(regOut, 0));
            stream >> op;
            sign = op == "inc" ? 1 : -1;
            stream >> valOut;
            stream >> op;
            stream >> regIn;
            reg.insert(std::make_pair(regIn, 0));
            stream >> op;
            stream >> valIn;
            if(op == "==" && reg[regIn] == valIn ||
               op == "!=" && reg[regIn] != valIn ||
               op == "<=" && reg[regIn] <= valIn ||
               op == ">=" && reg[regIn] >= valIn ||
               op == "<"  && reg[regIn] <  valIn ||
               op == ">"  && reg[regIn] >  valIn) {
                reg[regOut] += sign * valOut;
                max = reg[regOut] > max ? reg[regOut] : max;
            }
        }
        std::cout << "The biggest value to be in the register was " << max << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

