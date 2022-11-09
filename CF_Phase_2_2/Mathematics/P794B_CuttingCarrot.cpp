//
// Created by George on 11/9/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/794/B
 * Problem Status:          Accepted.
 */
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
    // ------------ Separator ------------
    int N, H, C = 1;
    cin >> N >> H;
    // ------------ Separator ------------
    while(C <= N-1){
        cout << setprecision(20) << double(H) * sqrt(double(C) / N) << " ";
        C++;
    }
    // ------------ Separator ------------
    return 0;
}