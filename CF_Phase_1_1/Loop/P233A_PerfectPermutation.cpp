//
// Created by George on 12/4/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/233/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    if(N % 2 == 1)
        cout << -1 << endl;
    else {
        while(N >= 1)
            cout << N-- << " ";
    }
    return 0;
}