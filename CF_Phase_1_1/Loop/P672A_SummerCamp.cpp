//
// Created by George on 12/9/2022.
//

/*
 * Problem Link:    https://codeforces.com/problemset/problem/672/A
 * Problem Status:  Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int N, count = 1;
    string S = "";
    cin >> N;
    while(S.size() < N)
        S += to_string(count++);
    cout << S[N-1] << endl;
    return 0;
}