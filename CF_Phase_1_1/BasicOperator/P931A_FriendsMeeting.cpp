//
// Created by George on 10/17/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/931/A
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <algorithm>
using namespace std;

int series(int N){
    return (N * (N+1))/2;
}

int main(){
    // ---------- Separator ----------
    int A, B, Diff;
    cin >> A >> B;
    Diff = abs(A-B)/2;
    cout << series(Diff) + series(abs(A-B)-Diff) << endl;
    // ---------- Separator ----------
    return 0;
}