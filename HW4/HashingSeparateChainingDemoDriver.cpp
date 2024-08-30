#include <iostream>
#include "HashingSeparateChainingDemo.h"

using namespace std;

void Menu() {

    int tableSize;
    double loadFactorThreshold;

    cout << "Please enter the table size and the load factor threshold:";
    cin >> tableSize >> loadFactorThreshold;
    cout << endl;

    HashingSeparateChainingDemo demo(tableSize, loadFactorThreshold);

    int option = 1;
    int num;

    while (option != 0) {

        cout << "Please enter the option:\n";
        cout << "1. Insert\n2. Remove\n3. Search\n4. Remove All\n0. Exit\n";

        cin >> option;

        if (option > 0 && option < 4) {
            cout << "Please enter a number:";
            cin >> num;
            cout << endl;
        }

        switch (option) {
            case 1:
                demo.Insert(num);
                demo.Display();
                break;
            case 2:
                demo.Delete(num);
                demo.Display();
                break;
            case 3:
                if (demo.Search(num))
                    cout << num << " is in the list.\n";
                else
                    cout << num << " is not in the list.\n";
                break;
            case 4:
                demo.DeleteAll();
                demo.Display();
                break;
            case 0:
                exit(1);
            default:
                cout << "Invalid input, please input again.\n";
        }

    }

}

int main() {

    srand(time(0));
    Menu();


    return 0;
}