#include <iostream>
#include <fstream>
#include <vector>
#include <set>

inline int getMax(std::vector<int>& vector) {
    int x = 0;
    for(int i = 1; i < vector.size(); ++i)
        x = vector[i] > vector[x] ? i : x; 
    return x;
}

inline std::string makeState(std::vector<int>& vector) {
    std::string state = ("");
    for(int i = 0; i < vector.size(); ++i)
        state += char(vector[i]);
    return state;
}

inline void balance(std::vector<int>& vector, int i) {
    int j, k;
    for(j = vector[i], k = (i + 1) % vector.size(), vector[i] = 0; j > 0; --j, ++vector[k], ++k %= vector.size());
}

struct cmpr {
    bool operator() (const std::pair<std::string, size_t>& l, const std::pair<std::string, size_t>& r) {
        return l.first < r.first;
    }
};

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        std::vector<int> banks;
        std::set<std::pair<std::string, size_t>, cmpr> states;
        std::string state;
        int x;
        while(input >> x) 
            banks.push_back(x);
        for(int i = getMax(banks); states.insert(std::make_pair(makeState(banks), states.size())).second == true; balance(banks, i), i = getMax(banks));
        std::cout << "Number of redistribution cycles inside the loop is " << states.size() - states.find(std::make_pair(makeState(banks), states.size())) -> second << " jumps" <<  std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

