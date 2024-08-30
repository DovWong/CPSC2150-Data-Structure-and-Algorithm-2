#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include "Node.h"


#ifndef SKIPLIST_H
#define SKIPLIST_H

using namespace std;

class SkipList{
public:
    // Maximum number of levels allowed for this skip list
    int MAXIMUM_ALLOWED_LEVELS;
 
    // current maximum level amongst the inserted nodes
    int level;
    
    // the head node's next links are connected to the first node at every level
    Node *head;

    SkipList(int maxLevels){
        MAXIMUM_ALLOWED_LEVELS = maxLevels;

        // initially we have the bottom-most level only
        level = 0;
    
        // create the header node, value is irrelevant (as long as it doesn't match an inserted value - NO REPEATS), number of next links is important (this node is connected to the first node at every level)
        head = new Node(INT_MIN, MAXIMUM_ALLOWED_LEVELS);
    }

    int RandomLevel(){
        float probablity = (float)rand()/RAND_MAX; // flip a coin
        int lvl = 0;
        while (probablity < 0.5 && lvl < MAXIMUM_ALLOWED_LEVELS){
            lvl++; // landed heads so increase level by 1
            probablity = (float)rand()/RAND_MAX; // flip a coin again
        }
        return lvl;        
    }

    Node* CreateNode(int value, int level){
        // create a new node with next links for every level that this node will be part of
        // it will use these links to connect to the next node at each level  
        return new Node(value, level);
    }

    void InsertElement(int value){

        /**
         * THIS CODE HAS A BUG, 
         * 
         * ***********FIND THE BUG, 
         * *************EXPLAIN THE WHY THE BUG EXIST 
         * AND 
         * **********************SUGGEST A FIX         * 
         * 
         */

        Node *current = head; // start at head node
        vector<Node*> update(MAXIMUM_ALLOWED_LEVELS+1, nullptr); // this will hold the nodes that need updating at every level after the insert takes place
        for (int i = level; i >= 0; i--){
            // for level i, if value is to be inserted here then find out where (i.e. after which node)
            while (current->next[i] != nullptr && current->next[i]->value < value){
                current = current->next[i];
            }
            // found the node after which the value is to be placed at level i
            update[i] = current;
        }    
        
        current = current->next[0];
    
        if (current == nullptr || current->value != value){
            int ranLevel = RandomLevel(); // choose a random level upto where the new node will be placed
    
            if (ranLevel > level){
                // if random level for current node is higher than the current maximum level for the existing nodes then set updates for each level over current maximum to head (since there are no nodes at these levels yet).
                for (int i=level;i<=ranLevel;i++){
                    update[i] = head;
                }
    
                // also change the current maximum level for the existing nodes
                level = ranLevel;
            }
    
            // create new node with next links for every level from ranLevel to zero
            Node* n = CreateNode(value, ranLevel);
    
            // placing new node in the correct place at every level
            for (int i=0;i<=ranLevel;i++){
                n->next[i] = update[i]->next[i];
                update[i]->next[i] = n;
            }
        }
           
    }

    void Delete(int value){
        // TO BE COMPLETED
        // remove value from skip list (all levels) if it exists (output a message if it does not exist)
    }

    bool Search(int value){
        // TO BE COMPLETED
        // search for value in skip list and return true if it exists; false otherwise
    }

    void Show(){
        for (int i=0;i<=level;i++){
            Node *node = head->next[i];
            cout << "Level " << i << ": ";
            while (node != nullptr && node->next[i] != nullptr){
                cout << node->value << " -> ";
                node = node->next[i];
            }
            cout << node->value << " .\n";
        }
    }
};

#endif