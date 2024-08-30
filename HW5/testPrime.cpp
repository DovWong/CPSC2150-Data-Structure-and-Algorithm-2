#include <iostream>
#include "Prime.cpp"
#include <vector>
#include <iomanip>

using namespace std;

int main() {

    cout << "\n********************Testing for Prime Number function********************\n\n";

    int primeNum = 10000;

    vector<int> primeList = SieveOfEratosthenes(primeNum);
    vector<int> primeList2 = SieveOfEratosthenes2(primeList[primeNum - 1]);
    vector<int> primeList3 = BrutalForce(primeNum);
    vector<int> primeList4 = BrutalForce2(primeNum);

    bool checker = true;

    for (int i = 0; i < primeNum; i++) {
        if (primeList[i] != primeList2[i] || primeList2[i] != primeList3[i] || primeList3[i] != primeList4[i]) {
            checker = false;
            break;
        }
    }

    if (checker)
        cout << "All functions produce same results\n";
    else
        cout << "Something wrong...\n";

    cout << "\n********************Display the Prime List********************\n\n";

    for (int i = 0; i < 1000; i++) {
        cout << setw(4) << primeList[i] << " ";

        if ((i + 1) % 30 == 0)
            cout << endl;
    }

    cout << endl;


    int testSizeList[] = {1000, 5000, 10000, 50000, 100000};
    int sizeOfTestSizeList = sizeof(testSizeList) / sizeof(int);
    vector<int> refList = BrutalForce(testSizeList[sizeOfTestSizeList - 1]);
    vector<int> refList2;

    for (int i = 0; i < sizeOfTestSizeList; i++) // Creating a list for the parameter of Sieve2
        refList2.push_back(refList[testSizeList[i] - 1]);

    int numOfAlgorithm = 4;
    int timeList[numOfAlgorithm][sizeOfTestSizeList];

    clock_t clockT;

    for (int i = 0; i < sizeOfTestSizeList; i++) {

        clockT = clock();

        SieveOfEratosthenes(testSizeList[i]);

        timeList[0][i] = clock() - clockT;
    }

    for (int i = 0; i < sizeOfTestSizeList; i++) {

        clockT = clock();

        SieveOfEratosthenes2(refList2[i]);

        timeList[1][i] = clock() - clockT;
    }

    for (int i = 0; i < sizeOfTestSizeList; i++) {

        clockT = clock();

        BrutalForce(testSizeList[i]);

        timeList[2][i] = clock() - clockT;
    }

    for (int i = 0; i < sizeOfTestSizeList; i++) {

        clockT = clock();

        BrutalForce2(testSizeList[i]);

        timeList[3][i] = clock() - clockT;
    }



    string algorithmList[] = {"Sieve of Eratosthenes", "Sieve of Eratosthenes 2",
                               "Brutal Force","Brutal Force2"};

    cout << "\nTiming for different algorithm\n\n";

    cout << setw(22) << left << "Tested size";
    for (int i = 0; i < numOfAlgorithm; i++)
        cout << setw(28) << left << algorithmList[i];

    cout << endl;

    for (int i = 0; i < sizeOfTestSizeList; i++) {

        cout << setw(28) << left << testSizeList[i];

        for (int j = 0; j < numOfAlgorithm; j++)
            cout << setw(28) << left << timeList[j][i];

        cout << endl;
    }

    return 0;
}