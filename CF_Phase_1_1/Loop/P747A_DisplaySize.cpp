//
// Created by George on 12/24/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/747/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, a, b;
    cin >> n;
    a = floor(sqrt(n));
    b = ceil(sqrt(n));
    while(a * b != n){
        if(a * b > n)
            a--;
        else
            b++;
    }

    cout << a << " " << b << endl;
    return 0;
}