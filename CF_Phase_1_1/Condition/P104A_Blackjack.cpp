//
// Created by George on 11/18/2022.
//

/*
 * Problem Link:        https://codeforces.com/contest/104/problem/A
 * Problem Status:      Accepted.
 */

#include <iostream>

using namespace std;

int main()
{
    int N, required;
    cin >> N;
    required = N - 10;
    if(required <= 0 || required >= 12)
        cout << 0 << endl;
    else {
        if(required >= 2 && required < 10){
            cout << 4 << endl;
        } else if (required == 1 || required == 11){
            cout << 4 << endl;
        } else if(required == 10){
            cout << 15 << endl;
        }
    }
    return 0;
}