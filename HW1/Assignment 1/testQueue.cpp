#include "Queue.h"

#include <iostream>

using namespace std;

int main() {

    Queue q1;

    cout << "Testing \"q1.PeekFront()\" to the empty queue:  "<< endl;
    cout << "Actual: ";
    q1.PeekFront();
    cout << "Expected: Some warning messages" << endl << endl;

    cout << "Testing \"q1.PeekRear()\" to the empty queue:  "<< endl;
    cout << "Actual: ";
    q1.PeekRear();
    cout << "Expected: Some warning messages" << endl << endl;

    q1.Enqueue(3);
    cout << "Testing \"q1.PeekFront()\" and \"q1.PeekRear()\" to the queue(3):  "<< endl;
    cout << "Actual front: " << q1.PeekFront() << "; rear: " << q1.PeekRear() << endl;
    cout << "Expected front: 3; rear: 3" << endl << endl;

    q1.Enqueue(4);
    cout << "Testing \"q1.PeekFront()\" and \"q1.PeekRear()\" to the queue(3 -> 4):  "<< endl;
    cout << "Actual front: " << q1.PeekFront() << "; rear: " << q1.PeekRear() << endl;
    cout << "Expected front: 3; rear: 4" << endl << endl;

    q1.Enqueue(5);
    cout << "Testing \"q1.PeekFront()\" and \"q1.PeekRear()\" to the queue(3 -> 4 -> 5):  "<< endl;
    cout << "Actual front: " << q1.PeekFront() << "; rear: " << q1.PeekRear() << endl;
    cout << "Expected front: 3; rear: 5" << endl << endl;

    cout << "Testing \"q1.PeekFront()\" and \"q1.PeekRear()\" to the queue(4 -> 5):  "<< endl;
    cout << "Actual dequeued: " << q1.Dequeue() << endl;
    cout << "Expected dequeued : 3" << endl;
    cout << "Actual front: " << q1.PeekFront() << "; rear: " << q1.PeekRear() << endl;
    cout << "Expected front: 4; rear: 5" << endl << endl;

    cout << "Testing \"q1.PeekFront()\" and \"q1.PeekRear()\" to the queue(5):  "<< endl;
    cout << "Actual dequeued: " << q1.Dequeue() << endl;
    cout << "Expected dequeued : 4" << endl;
    cout << "Actual front: " << q1.PeekFront() << "; rear: " << q1.PeekRear() << endl;
    cout << "Expected front: 5; rear: 5" << endl << endl;

    q1.Dequeue();

    cout << "Testing \"q1.PeekFront()\" to the empty queue:  "<< endl;
    cout << "Actual: ";
    q1.PeekFront();
    cout << "Expected: Some warning messages" << endl << endl;

    cout << "Testing \"q1.PeekRear()\" to the empty queue:  "<< endl;
    cout << "Actual: ";
    q1.PeekRear();
    cout << "Expected: Some warning messages" << endl << endl;

    return 0;
}