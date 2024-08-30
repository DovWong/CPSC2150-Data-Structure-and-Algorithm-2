#include "stack.h"

#include <iostream>
#include <vector>

using namespace std;


int main() {

    Stack s1;

    cout << "The stack is just created and it is empty." << endl;
    cout << "Testing Peek:" << endl;
    cout << "Actual: " << s1.Peek() << endl;
    cout << "Expect: 0" << endl << endl;

    cout << "Testing Pop:" << endl;
    cout << "Actual: " << s1.Pop() << endl;
    cout << "Expect: 0" << endl << endl;

    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    cout << "The stack is pushed by 1, 2 and 3." << endl;
    cout << "Testing Peek:" << endl;
    cout << "Actual: " << s1.Peek() << endl;
    cout << "Expect: 3" << endl << endl;
    cout << "Testing Pop:" << endl;
    cout << "Actual: " << s1.Pop() << endl;
    cout << "Expect: 2" << endl << endl;
    cout << "Testing Pop:" << endl;
    cout << "Actual: " << s1.Pop() << endl;
    cout << "Expect: 1" << endl << endl;
    cout << "Testing Pop:" << endl;
    cout << "Actual: " << s1.Pop() << endl;
    cout << "Expect: 0" << endl;

    return 0;
}
