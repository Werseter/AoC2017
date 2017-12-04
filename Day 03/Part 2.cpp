#include <iostream>

const int input = 325489;
const int sidesize = 11;

int getNear(int (&tab)[sidesize][sidesize], int sidesize, int x, int y) {
    int sum = 0;
    for(int i = -1; i < 2; ++i)
        for(int j = -1; j < 2; ++j)
            sum += tab[x + i][y + j];
    return sum;
}

int main(void) {
    int tab[sidesize][sidesize] = {{0}};    
    int depth = 1;
    int val = tab[sidesize / 2][sidesize / 2] = 1;
    int xpos, ypos;
    xpos = ypos = sidesize / 2;
    bool found = false;
    int plusOne  = 1;
    int minusOne = -1;
    int* const moves[4][2] = {{&ypos, &minusOne}, {&xpos, &minusOne}, {&ypos, &plusOne}, {&xpos, &plusOne}};
    while(!found) {
        ++xpos;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; !found && j <= depth; *(moves[i][0]) += *(moves[i][1]), ++j) {
                val = tab[xpos][ypos] = getNear(tab, sidesize, xpos, ypos);
                if(val > input)
                    found = true;
            }
            *(moves[i][0]) -= *(moves[i][1]);
            if(i != 3)
                *(moves[i + 1][0]) += *(moves[i + 1][1]);
        }
        depth += 2;
    }
        std::cout << "The first number written that is larger than input is " << val << std::endl;
    return 0;
}
