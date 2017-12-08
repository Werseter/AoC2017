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
        int totalWeight;
        std::string name;
        Node* root;
        std::vector<Node*> leafs;
        std::vector<std::string> missing;
        Node(std::string name) {
            this -> weight = 0;
            this -> totalWeight = 0;
            this -> name = name;
            this -> root = nullptr;
        }
    friend bool operator< (Node& x, Node& y) {
        return x.name < y.name;
    }
};

void getTotal(Node* p) {
    for(Node* q : p -> leafs)
        getTotal(q);
    p -> totalWeight += p -> weight;
    p -> root -> totalWeight += p -> totalWeight;
}
    

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
        for(Node* q : p -> leafs) {
            getTotal(q);
            std::cout << "Leaf " << q -> name << " weights " << q -> totalWeight << std::endl;
        }
        for(bool leave = false; !leave;) {
            for(int i = 0; i < (p -> leafs).size(); ++i) {
                leave = true;
                int temp = (p -> leafs)[i] -> totalWeight;
                if(std::count_if((p -> leafs).begin(), (p -> leafs).end(), [temp](const Node* n) {
                    return (n -> totalWeight) == temp;
                }) == 1) {
                    leave = false;
                    p = (p -> leafs)[i];
                    break;
                }
            }
        }
        Node* q = (p -> root -> leafs)[0];
        if(p == q)
            q = (p -> root -> leafs)[1];
        std::cout << "The weight of the block " << p -> name << " would have to be " << p -> weight - (p -> totalWeight - q -> totalWeight) << std::endl;
        return 0;
    }
    else {
        std::cout << "Failed to open input.txt file" << std::endl;
        return 1;
    }
} 

