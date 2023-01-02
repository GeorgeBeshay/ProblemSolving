//
// Created by George on 1/2/2023.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/822/A
 * Problem status:          Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int a, b, temp;
    cin >> a >> b;
    temp = min(a, b);
    for(int i = temp - 1; i >= 1 ; i--)
        temp *= i;
    cout << temp << endl;
    return 0;
}