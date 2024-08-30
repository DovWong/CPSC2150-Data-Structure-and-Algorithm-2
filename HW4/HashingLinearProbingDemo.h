#ifndef HASHINGLINEARPROBINGDEMO_H
#define HASHINGLINEARPROBINGDEMO_H

#include <iostream>
#include <iomanip>

using namespace std;

class HashingLinearProbingDemo {

private:
    
    int* hashTable;
    int hashTableSize;
    int numberOfKeys;
    double loadFactorThreshold;

public:

    HashingLinearProbingDemo() {
        hashTable = nullptr;
        hashTableSize = 10;
        numberOfKeys = 0;
        loadFactorThreshold = 1.0;
    }

    HashingLinearProbingDemo(int initialTableSize, double initialLoadFactor) {
        hashTableSize = initialTableSize;
        hashTable = new int[initialTableSize]();
        numberOfKeys = 0;

        if (initialLoadFactor < 0)
            loadFactorThreshold = 0;
        else if (initialLoadFactor > 1)
            loadFactorThreshold = 1;
        else
            loadFactorThreshold = initialLoadFactor;
    }

    void ReHash() {
        hashTableSize *= 2;
        int* newHashTable = new int[hashTableSize]();
        hash<int> hashFunction;

        for(int i = 0; i < hashTableSize / 2; i++) {
            if (hashTable[i] != 0) {
                int hashCode = hashFunction(hashTable[i]) % hashTableSize;

                while(newHashTable[hashCode] != 0)
                    hashCode = (hashCode + 1) % hashTableSize;

                newHashTable[hashCode] = hashTable[i];
            }
        }

        delete []hashTable;
        hashTable = newHashTable;
    }

    void Insert(int value) {

        if(value == 0) {
            cout << "0 is not allow\n";
            return;
        }

        if(Search(value)) {
            cout << value << " already exists!\n";
            return;
        }

        if ((numberOfKeys * 1.0 + 1) / hashTableSize > loadFactorThreshold)
            ReHash();

        hash<int> hashFunction;
        int hashCode = hashFunction(value) % hashTableSize;

        while(hashTable[hashCode] != 0)
            hashCode = (hashCode + 1) % hashTableSize;

        hashTable[hashCode] = value;
        numberOfKeys++;
    }

    void Delete(int value) {

        if(value == 0) {
            cout << "0 is not allow\n";
            return;
        }

        hash<int> hashFunction;
        int hashCode = hashFunction(value) % hashTableSize;

        int count = 0;

        while(hashTable[hashCode] != value && count != numberOfKeys) {
            hashCode = (hashCode + 1) % hashTableSize;
            count++;
        }

        if (hashTable[hashCode] == value) {
            hashTable[hashCode] = 0;
            numberOfKeys--;
        } else {
            cout << value << " does not exists." << endl;
        }
    }

    bool Search(int value) {

        if(value == 0) {
            cout << "0 is not allow\n";
            return false;
        }

        hash<int> hashFunction;
        int hashCode = hashFunction(value) % hashTableSize;

        int count = 0;

        while(hashTable[hashCode] != value && count != numberOfKeys) {
            hashCode = (hashCode + 1) % hashTableSize;
            count++;
        }

        if (hashTable[hashCode] == value)
            return true;
        
        return false;
    }

    void Display() {
        cout << "Current Table Size: " << hashTableSize;
        cout << "; Number of Keys: " << numberOfKeys;
        cout << ";  Current Load Factor: " << setprecision(2) << fixed << (numberOfKeys * 1.0) / hashTableSize;
        cout << ";  Load Factor Threshold: " << setprecision(2) << fixed << loadFactorThreshold << endl;

        for (int i = 0; i < hashTableSize; i++) {
            cout << hashTable[i];

            if (i != hashTableSize - 1)
                cout << ", ";
        }

        cout << endl;
    }

    void DeleteAll() {
        for (int i = 0; i < hashTableSize; i++)
            hashTable[i] = 0;
    }

    ~HashingLinearProbingDemo() {
        delete []hashTable;
        hashTable = nullptr;
    }
};



#endif