#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        std::string line;
        int sum = 0;
        int min, max, x;
        while(std::getline(input, line)) {
            std::istringstream stream(line);
            stream >> x;
            min = max = x;
            while(stream >> x) {
                if(x > max)
                    max = x;
                if(x < min)
                    min = x;
            }
            sum += (max - min);
        }
        std::cout << "Sum is equal to " << sum << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 
