//
// Created by George on 11/16/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/832/A
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <math.h>
using namespace std;
int main(){
    long long N, K;
    cin >> N >> K;
    if((long long)floor(N / K) % 2 == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}