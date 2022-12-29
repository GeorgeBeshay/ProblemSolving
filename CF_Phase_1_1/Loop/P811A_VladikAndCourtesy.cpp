//
// Created by George on 12/29/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/811/A
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a, b, n1;
    cin >> a >> b;
    n1 = floor(sqrt(a));
    if(b >= n1 * (n1+1)){
        cout << "Vladik" << endl;
    } else {
        cout << "Valera" << endl;
    }
    return 0;
}