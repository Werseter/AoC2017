#include <iostream>
#include <fstream>

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        int sum = 0;
        int score = 0;
        char x;
        while(input >> x) {
            if(x == '{')
                ++score;
            else if(x == '}')
                sum += score, --score;
            else if(x == '!')
                input.get();
            else if(x == '<')
                while(x != '>')
                    input >> x, x != '!' ? : input.get();  
        }
        std::cout << "Total score is equal to " << sum << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

