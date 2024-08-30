#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SkipList.h"

using namespace std;

int main(){
    srand(time(0));
 
    SkipList lst(3); // skiplist with maximum level index
 
    lst.InsertElement(13);
    lst.InsertElement(7);
    lst.InsertElement(11);
    lst.InsertElement(1);
    lst.InsertElement(5);
    lst.InsertElement(19);

    lst.InsertElement(313);
    lst.InsertElement(37);
    lst.InsertElement(311);
    lst.InsertElement(31);
    lst.InsertElement(35);
    lst.InsertElement(319);

    lst.Show();

    cout << endl;

    lst.ShowBackward();

    cout << endl << "------------Testing \"Delete\"------------" << endl;

    lst.Delete(2);
    lst.Delete(1000);
    lst.Delete(37);
    lst.Delete(313);
    lst.Delete(319);
    lst.Delete(311);

    cout << endl << "New list" << endl;
    lst.Show();
    cout << endl << "New list reversed" << endl;
    lst.ShowBackward();
    cout << endl << "level now: " << lst.level << endl;

    // Please comment out the test for delete first before testing for search
//    cout << endl << "------------Testing \"Search\"------------" << endl;
//    int testList[] = {1, 5, 7, 11, 13, 19, 31, 35, 37, 311, 313, 319};
//    int testListSize = sizeof(testList) / sizeof(int);
//    bool result = false;
//    int testNum;
//    for (int i = 0; i < testListSize * 5; i++) {
//
//        float probablity = (float)rand()/RAND_MAX;
//
//        if (probablity < 0.5) {
//            testNum = testList[i % testListSize] + 1;
//            result = false;
//        } else {
//            testNum = testList[i % testListSize];
//            result = true;
//        }
//
//        cout << "Testing: " << testNum << endl;
//        cout << "Actual: " << lst.Search(testNum) << endl;
//        cout << "Expected: " << result << endl << endl;
//    }



    return 0;
}