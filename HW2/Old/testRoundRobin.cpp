#include "RoundRobinProcessScheduler.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;

int main() {

    srand(time(0));
    cout << fixed << setprecision(2);

    int numOfTest = 10;

    for (int i = 0; i < numOfTest; i++) {

        RoundRobinProcessScheduler test1;
        int timeSlide = rand() % 5 + 3;
        test1.timeSlice = timeSlide;
        int length = rand() % 10 + 1;
        int numOfProcess = length;
        int testList[length];
        int eachTurnoverTime[length];
        int totalTurnoverTime = 0;
        int sum = 0;

        int processTimes;

        for (int j = 0; j < length; j++) {
            processTimes = rand() % 20 +10;
            eachTurnoverTime[j] = 0;
            testList[j] = processTimes;
            test1.processTimes.insert(processTimes);
            test1.eachTurnaroundTime.push_back(0);
            test1.processDone.push_back(false);
            test1.size++;
        }

        cout << endl << "Test " << i + 1 << ":" << endl;
        cout << "TimeSlide: " << timeSlide << endl;
        cout << "Process time: ";

        for (int a = 0; a < length; a++) {
            cout << testList[a];

            if (a != length - 1)
                cout << ", ";
            else
                cout << endl;
        }

        for (int k = 0; numOfProcess > 0; k = (k + 1) % length) {

            if (testList[k] == 0)
                continue;

            if (testList[k] > timeSlide) {
                testList[k] -= timeSlide;
                totalTurnoverTime += timeSlide;
            } else {
                totalTurnoverTime += testList[k];
                eachTurnoverTime[k] = totalTurnoverTime;
                testList[k] = 0;
                numOfProcess--;
            }
        }

        test1.Process();

        cout << endl << "Expected result:" << endl;
        cout << "Turnover Time:" << endl;

        for (int n = 0; n < length; n++) {
            cout << "Process " << n + 1 << ": " << eachTurnoverTime[n] << endl;
            sum += eachTurnoverTime[n];
        }

        cout << "Average Turnover Time: " << sum * 1.0 / length << endl;

        cout << endl << "Actual result: " << endl;
        test1.ShowResults();
        cout << "------------------------------------------------------------------------" << endl;
    }

    cout << endl << "Testing by loading from process.txt:" << endl;

    RoundRobinProcessScheduler test2;
    test2.LoadFromFile("process.txt");

    test2.Process();
    test2.ShowResults();

    return 0;
}