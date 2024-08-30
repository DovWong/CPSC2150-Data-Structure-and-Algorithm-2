#ifndef HASHINGSEPARATECHAINGDEMO_H
#define HASHINGSEPARATECHAINGDEMO_H

#include <iostream>
#include <iomanip>
#include "SkipList.h"

using namespace std;

class HashingSeparateChainingDemo {

private:
    
    vector<SkipList*> hashTable;
    int hashTableSize;
    int numberOfKeys;
    double loadFactorThreshold;
    int MAXIMUM_ALLOWED_LEVELS;

public:

    HashingSeparateChainingDemo() {
        hashTableSize = 10;
        MAXIMUM_ALLOWED_LEVELS = 3;

        for (int i = 0; i < hashTableSize; i++)
            hashTable.push_back(new SkipList(MAXIMUM_ALLOWED_LEVELS));

        numberOfKeys = 0;
        loadFactorThreshold = 1.0;
    }

    HashingSeparateChainingDemo(int initialTableSize, double initialLoadFactor) {
        hashTableSize = initialTableSize;
        MAXIMUM_ALLOWED_LEVELS = 3;

        for (int i = 0; i < hashTableSize; i++)
            hashTable.push_back(new SkipList(MAXIMUM_ALLOWED_LEVELS));

        numberOfKeys = 0;

        if (initialLoadFactor < 0)
            loadFactorThreshold = 0;
        else
            loadFactorThreshold = initialLoadFactor;
    }

    void ReHash() {

        hashTableSize *= 2;
        vector<SkipList*> newHashTable(hashTableSize);
        hash<int> hashFunction;

        for (int i = 0; i < hashTableSize; i++)
            newHashTable[i] = new SkipList(MAXIMUM_ALLOWED_LEVELS);

        for (int i = 0; i < hashTableSize / 2; i++) {

            if (hashTable[i]->head->next[0] != hashTable[i]->tail) {

                Node* cur = hashTable[i]->head->next[0];
                while (cur != hashTable[i]->tail) {
                    int hashCode = hashFunction(cur->value) % hashTableSize;
                    newHashTable[hashCode]->InsertElement(cur->value);
                    cur = cur->next[0];
                }
            }

            delete hashTable[i];
        }

        hashTable = newHashTable;
    }

    void Insert(int value) {

        if(Search(value)) {
            cout << value << " already exists!\n";
            return;
        }

        if ((numberOfKeys * 1.0 + 1) / hashTableSize > loadFactorThreshold)
            ReHash();

        hash<int> hashFunction;
        int hashCode = hashFunction(value) % hashTableSize;

        hashTable[hashCode]->InsertElement(value);
        numberOfKeys++;
    }

    void Delete(int value) {

        if(!Search(value)) {
            cout << value << " does not exists!\n";
            return;
        }

        hash<int> hashFunction;
        int hashCode = hashFunction(value) % hashTableSize;

        hashTable[hashCode]->Delete(value);
    }

    bool Search(int value) {

        hash<int> hashFunction;
        int hashCode = hashFunction(value) % hashTableSize;

        return hashTable[hashCode]->Search(value);
    }

    void Display() {
        cout << "Current Table Size: " << hashTableSize;
        cout << "; Number of Keys: " << numberOfKeys;
        cout << ";  Current Load Factor: " << setprecision(2) << fixed << (numberOfKeys * 1.0) / hashTableSize;
        cout << ";  Load Factor Threshold: " << setprecision(2) << fixed << loadFactorThreshold << endl;

        for (int i = 0; i < hashTableSize; i++) {
            cout << "Index " << i << ":\n";
            hashTable[i]->Show();
            cout << endl;
        }

        cout << endl;
    }

    void DeleteAll() {

        for (int i = 0; i < hashTableSize; i++)
            hashTable[i]->DeleteAll();

        numberOfKeys = 0;
    }

    ~HashingSeparateChainingDemo() {
        for (int i = 0; i < hashTableSize; i++) {
            delete hashTable[i];
            hashTable[i] = nullptr;
        }
    }
};



#endif