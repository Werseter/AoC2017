#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        std::string line;
        int sum = 0;
        int x;
        float div;
        bool stop = false;
        while(std::getline(input, line)) {
            std::istringstream stream(line);
            std::vector<int> row;
            while(stream >> x)
                row.push_back(x);
            for(int i = 0; i < row.size(); ++i, stop = false)
                for(int j = i + 1; !stop && j < row.size(); ++j) {
                    div = float(row[i] < row[j] ? row[j] : row[i]) / float(row[i] < row[j] ? row[i] : row[j]);
                    if(div == int(div)) {
                        sum += div;
                        stop = true;
                    }
                }
        }
        std::cout << "Sum is equal to " << sum << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

