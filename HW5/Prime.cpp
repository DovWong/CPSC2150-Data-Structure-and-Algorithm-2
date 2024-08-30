#include <iostream>
#include <vector>

using namespace std;

vector<int> SieveOfEratosthenes2(int n) { //Find all Primes from 2 to n

    vector<bool> primesCheck(n + 1, true);
    vector<int> primesList;

    if (n <= 1)
        return primesList;

    int curNum = 2;

    while (curNum * curNum <= n) {

        primesList.push_back(curNum);

        for (int i = curNum * curNum; i < primesCheck.size(); i += curNum){ //start from curNum * curNum as multiples of num that less than curNum are tested
            if(primesCheck[i])
                primesCheck[i] = false;
        }

        while (++curNum < primesCheck.size() && !primesCheck[curNum]) {} //increment curNum to next Primes
    }

    for (int i = curNum; i < primesCheck.size(); i += 2) { //WE can skip all even number. It works even n = 2
        if(primesCheck[i])
            primesList.push_back(i);
    }

    return primesList;
}

vector<int> SieveOfEratosthenes(int n) { //Find n Prime numbers

    vector<bool> primesCheck(n + 1, true);
    vector<int> primesList(n);

    primesCheck[0] = false;
    primesCheck[1] = false;

    if (n <= 0)
        return primesList;

    int curNum = 2;
    int listIndex = 0;

    while (listIndex != n) {

        primesList[listIndex++] = curNum;

        for (int i = curNum * curNum; i < primesCheck.size(); i += curNum){ //start from curNum * curNum as multiples of num that less than curNum are tested
            if(primesCheck[i])
                primesCheck[i] = false;
        }

        while (++curNum < primesCheck.size() && !primesCheck[curNum]) {} //increment curNum to next Primes

        //same as before, multiples of num that less than curNum are all tested
        //e.g. if curNum is 11, 2 * 11, 3 * 11 .... are tested, I just need to start as 11 * 11
        // if the test list is 2 to 100, as 11 * 11 > 100, it means 100 = a * b, a > 11 and b < 11, and b are tested
        // this rule also applicable to numbers that less than 100, so the remaining number in the checklist are all Primes
        if (curNum * curNum >= primesCheck.size()) {

            while (curNum < primesCheck.size() && listIndex < n) {
                if (primesCheck[curNum])
                    primesList[listIndex++] = curNum;

                curNum++;
            }

            if (listIndex == n)
                return primesList;
            else {

                int oldSize = primesCheck.size();

                primesCheck.resize(oldSize * 2, true);

                for (int j = 0; j < listIndex; j++) {

                    int num = oldSize;

                    while (num % primesList[j] != 0) //Use ++ to find divisable then reassign i to that
                        num++;

                    for (int k = num; k < primesCheck.size(); k += primesList[j]) {
                        if(primesCheck[k])
                            primesCheck[k] = false;
                    }
                }

                while (++curNum < primesCheck.size() && !primesCheck[curNum]) {} //increment curNum to next Primes
            }
        }
    }

    primesList[listIndex] = curNum;

    return primesList;
}

bool IsPrime(int num) {

    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0 && num != i)
            return false;
    }

    return true;
}

vector<int> BrutalForce(int n) { //brutal force

    vector<int> primeList;

    for (int i = 2; primeList.size() < n; i++) {

        if (IsPrime(i))
            primeList.push_back(i);
    }

    return primeList;
}

bool IsPrime2(int num, const vector<int>& primeList) {

    if (num <= 1)
        return false;

    for (int i = 0; i < primeList.size() && primeList[i] * primeList[i] <= num; i++) {
        if (num % primeList[i] == 0)
            return false;
    }

    return true;
}

vector<int> BrutalForce2(int n) { //brutal force

    vector<int> primeList;

    for (int i = 2; primeList.size() < n; i++) {

        if (IsPrime2(i, primeList))
            primeList.push_back(i);
    }

    return primeList;
}