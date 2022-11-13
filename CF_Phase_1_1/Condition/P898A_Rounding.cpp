//
// Created by George on 11/13/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/898/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    long N;
    cin >> N;
    if(N % 10 <= 5)
        cout << setprecision(20) << (N - (N % 10)) << endl;
    else
        cout << setprecision(20) << (N + (10 - (N % 10))) << endl;
    return 0;
}