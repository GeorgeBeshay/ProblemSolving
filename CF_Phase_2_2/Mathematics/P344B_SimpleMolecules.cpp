//
// Created by George on 10/16/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/344/B
 * Problem Status:          Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int A, B, C, X, Y, Z;
    cin >> A >> B >> C;
    X = (A+B-C)/2;
    Y = B-X;
    Z = A-X;
    if(X < 0 || Y < 0 || Z < 0 || X + Y + Z != (A+B+C)/2.0)
        cout << "Impossible" << endl;
    else
        cout << X << " " << Y << " " << Z << endl;
    return 0;
}