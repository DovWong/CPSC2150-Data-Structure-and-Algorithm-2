#include "LinkedListFull.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    LinkedList<int> list;

    cout << "Testing \"list.removeLast()\" to an empty list: "<< endl;
    cout << "Actual: ";
    list.removeLast();
    cout << endl;
    cout << "Expect: " << "Some warning messages" << endl << endl;

    cout << "Testing \"list.Show()\" to an empty list: "<< endl;
    cout << "Actual: ";
    list.Show();
    cout << "Expect: " << "Some warning messages" << endl << endl;

    list.add(3, 2);
    cout << "Testing \"list.add(3, 2)\" to an empty list: "<< endl;
    cout << "Actual: ";
    list.Show();
    cout << "Expect: " << endl << endl;

    list.add(0, 0);
    cout << "Testing \"list.add(0, 0)\" to the list(2): "<< endl;
    cout << "Actual: ";
    list.Show();
    cout << "Expect: " << "0 -> 2" << endl << endl;

    cout << "Testing \"list.add(1, 1)\" to the list(0 -> 2): "<< endl;
    cout << "Actual: ";
    list.add(1,1);
    list.Show();
    cout << "Expect: " << "0 -> 1 -> 2" << endl << endl;

    cout << "Testing \"list.add(3, 3)\" to the list(0 -> 1 -> 2): "<< endl;
    cout << "Actual: ";
    list.add(3,3);
    list.Show();
    cout << "Expect: " << "0 -> 1 -> 2 -> 3" << endl << endl;

    cout << "Testing \"list.removeLast()\" to the list(0 -> 1 -> 2 -> 3):  "<< endl;
    cout << "Actual removal: " << list.removeLast() << endl;
    cout << "Expected removal: 3" << endl;
    cout << "Actual: ";
    list.Show();
    cout << "Expect: " << "0 -> 1 -> 2" << endl << endl;

    cout << "Testing \"list.removeLast()\" to the list(0 -> 1 -> 2):  "<< endl;
    cout << "Actual removal: " << list.removeLast() << endl;
    cout << "Expected removal: 2" << endl;
    cout << "Actual: ";
    list.Show();
    cout << "Expect: " << "0 -> 1" << endl << endl;

    cout << "Testing \"list.contains(1)\" to the list(0 -> 1):  "<< endl;
    cout << "Actual: " << list.contains(1) << endl;
    cout << "Expect: 1(True)" << endl << endl;

    cout << "Testing \"list.contains(2)\" to the list(0 -> 1):  "<< endl;
    cout << "Actual: " << list.contains(2) << endl;
    cout << "Expect: 0(False)" << endl << endl;

    cout << "Testing \"list.clear\" to the list(0 -> 1):  "<< endl;
    list.clear();
    cout << "Actual: ";
    list.Show();
    cout << "Expect: " << "Some warning messages" << endl;
    cout << "Actual size: " << list.getSize() << "; Expected size: 0" << endl << endl;

    return 0;
}
