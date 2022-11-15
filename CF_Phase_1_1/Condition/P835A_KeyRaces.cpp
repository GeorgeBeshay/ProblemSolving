//
// Created by George on 11/15/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/835/A
 * Problem Status:          Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int S, V1, V2, T1, T2, A, B;
    cin >> S >> V1 >> V2 >> T1 >> T2;
    A = (V1 * S) + (2 * T1);
    B = (V2 * S) + (2 * T2);
    if(A < B)
        cout << "First" << endl;
    else if(A > B)
        cout << "Second" << endl;
    else
        cout << "Friendship" << endl;
    return 0;
}