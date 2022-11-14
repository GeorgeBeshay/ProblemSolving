//
// Created by George on 11/14/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/851/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int N, K , T;
    cin >> N >> K >> T;
    if(T <= K)
        cout << T << endl;
    else if(T <= N)
        cout << K << endl;
    else
        cout << N + K - T << endl;
    return 0;
}