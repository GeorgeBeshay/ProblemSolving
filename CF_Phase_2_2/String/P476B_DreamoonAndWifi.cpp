//
// Created by George on 9/24/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/476/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

double TheAmazingFunction(string X, string Y);
double factorial(int n);
double nCr(int n, int r);

int main() {
    // ---------------------------- Separator ----------------------------
    string X, Y;
    // ---------------------------- Separator ----------------------------
    getline(cin, X);
    getline(cin, Y);
    // ---------------------------- Separator ----------------------------
    cout << setprecision(13) <<TheAmazingFunction(X, Y) << endl;
    // ---------------------------- Separator ----------------------------
    return 0;
}

double factorial(int n){
    if(n == 0)
        return 1;
    double fact = 1;
    for(int i = 2 ; i <= n ; i++)
        fact = fact * i;
    return fact;
}

double nCr(int n, int r){
    return (factorial(n)) / ((factorial(r))*(factorial(n-r)));
}

double TheAmazingFunction(string X, string Y){
    double Answer = 0;
    int A[] = {0, 0, 0};        // X -> {+, -, ?}
    int B[] = {0, 0, 0};        // Y -> {+, -, ?}
    // ---------------------------- Separator ----------------------------
    for(int i = 0 ; i < X.size() ; i++){
        // ---------- Separator ----------
        if(X[i] == '+')
            A[0]++;
        else
            A[1]++;
        // ---------- Separator ----------
        if(Y[i] == '+')
            B[0]++;
        else if (Y[i] == '-')
            B[1]++;
        else
            B[2]++;
        // ---------- Separator ----------
    }
    for(int i = 0 ; i < 2 ; i++){
        if(B[i] > A[i]) {
            return 0;
        }
    }
    if(B[2] == 0) {
        if (A[0] != B[0] || A[1] != B[1])
            return 0;
    } else {
        if (A[0] - B[0] + A[1] - B[1] != B[2])
            return 0;
    }
    Answer = nCr(B[2], A[0]-B[0]) / pow(2.0, B[2]);
//    cout << nCr(B[2], A[0]-B[0]) << " / " << pow(2.0, B[2]) << endl;
    // ---------------------------- Separator ----------------------------
    return Answer;
}