#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        std::vector<int> numbers;
        int i, x;
        while(input >> x) 
            numbers.push_back(x);
        for(x = i = 0; i < numbers.size(); ++numbers[i], i += numbers[i] - 1, ++x);
        std::cout << "Number of required jumps is " << x << " jumps" <<  std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

