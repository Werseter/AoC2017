#include <iostream>

const int input = 325489;

int main(void) {
    int val = 1, depth = 0;
    for(; val < input; ++depth)
        val += (2 + 8*depth);
    std::cout << "The distance is " << (val - input) % (2 * depth) << std::endl;
    return 0;
}
