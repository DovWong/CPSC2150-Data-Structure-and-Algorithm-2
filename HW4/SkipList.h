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

        for (int i = level; i >= 0; i--){

            while (current->next[i]->value < value)
                current = current->next[i];

            if (current->next[i]->value == value) {
                current = current->next[i];
                break;
            }
        }

        if (current->value != value) {
            cout << value << " is not existed in the list." << endl;
            return;
        }

        bool max = true;

        for (int i = level; i >= 0; i--) {

            if (current->next.size() < i + 1)
                continue;

            current->prev[i]->next[i] = current->next[i];
            current->next[i]->prev[i] = current->prev[i];
            current->next[i] = nullptr;
            current->prev[i] = nullptr;

            if (max && head->next[i] == tail)
                level--;
            else
                max = false;
        }

        delete current;
        current = nullptr;
    }

    void DeleteAll() {

        Node* cur = head->next[0];
        Node* del;

        while (cur != tail) {

            del = cur;
            cur = cur->next[0];

            for (int i = 0; i <= level; i++) {

                if (del->next[i] == nullptr)
                    break;

                del->prev[i] = nullptr;
                del->next[i] = nullptr;
            }

            delete del;
            del = nullptr;
        }

        level = 0;

        for (int i = 0; i <= MAXIMUM_ALLOWED_LEVELS; i++) {
            head->next[i] = tail;
            tail->prev[i] = head;
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

    ~SkipList() {
        DeleteAll();

        for (int i = 0; i <= MAXIMUM_ALLOWED_LEVELS; i++) {
            head->next[i] = nullptr;
            tail->prev[i] = nullptr;
        }

        delete head;
        head = nullptr;
        delete tail;
        tail = nullptr;
    }
};

#endif