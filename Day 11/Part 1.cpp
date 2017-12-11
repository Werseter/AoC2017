#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        std::map<std::string, int> moves;
        std::string line, move;
        int offset, sum = 0;
        std::getline(input, line);
        std::istringstream stream(line);
        std::string dirs[] = {"nw", "n", "ne", "se", "s", "sw"}; 
        for(int i = 0; i < 6; moves.insert(std::make_pair(dirs[i], 0)), ++i);
        while(std::getline(stream, move, ',')) ++moves[move];
        for(int i = 0; i < 3; ++i) {
            offset = std::min(moves[dirs[i]], moves[dirs[i + 3]]);
            moves[dirs[i]]     -= offset;
            moves[dirs[i + 3]] -= offset;
         }
        for(int i = 0; i < 6; ++i) {
            offset = std::min(moves[dirs[i]], moves[dirs[(i + 2) % 6]]);
            moves[dirs[i]]           -= offset;
            moves[dirs[(i + 2) % 6]] -= offset;
            moves[dirs[(i + 1) % 6]] += offset;
        }
        for(std::pair<std::string, int> x : moves)
            sum += x.second;
        std::cout << "The fewest number of steps required to reach the child process is " << sum << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

