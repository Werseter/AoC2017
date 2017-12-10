#include <iostream>
#include <string>
#include <fstream>

class circList {
    private:
        int* arr;
        int size;
    public:
        circList(const int size) {
            this -> arr = new int [size];
            for(int i = 0; i < size; ++i) this -> arr[i] = i;
            this -> size = size;
        }   
        int& operator[] (int i) {
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
        int x;
        int skip = 0, currPos = 0;
        circList arr(256);
        while(input >> x) {
            reverse(arr, currPos, x);
            currPos += x + skip;
            ++skip;
            input.get();
        }
        std::cout << "Result of multiplying first two numbers in the list is " << arr[0] * arr[1] << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 
