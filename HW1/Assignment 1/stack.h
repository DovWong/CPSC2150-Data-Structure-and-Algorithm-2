#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

using namespace std;

class Stack {

public:

    Stack() {
        size = 0;
    };

    /**
     * @brief adds the value in parameter x to the top of the stack
     * 
     * @param x, int
     * 
     * @return none
     * 
     * Time Complexity: O(1), because vector is array in nature, any positions in the array can be accessed and modified by constant time,
     * so the value can be added to the end of the vector by constant time
     * Only some special time (size > capacity) will become O(n) as it needs to create a new vector and copy of n elements to new array
     * 
     */
    void Push(int x) {
        data.push_back(x);
        size++;
    };

    /**
     * @brief delete the value of the top of the stack
     *        If the stack is empty or becomes empty after pop, a warning message will be printed and 0 will be returned.
     * 
     * @param none
     * 
     * @return the value of the top of the stack; or 0 if the size of the stack is empty or become empty after pop.
     * 
     * Time Complexity: O(1), because vector is array in nature, any positions in the array can be modified by constant time.
     * 
     */
    int Pop() {

        if (size == 1) {
            cout << "Stack is now empty after poping! Returning 0." << endl;
            size--;
            return 0;
        }

        if (size == 0) {
            cout << "Stack is empty! Returning 0." << endl;
            return 0;
        }
        
        data.pop_back();
        size--;
        return data.back();
    };

    /**
     * @brief show the value of the top of the stack
     *        If the stack is empty, a warning message will be printed and 0 will be returned.
     * 
     * @param none
     * 
     * @return the value of the top of the stack; or 0 if the stack is empty.
     * 
     * Time Complexity: O(1), because vector is array in nature, any positions in the array can be accessed by constant time.
     * 
     */
    int Peek() const {
        if (size == 0) {
            cout << "Stack is empty! Returning 0." << endl;
            return 0;
        }

        return data.back();
    };

private:

    vector<int> data;
    int size;
};

#endif