#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cmath>
#include <chrono>

using namespace std;
//const int CHAR_RANGE = 26;
const int CHAR_RANGE = 94;

//O(n) * O(n) = )(n^2)
bool firstSolution(string str) {

    if (str == "")
        return false;

    for (int i = 0; i < str.size() - 1; i++) { //O(n)
        for (int j = i + 1; j < str.size(); j++) { //O(n)
            if (str[i] == str[j])
                return true;
        }
    }

    return false;
}

// Loop (O(n)) * dividing the str O(log(n)) = O(nlog(n))
void mergeSort(char list[], int size) {

    if (size <= 1)
        return;

    int size1 = size / 2;
    int size2 = size - size1;

    // whole processes will be log(n)
    mergeSort(list, size1);
    mergeSort(list + size1, size2);

    int index1 = 0;
    int index2 = 0;

    int *newList = new int[size];
    int index3 = 0;

    // Time for 3 while lopp will be O(n)
    while (index1 < size1 && index2 < size2) {

        if (list[index1] < (list + size1)[index2])
            newList[index3++] = list[index1++];
        else
            newList[index3++] = (list + size1)[index2++];
    }

    while (index1 < size1)
        newList[index3++] = list[index1++];

    while (index2 < size2)
        newList[index3++] = (list + size1)[index2++];

    for (int i = 0; i < size; i++)
        list[i] = newList[i];

    delete []newList;
    newList = nullptr;
}

// For loop (O(n)) + MergeSort O(nlog(n)) = O(nlog(n))
bool secondSolution(string str) {

    if (str == "")
        return false;

    int size = str.size();

    char list[size];

    for (int i = 0; i < size; i++)
        list[i] = str[i];

    mergeSort(list, size);

    for (int i = 0; i < size - 1; i++) { //(O(n)
        if (list[i] == list[i + 1])
            return true;
    }

    return false;
}

void mergeSort2(char list[], int size) {

    if (size <= 1)
        return;

    int size1 = size / 2;
    int size2 = size - size1;

    // whole processes will be log(n)
    mergeSort(list, size1);
    mergeSort(list + size1, size2);

    if (list[0] == list[1] && (list + size1)[0] == (list + size1)[1])
        return;

    int index1 = 0;
    int index2 = 0;

    int *newList = new int[size];
    int index3 = 0;

    // Time for 3 while lopp will be O(n)
    while (index1 < size1 && index2 < size2) {

        if (list[index1] == (list + size1)[index2]) {
            list[0] = list[1]; // for  if (list[0] == list[1] && (list + size1)[0] == (list + size1)[1])
            return;
        }

        if (list[index1] < (list + size1)[index2])
            newList[index3++] = list[index1++];
        else
            newList[index3++] = (list + size1)[index2++];
    }

    while (index1 < size1)
        newList[index3++] = list[index1++];

    while (index2 < size2)
        newList[index3++] = (list + size1)[index2++];

    for (int i = 0; i < size; i++)
        list[i] = newList[i];

    delete []newList;
    newList = nullptr;
}

bool secondSolution2(string str) {

    if (str == "")
        return false;

    int size = str.size();

    char list[size];

    for (int i = 0; i < size; i++)
        list[i] = str[i];

    mergeSort2(list, size);

    for (int i = 0; i < size - 1; i++) { //(O(n)
        if (list[i] == list[i + 1])
            return true;
    }

    return false;
}

bool mergeSort3(char list[], int size) {

    if (size <= 1)
        return false;

    int size1 = size / 2;
    int size2 = size - size1;

    // whole processes will be log(n)
    if (mergeSort3(list, size1) || mergeSort3(list + size1, size2))
        return true;

    int index1 = 0;
    int index2 = 0;

    int *newList = new int[size];
    int index3 = 0;

    // Time for 3 while lopp will be O(n)
    while (index1 < size1 && index2 < size2) {

        if (list[index1] == (list + size1)[index2])
            return true;

        if (list[index1] < (list + size1)[index2])
            newList[index3++] = list[index1++];
        else
            newList[index3++] = (list + size1)[index2++];
    }

    while (index1 < size1)
        newList[index3++] = list[index1++];

    while (index2 < size2)
        newList[index3++] = (list + size1)[index2++];

    for (int i = 0; i < size; i++)
        list[i] = newList[i];

    delete []newList;
    newList = nullptr;

    return false;
}

bool secondSolution3(string str) {

    if (str == "")
        return false;

    int size = str.size();

    char list[size];

    for (int i = 0; i < size; i++)
        list[i] = str[i];

    return mergeSort3(list, size);
}

