#include "CircularList.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

#ifndef HW2_ROUNDROBINPROCESSSCHEDULER_H
#define HW2_ROUNDROBINPROCESSSCHEDULER_H

class RoundRobinProcessScheduler{

public:
    int timeSlice;
    int totalTurnaroundTime;
    CircularLinkedList processTimes;
    vector<int> eachTurnaroundTime;
    vector<bool> processDone;
    int size;

    RoundRobinProcessScheduler(){
        timeSlice = totalTurnaroundTime = size = 0;
    }

    void LoadFromFile(string fileName) {

        ifstream input(fileName);
        string word;
        bool flag = true;

        while (!input.eof()) {

            if (flag) {
                input >> timeSlice;
                flag = false;
            } else {
                while (getline(input, word, ',')) {
                    processTimes.insert(stoi(word));
                    eachTurnaroundTime.push_back(0);
                    processDone.push_back(false);
                    size++;
                }
            }
        }

        input.close();
    }

    void Process() {

        if (size == 0) {
            cout << "No process exist." << endl;
            return;
        }

        Node* prev = processTimes.getLast();
        Node* next;
        int index = 0;
        int originalSize = size;

        while (prev && size > 1) {

            if (prev->next->data <= timeSlice) {
                totalTurnaroundTime += prev->next->data;
                eachTurnaroundTime[index] = totalTurnaroundTime;
                prev->next->data = 0;
                processDone[index] = true;

                next = prev->next->next;
                delete prev->next;
                prev->next = next;
                size--;
            } else {
                prev->next->data -= timeSlice;
                totalTurnaroundTime += timeSlice;
                prev = prev->next;
            }

            index = (index + 1) % originalSize;

            while (processDone[index])
                index = (index + 1) % originalSize;
        }

        while (!processDone[index]) {

            if (prev->data <= timeSlice) {
                totalTurnaroundTime += prev->data;
                eachTurnaroundTime[index] = totalTurnaroundTime;
                processDone[index] = true;

                delete prev;
                prev = nullptr;
                size--;
            } else {
                prev->data -= timeSlice;
                totalTurnaroundTime += timeSlice;
            }
        }

        processTimes.setLast(nullptr);
    }

    void ShowResults() {

        cout << "Turnover Time:" << endl;
        int sum = 0;

        for (int i = 0; i < eachTurnaroundTime.size(); i++) {
            cout << "Process " << i + 1 << ": " << eachTurnaroundTime[i] << endl;
            sum += eachTurnaroundTime[i];
        }

        cout << fixed << setprecision(2);

        cout << endl << "Average Turnover Time: " << sum * 1.0 / eachTurnaroundTime.size() << endl;
    }

};

#endif //HW2_ROUNDROBINPROCESSSCHEDULER_H
