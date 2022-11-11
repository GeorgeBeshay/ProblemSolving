//
// Created by George on 11/11/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/472/A
 * Problem Status:
 */

#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    if(N % 2 == 0)
        cout << 4 << " " << N - 4 << endl;
    else
        cout << 9 << " " << N - 9 << endl;
    return 0;
}