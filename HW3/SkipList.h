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

    int currentLevel;
    
    // the head node's next links are connected to the first node at every level
    Node *head;

    Node* tail;

    SkipList(int maxLevels){
        MAXIMUM_ALLOWED_LEVELS = maxLevels;
        currentLevel = 0;
    
        // create the header node, value is irrelevant (as long as it doesn't match an inserted value - NO REPEATS), number of next links is important (this node is connected to the first node at every level)
        head = new Node(INT_MIN, MAXIMUM_ALLOWED_LEVELS);
        tail = new Node(INT_MAX, MAXIMUM_ALLOWED_LEVELS);

        for (int i = 0; i <= MAXIMUM_ALLOWED_LEVELS; i++) {
            head->next[i] = tail;
            tail->prev[i] = head;
        }
    }

    Node* CreateNode(int value, int level){
        // create a new node with next links for every level that this node will be part of
        // it will use these links to connect to the next node at each level  
        return new Node(value, level);
    }

    void InsertElement(){

        unsigned int level = rand() % (MAXIMUM_ALLOWED_LEVELS + 1);

        if (level > currentLevel)
            currentLevel = level;

        int value = rand() - 1;

        if (value % 2 == 1)
            value = -1 * (rand() - 1); // Reserve INT_MIN for Remove fct

        Node* node = new Node(value, level);

        for (int i = level; i >= 0; i--){
            tail->prev[i]->next[i] = node;
            node->prev[i] = tail->prev[i];
            tail->prev[i] = node;
            node->next[i] = tail;
        }
    }

    int RemoveFirstInHighestPriority (){

        if (head->next[0] == tail) {
            cout << "There is no element in the queue." << endl;
            return INT_MIN;
        }

        Node* del;

        for (int i = currentLevel; i >= 0; i--) {

            if (head->next[i] != tail) {
                del = head->next[i];

                for (int j = i; j >= 0; j--) {
                    del->prev[j]->next[j] = del->next[j];
                    del->next[j]->prev[j] = del->prev[j];

                    if (head->next[j] == tail)
                        currentLevel--;
                }

                break;
            }
        }

        int num = del->value;
        delete del;
        del = nullptr;
        return num;
    }

    void Show(){

        if (head->next[0] == tail) {
            cout << "There are nothing in the list." << endl;
            return;
        }

        for (int i = currentLevel; i >= 0; i--){
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

        if (head->next[0] == tail) {
            cout << "There are nothing in the list." << endl;
            return;
        }

        for (int i = currentLevel; i >= 0; i--){
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