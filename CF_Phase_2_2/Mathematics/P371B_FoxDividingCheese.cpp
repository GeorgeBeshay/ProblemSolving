//
// Created by George on 2/4/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/371/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
map<int, int> PrimeFactorization(int Num);
int main(){
        int a,b, stepsCount = 0, finalA, finalB;
        cin >> a >> b;
        finalA = 1;
        finalB = 1;
        int gcd = __gcd(a, b);
        a /= gcd; b/= gcd;
        map<int, int> aFactors = PrimeFactorization(a);map<int, int> bFactors = PrimeFactorization(b);
        for(auto I : aFactors) {
            if(I.first == 1)
                continue;
            stepsCount += I.second;
            if(I.first > 5){
                cout << -1 << endl;
                exit(0);
            }
        }
        for(auto I : bFactors) {
            if(I.first == 1)
                continue;
            stepsCount += I.second;
            if(I.first > 5){
                cout << -1 << endl;
                exit(0);
            }
        }
        cout << stepsCount << endl;
    return 0;
}

map<int, int> PrimeFactorization(int Num) {
    std::map<int, int> factors;
    std::vector<int> basePrimeNums;
    for (int X = 2; X <= std::ceil(std::sqrt(Num)) + 1; X++) {
        bool flag = true;
        for (int temp = 2; temp < X; temp++) {
            if (X % temp == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            basePrimeNums.push_back(X);
        }
    }
    int tempNum = Num;
    bool finished = false;
    while (!finished) {
        finished = true;
        for (auto factor : basePrimeNums) {
            if (tempNum % factor == 0) {
                if (factors.find(factor) != factors.end()) {
                    factors[factor]++;
                }
                else {
                    factors[factor] = 1;
                }
                tempNum = tempNum / factor;
                finished = false;
                break;
            }
        }
    }
    if (int(tempNum) != 1) {
        factors[int(tempNum)] = 1;
    }
    if (factors.empty()) {
        factors[Num] = 1;
    }
    return factors;
}