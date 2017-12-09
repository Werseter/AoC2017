#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

class Node {
    public:
        int weight;
        std::string name;
        Node* root;
        std::vector<Node*> leafs;
        std::vector<std::string> missing;
        Node(std::string name) {
            this -> weight = 0;
            this -> name = name;
            this -> root = nullptr;
        }
    friend bool operator< (Node& x, Node& y) {
        return x.name < y.name;
    }
};

int main(void) {
    std::ifstream input ("input.txt");
    if(input.is_open()) {
        std::string line;
        std::string word;
        int number;
        Node* p;
        std::set<Node*> queue;
        while(std::getline(input, line)) {
            std::istringstream stream(line);
            stream >> word;
            p = new Node(word);
            stream >> word;
            p -> weight = std::stoi(word.substr(1, word.length() - 2));
            if(stream >> word)
                while(stream >> word) {
                    if(word.back() == ',')
                        word = word.substr(0, word.length() - 1);
                    (p -> missing).push_back(word);
                }
            queue.insert(p);
        }
        for(std::set<Node*>::iterator i = queue.begin(); i != queue.end(); ++i) {
            for(std::vector<std::string>::iterator j = ((*i) -> missing).begin(); j != ((*i) -> missing).end(); ++j) {
                std::string name = *j;
                p = *(std::find_if(queue.begin(), queue.end(), [name](const Node* n) {
                    return (n -> name).compare(name) == 0;
                }));
                p -> root = *i;
                ((*i) -> leafs).push_back(p);    
            }
        }
        for(p = *(queue.begin()); p -> root != nullptr; p = p -> root);
        std::cout << "The name of the bottom program is " << p -> name << std::endl;
        for(Node* x : queue)
            delete x;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

