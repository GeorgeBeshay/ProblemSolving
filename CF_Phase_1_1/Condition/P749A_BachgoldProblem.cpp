//
// Created by George on 10/28/2022.
//

/*
 * Problem Link:            https://codeforces.com/contest/749/problem/A
 * Problem Status:          Accepted.
 */

#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int N;
    cin >> N;
    if(N % 2 == 0){
        cout << N / 2 << endl;
        for(int i = 0 ; i < N / 2 ;i++)
            cout << "2 ";
    } else {
        cout << ((N-3) / 2)  + 1 << endl;
        for(int i = 0 ; i < (N-3) / 2 ;i++)
            cout << "2 ";
        cout << "3 " << endl;
    }
    return 0;
}