//O(n) * O(1) * O(1) = O(n)
bool thirdSolution(string str) {

    int hashTable[CHAR_RANGE] = {0};
    int hashCode;

    for (int i = 0; i < str.size(); i++) { //O(n)

        hashCode = (int)str[i] % CHAR_RANGE; //O(1)
        // or hashCode = str[i] - '!';

        //O(1)
        if (hashTable[hashCode] == 0)
            hashTable[hashCode]++;
        else
            return true;
    }

    return false;
}

//string generateString() {
//
//    int probability = rand() % 2;
//    int strSize = rand() % 26 + 1;;
//    string newStr = "";
//
//    if (probability == 0) { //non repeated string
//        string list = "abcdefghijklmnopqrstuvwxyz";
//
//        for (int i = 0; i < strSize; i++) {
//            int index = rand() % list.size();
//            newStr += list[index];
//            list = list.substr(0, index) + list.substr(index + 1, strSize);
//        }
//
//        return newStr;
//    }
//
//    for (int i = 0; i < strSize; i++) {
//        int charIndex = rand() % CHAR_RANGE;
//        newStr += 'a' + charIndex;
//    }
//
//    int index = rand() % strSize;
//    newStr += newStr[index];
//
//    return newStr;
//}

string generateString(int size) {

    if (size < 0)
        size = 2;

    if (size > 94)
        size = 94;

    int probability = rand() % 2;
    string newStr = "";

    if (probability == 0) { //non repeated string

        string list = "";

        for (int i = 0; i < CHAR_RANGE; i++)
            list += '!' + i;

        for (int i = 0; i < size; i++) {
            int index = rand() % list.size();
            newStr += list[index];
            list = list.substr(0, index) + list.substr(index + 1, CHAR_RANGE);
        }

        return newStr;
    }

    int charIndex;

    for (int i = 0; i < size - 1; i++) {
        charIndex = rand() % CHAR_RANGE;
        newStr += '!' + charIndex;
    }

    int index = rand() % (size - 1);
    newStr += newStr[index];

    return newStr;
}

//string generateString() {
//
//    int strSize = 94;
//    string newStr = "";
//
//    string list = "";
//
//    for (int i = 0; i < 94; i++)
//        list += '!' + i;
//
//    for (int i = 0; i < strSize; i++) {
//        int index = rand() % list.size();
//        newStr += list[index];
//        list = list.substr(0, index) + list.substr(index + 1, strSize);
//    }
//
//    newStr += newStr[93];
//
//    return newStr;
//}


