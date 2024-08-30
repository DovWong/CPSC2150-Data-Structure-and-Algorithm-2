#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

// the node
class Node{
public:
    int value;
    // Array of pointers to the next nodes (which are located at various levels)
    vector<Node*> next; 
    Node(int val, int level){
        value = val;
        next = vector<Node*>(level+1, nullptr); // initialize array of pointers to nulls
    };
};

#endif