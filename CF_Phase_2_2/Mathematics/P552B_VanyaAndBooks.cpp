//
// Created by George on 10/19/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/552/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
    // ------------ Separator ------------
    long long int X, N, temp;
    long long Answer = 0;
    cin >> N;
    // ------------ Separator ------------
    string S = to_string(N);
    X = pow(10, S.length()-1);
    while(X > 0){
        temp = (N - X + 1);
        Answer += temp * S.length();
        X /= 10;
        N -= temp;
        S = to_string(N);
    }
    cout << setprecision(40) << Answer << endl;
    // ------------ Separator ------------
    return 0;
}