#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int mod(const int& a, const int& b) {
    return a < 0 ? a % b + b : a % b;
}

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        std::map<std::string, std::pair<int, int>> moves;
        std::string line, move;
        int dist = 0, max = 0;
        std::getline(input, line);
        std::istringstream stream(line);
        std::string dirs[] = {"nw", "n", "ne", "se", "s", "sw"}; 
        for(int i = 0; i < 6; moves.insert(std::make_pair(dirs[i], std::make_pair(0, i))), ++i);
        while(std::getline(stream, move, ',')) {
            ++moves[move].first;
            if(moves[dirs[mod(moves[move].second + 3, 6)]].first != 0) {
                --moves[move].first;
                --moves[dirs[mod(moves[move].second + 3, 6)]].first; 
                dist -= 2;
            }
            else if(moves[dirs[mod(moves[move].second + 2, 6)]].first != 0) {
                --moves[move].first;
                --moves[dirs[mod(moves[move].second + 2, 6)]].first; 
                ++moves[dirs[mod(moves[move].second + 1, 6)]].first;
                --dist;
            }
            else if(moves[dirs[mod(moves[move].second - 2, 6)]].first != 0) {
                --moves[move].first;
                --moves[dirs[mod(moves[move].second - 2, 6)]].first; 
                ++moves[dirs[mod(moves[move].second - 1, 6)]].first;
                --dist;
            }
            ++dist;
            max = dist > max ? dist : max;
        }
        std::cout << "The furthest away he ever got from starting point is " << max << " steps" << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

