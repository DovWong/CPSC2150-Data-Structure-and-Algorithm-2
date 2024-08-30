//
// Created by Dov Wong on 2023-09-15.
//

#ifndef HW1_QUEUE_H
#define HW1_QUEUE_H

#include "LinkedListFull.h"

#include <iostream>
#include <vector>

using namespace std;

class Queue {

private:
    LinkedList<int> Data;
    int size;

public:
    Queue() {
        size = 0;
    }

    /**
     * @brief adds a int to the rear of the queue
     *
     * @param x, int
     *
     * @return none
     *
     * Time Complexity: O(1), because the linked list class always keeps track of the tail, this fct just add a new node
     * to the end, connects the old tail to the new end and sets the new tail to the new ned
     *
     */
    void Enqueue(int x) { //adds the parameter to the rear of the queue and updates Size, returns nothing
        Data.addLast(x);
        size++;
    }

    /**
     * @brief remove the first element of the queue
     *
     * @param none
     *
     * @return the value(int) removed
     *
     * Time Complexity: O(1), because this fct just remove the front of the queue and don't need to go through the queue
     *
     */
    int Dequeue() {// removes the item at the front of the queue and updates Size, returns an int (the item removed)
        int front = Data.getFirst();
        Data.removeFirst();
        size--;
        return front;
    }

    /**
     * @brief display the front of the queue
     *
     * @param none
     *
     * @return value(int) of the front of the queue
     *
     * Time Complexity: O(1), because this fct just access the front of the queue and don't need to go through the queue
     *
     */
    int	PeekFront() { //-  returns the item at the front of the queue, returns an int
        if (size == 0)
            cout << "No elements in the queue" << endl;
        else
            return Data.getFirst();
    }

    /**
     * @brief display the rear of the queue
     *
     * @param none
     *
     * @return value(int) of the rear of the queue
     *
     * Time Complexity: O(1), because the linked list class always keeps track of the tail, this fct just access
     * tail of the list and don't need to go through the queue
     *
     */
    int PeekRear() { // returns the item at the rear of the queue, returns an int
        if (size == 0)
            cout << "No elements in the queue" << endl;
        else
            return Data.getLast();
    }

};


#endif //HW1_QUEUE_H
