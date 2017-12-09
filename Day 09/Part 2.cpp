#include <iostream>
#include <fstream>

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        int sum = 0;
        char x;
        while(input >> x) {
            if(x == '!')
                input.get();
            else if(x == '<') {
                while(x != '>')
                    input >> x, x == '!' ? input.get() : ++sum;
                --sum;
            }
        }
        std::cout << "There are " << sum << " non-cancelled characters within the garbage" << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

