#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

bool isAnagram(std::string a, std::string b) {
    if(a.length() == b.length()) {
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        return a == b;
    }
    return false;
}

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        std::string line;
        std::string word;
        int sum = 0;
        bool stop = false;
        while(std::getline(input, line)) {
            std::istringstream stream(line);
            std::vector<std::string> row;
            while(stream >> word)
                row.push_back(word);
            stop = false;
            for(int i = 0; !stop &&i < row.size(); ++i)
                for(int j = i + 1; !stop && j < row.size(); ++j)
                    if(isAnagram(row[i], row[j])) {
                        --sum;
                        stop = true;
                        std::cout << row[i] << " == " << row[j] << std::endl;
                    }
            ++sum;
        }
        std::cout << "Sum is equal to " << sum << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

