//
// Created by George on 10/25/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/581/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;
int main() {
    int X, Y;
    cin >> X >> Y;
    cout << min(X, Y) << " " << (max(X, Y) - min(X, Y))/2 << endl;
    return 0;
}