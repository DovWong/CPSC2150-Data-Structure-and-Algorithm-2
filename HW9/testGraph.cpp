#include "Graph.h"
#include <iostream>

using namespace std;

int main(){
    Graph g("distances2.txt");

    char option = 'y';

    do {
        g.ShowLocationInfo();
        g.FindRoute();

        cout << "\nDo you want to continue? (y/n)\n";
        cin >> option;
    } while (option == 'y');



    return 0;
}