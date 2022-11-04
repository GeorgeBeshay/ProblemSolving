//
// Created by George on 11/4/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/752/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int N, M, K, L, D;
    char C = 'L';
    // ---------------- Separator ----------------
    cin >> N >> M >> K;
    // ---------------- Separator ----------------
    L = ceil(float(K) / (2 * M));
    D = ceil((K - (2 * M)*(L-1)) / 2.0);
    if(K % 2 == 0)
        C = 'R';
    // ---------------- Separator ----------------
    cout << L << " " << D << " " << C << endl;
    // ---------------- Separator ----------------
    return 0;
}