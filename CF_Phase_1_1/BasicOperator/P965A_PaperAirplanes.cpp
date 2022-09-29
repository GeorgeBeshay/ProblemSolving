//
// Created by George on 9/29/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/965/A
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    double K, N, S, P;
    cin >> K >> N >> S >> P;
    cout << setprecision(20) <<ceil((ceil(N / S) * K) / P) << endl;
    return 0;
}