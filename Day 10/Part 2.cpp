#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

class circList {
    private:
        char* arr;
        int size;
    public:
        circList(const int size) {
            this -> arr = new char [size];
            for(int i = 0; i < size; ++i) this -> arr[i] = i;
            this -> size = size;
        }   
        char& operator[] (int i) {
            return this -> arr[i % size];
        }
};

void reverse(circList& arr, int currPos, int length) {
    for(int i = 0; i < length / 2; ++i)
        std::swap(arr[currPos + i], arr[currPos + length - i - 1]);
}

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        char x;
        int skip = 0, currPos = 0;
        circList arr(256);
        std::vector<char> lengths;
        input >> std::noskipws;
        while(input >> x)
            lengths.push_back(x);
        lengths.pop_back();
        lengths.insert(lengths.end(), {17, 31, 73, 47, 23});
        for(int i = 0; i < 64; ++i)
            for(char x : lengths) {
                reverse(arr, currPos, x);
                currPos += x + skip++;
            }
        unsigned char hash[16] = {0};
        for(int i = 0; i < 16; ++i)
            for(int j = 0; j < 16; ++j)
                hash[i] ^= arr[16 * i + j];
        std::cout << "The knot hash of the puzzle input is ";
        for(unsigned char x : hash) {
            std::cout << std::hex << std::setfill('0') << std::setw(2) << +x;
        }
        std::cout << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 
