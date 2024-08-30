#include <iostream>
#include "SkipList.h"

#ifndef HW3_PRIORITYQUEUE_H
#define HW3_PRIORITYQUEUE_H

using namespace std;

class PriorityQueue {

public:

    SkipList list;
    int size;

    PriorityQueue(int maxLevels) : list(maxLevels) {
        size = 0;
    }

    void Enqeue() {
        list.InsertElement();
        size++;
    }

    int Dequeue() {
        size--;
        return list.RemoveFirstInHighestPriority();
    }

    void Process() {

        while (size != 0) {
            cout << list.RemoveFirstInHighestPriority() << " -> ";
            size--;
        }

        cout << "." << endl;
    }

    void Show() {
        list.Show();
    }
};

#endif //HW3_PRIORITYQUEUE_H
