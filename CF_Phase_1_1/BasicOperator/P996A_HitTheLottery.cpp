//
// Created by George on 9/26/2022.
//

/*
 * Problem Link:        https://codeforces.com/contest/996/problem/A
 * Problem Status:      Accepted
 */

#include <iostream>

using namespace std;

int main(){
    int A;
    cin >> A;
    int Ans = 0;
    Ans += A / 100;
    A = A % 100;
    Ans += A / 20;
    A = A % 20;
    Ans += A / 10;
    A = A % 10;
    Ans += A / 5;
    A = A % 5;
    Ans += A / 1;
    A = A % 1;
    cout << Ans << endl;
    return 0;
}
