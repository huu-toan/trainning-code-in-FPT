#include <iostream>
using namespace std;

int start = 0;

class Node {
    public:
        void Data () {

        };

        int *ptr = &start;

        Node *next_node_ptr;

        Node() {
            next_node_ptr = nullptr;
        }
};
