#include <iostream>
#include <iomanip>
#include "PriorityQueue.h"

using namespace std;

int main() {

    srand(time(0));


    PriorityQueue list(5);

    list.Enqeue();
    list.Enqeue();
    list.Enqeue();
    list.Enqeue();
    list.Enqeue();

    list.Show();
    cout << endl;
    list.list.ShowBackward();
    cout << endl;

    list.Enqeue();
    list.Enqeue();
    list.Enqeue();
    list.Enqeue();
    list.Enqeue();

    list.Show();
    cout << endl;
    list.list.ShowBackward();
    cout << endl;

    list.Process();

    return 0;
}