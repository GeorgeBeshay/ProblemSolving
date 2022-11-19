//
// Created by George on 11/19/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/4/A?f0a28=1
 * ProblemStatus:       Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    if (N % 2 == 0 && N > 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}