int main() {

    srand(time(0));

    cout << boolalpha << endl;

    int testSize = 20000;
    int numAlgorithm = 5;
    int numSize = 8;
    int sizeList[] = {20, 30, 40, 50, 60, 70, 80, 90}; //same size as numSize
    string stringList[numSize][testSize];

    for (int i = 0; i < numSize; i++) {
        for (int j = 0; j < testSize; j++) {
            stringList[i][j] = generateString(sizeList[i]);
        }
    }

    int trueList[numAlgorithm][numSize];
    int falseList[numAlgorithm][numSize];

    for (int i = 0; i < numAlgorithm; i++) {
        for (int j = 0; j < numSize; j++) {
            trueList[i][j] = 0;
            falseList[i][j] = 0;
        }
    }


    double timeList[numAlgorithm][numSize];

//    for (int i = 0; i < numSize; i++) {
//
//        auto start = chrono::high_resolution_clock::now();
//
//        for (int j = 0; j < testSize; j++) {
//            if (firstSolution(stringList[i][j]))
//                trueList[0][i]++;
//            else
//                falseList[0][i]++;
//        }
//
//        auto end = chrono::high_resolution_clock::now();
//        timeList[0][i] = chrono::duration_cast<chrono::milliseconds>(end - start).count();
//    }
//
//    for (int i = 0; i < numSize; i++) {
//
//        auto start = chrono::high_resolution_clock::now();
//
//        for (int j = 0; j < testSize; j++) {
//            if (secondSolution(stringList[i][j]))
//                trueList[1][i]++;
//            else
//                falseList[1][i]++;
//        }
//
//        auto end = chrono::high_resolution_clock::now();
//        timeList[1][i] = chrono::duration_cast<chrono::milliseconds>(end - start).count();
//    }
//
//    for (int i = 0; i < numSize; i++) {
//
//        auto start = chrono::high_resolution_clock::now();
//
//        for (int j = 0; j < testSize; j++) {
//            if (secondSolution2(stringList[i][j]))
//                trueList[2][i]++;
//            else
//                falseList[2][i]++;
//        }
//
//        auto end = chrono::high_resolution_clock::now();
//        timeList[2][i] = chrono::duration_cast<chrono::milliseconds>(end - start).count();
//    }
//
//    for (int i = 0; i < numSize; i++) {
//
//        auto start = chrono::high_resolution_clock::now();
//
//        for (int j = 0; j < testSize; j++) {
//            if (secondSolution3(stringList[i][j]))
//                trueList[3][i]++;
//            else
//                falseList[3][i]++;
//        }
//
//        auto end = chrono::high_resolution_clock::now();
//        timeList[3][i] = chrono::duration_cast<chrono::milliseconds>(end - start).count();
//    }
//
//    for (int i = 0; i < numSize; i++) {
//
//        auto start = chrono::high_resolution_clock::now();
//
//        for (int j = 0; j < testSize; j++) {
//            if (thirdSolution(stringList[i][j]))
//                trueList[4][i]++;
//            else
//                falseList[4][i]++;
//        }
//
//        auto end = chrono::high_resolution_clock::now();
//        timeList[4][i] = chrono::duration_cast<chrono::milliseconds>(end - start).count();
//    }

    clock_t t;

    for (int i = 0; i < numSize; i++) {

        t = clock();

        for (int j = 0; j < testSize; j++) {
            if (firstSolution(stringList[i][j]))
                trueList[0][i]++;
            else
                falseList[0][i]++;
        }

        timeList[0][i] = clock() - t;
    }

    for (int i = 0; i < numSize; i++) {

        t = clock();

        for (int j = 0; j < testSize; j++) {
            if (secondSolution(stringList[i][j]))
                trueList[1][i]++;
            else
                falseList[1][i]++;
        }

        timeList[1][i] = clock() - t;
    }

    for (int i = 0; i < numSize; i++) {

        t = clock();

        for (int j = 0; j < testSize; j++) {
            if (secondSolution2(stringList[i][j]))
                trueList[2][i]++;
            else
                falseList[2][i]++;
        }

        timeList[2][i] = clock() - t;
    }

    for (int i = 0; i < numSize; i++) {

        t = clock();

        for (int j = 0; j < testSize; j++) {
            if (secondSolution3(stringList[i][j]))
                trueList[3][i]++;
            else
                falseList[3][i]++;
        }

        timeList[3][i] = clock() - t;
    }

    for (int i = 0; i < numSize; i++) {

        t = clock();

        for (int j = 0; j < testSize; j++) {
            if (thirdSolution(stringList[i][j]))
                trueList[4][i]++;
            else
                falseList[4][i]++;
        }

        timeList[4][i] = clock() - t;
    }

    string algorithmList[5] = {"First Algorithm\t\t", "Second Algorithm\t", "Second2 Algorithm\t",
                               "Second3 Algorithm\t", "Third Algorithm\t\t"};

    cout << "Compare the results for different algorithms(Number of test cases: " << testSize << ")\n";

    for (int i = 0; i < numSize; i++) {
        cout << "\nTested string size(" << sizeList[i] << ")" << "\t\t\t\t\tNumber of True\t\t\t\t\tNumber of False\n\n";

        for (int j = 0; j < numAlgorithm; j++)
            printf("%s%29d%33d\n", algorithmList[j].c_str(), trueList[j][i], falseList[j][i]);

        cout << endl << "******************************************************************************************" << endl;
    }

    cout << "Timing for different algorithm\n\n";

    for (int i = 0; i < numAlgorithm; i++) {
        cout << algorithmList[i] << "\t\tTested string size\t\t\t\tT(n)\t\t\t\tT(n) / n\t\t\t\tT(n) / nlog(n)\t\t\t\tT(n) / n^2\n";

        for (int j = 0; j < numSize; j++) {
            printf("%40d%28.8f%21.8f%27.8f%26.8f\n", sizeList[j], timeList[i][j] / testSize,
                   timeList[i][j] / sizeList[j] / testSize,
               timeList[i][j] / (sizeList[j] * log2(sizeList[j])) / testSize,
               timeList[i][j] / sizeList[j] / sizeList[j] / testSize);
        }

        cout << endl << "******************************************************************************************" <<
        "******************************************************************************************" << endl;
    }

//    cout << "Timing for different algorithm\n";
//
//    for (int i = 0; i < numAlgorithm; i++) {
//        cout << algorithmList[i] << "\t\tNumber of Test Case\t\t\t\tT(n)\t\t\t\tT(n) / n\t\t\t\tT(n) / nlog(n)\t\t\t\tT(n) / n^2\n";
//
//        for (int j = 0; j < numSize; j++) {
//            printf("%40d%28.8f%21.8f%27.8f%26.8f\n", testSizeList[j], timeList[i][j] / testSizeList[j],
//                   timeList[i][j] / STRING_SIZE / testSizeList[j],
//               timeList[i][j] / (STRING_SIZE * log2(STRING_SIZE)) / testSizeList[j],
//               timeList[i][j] / STRING_SIZE / STRING_SIZE / testSizeList[j]);
//        }
//
//        cout << endl << "******************************************************************************************" << endl;
//    }

    return 0;
}