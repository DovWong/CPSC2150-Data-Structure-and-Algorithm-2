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

    Node* tail;

    SkipList(int maxLevels){
        MAXIMUM_ALLOWED_LEVELS = maxLevels;

        // initially we have the bottom-most level only
        level = 0;
    
        // create the header node, value is irrelevant (as long as it doesn't match an inserted value - NO REPEATS), number of next links is important (this node is connected to the first node at every level)
        head = new Node(INT_MIN, MAXIMUM_ALLOWED_LEVELS);
        tail = new Node(INT_MAX, MAXIMUM_ALLOWED_LEVELS);

        for (int i = 0; i <= MAXIMUM_ALLOWED_LEVELS; i++) {
            head->next[i] = tail;
            tail->prev[i] = head;
        }
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

        Node *current = head; // start at head node
        vector<Node*> update(MAXIMUM_ALLOWED_LEVELS + 1, nullptr); // this will hold the nodes that need updating at every level after the insert takes place
        for (int i = level; i >= 0; i--){
            // for level i, if value is to be inserted here then find out where (i.e. after which node)
            while (current->next[i]->value < value)
                current = current->next[i];
            // found the node after which the value is to be placed at level i
            update[i] = current;
        }
    
        if (current->next[0]->value != value){
            int ranLevel = RandomLevel(); // choose a random level upto where the new node will be placed

            if (ranLevel > level){
                // if random level for current node is higher than the current maximum level for the existing nodes then set updates for each level over current maximum to head (since there are no nodes at these levels yet).
                for (int i = level + 1;i <= ranLevel; i++)
                    update[i] = head;

                // also change the current maximum level for the existing nodes
                level = ranLevel;
            }

            // create new node with next links for every level from ranLevel to zero
            Node* n = CreateNode(value, ranLevel);

            // placing new node in the correct place at every level
            for (int i = 0; i <= ranLevel; i++){
                n->next[i] = update[i]->next[i];
                n->prev[i] = update[i];
                update[i]->next[i] = n;
                n->next[i]->prev[i] = n;
            }
        }
           
    }

    void Delete(int value){
        Node *current = head;
        vector<Node*> update(MAXIMUM_ALLOWED_LEVELS + 1, nullptr);
        vector<Node*> newAfter(MAXIMUM_ALLOWED_LEVELS + 1, nullptr);

        for (int i = level; i >= 0; i--){

            while (current->next[i]->value < value)
                current = current->next[i];

            update[i] = current;

            if (current->next[i]->value == value)
                newAfter[i] = current->next[i]->next[i];
            else
                newAfter[i] = current->next[i];
        }

        current = current->next[0];

        if (current->value != value) {
            cout << value << " is not existed in the list." << endl;
            return;
        }

        delete current;
        current = nullptr;

        bool max = true;

        for (int i = level; i >= 0; i--) {

            update[i]->next[i] = newAfter[i];
            newAfter[i]->prev[i] = update[i];

            if (max && head->next[i] == tail)
                level--;
            else
                max = false;
        }
    }

    bool Search(int value){
        Node *current = head;

        for (int i = level; i >= 0; i--){

            while (current->next[i]->value < value)
                current = current->next[i];

            if (current->next[i]->value == value)
                return true;
        }

        return false;
    }

    void Show(){

        if (head->next[0] == tail) {
            cout << "There are nothing in the list." << endl;
            return;
        }

        for (int i = 0; i <= level; i++){
            Node *node = head->next[i];
            cout << "Level " << i << ": ";
            while (node->next[i] != tail){
                cout << node->value << " -> ";
                node = node->next[i];
            }

            cout << node->value << " .\n";
        }
    }

    //Just for testing the prev
    void ShowBackward(){
        for (int i = 0; i <= level; i++){
            Node *node = tail->prev[i];
            cout << "Level " << i << ": ";

            while (node != head) {
                cout << node->value << " -> ";
                node = node->prev[i];
            }

            cout << "head\n";
        }
    }
};

#endif