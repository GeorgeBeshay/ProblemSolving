//
// Created by George on 12/22/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/478/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long n, m, temp1;
    cin >> n >> m;
    temp1 = floor(n / m);
    cout << m * (temp1*(temp1-1) / 2) + temp1 * (n - (temp1 * m)) << " " << (n - m + 1) * (n - m) / 2 << endl;
    return 0;
}