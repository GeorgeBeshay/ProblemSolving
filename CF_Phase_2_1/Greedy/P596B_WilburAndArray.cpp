//
// Created by George on 10/24/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/596/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <vector>
using namespace std;
int main(){
    // --------- Separator ---------
    long long N, C = 0, Ans = 0;
    cin >> N;
    // --------- Separator ---------
    vector<long long> V(N);
    for(int i = 0 ; i < N ; i++)
        cin >> V[i];
    // --------- Separator ---------
    for(int i = 0 ; i < N ; i++) {
        Ans += abs(V[i] - C);
        C = V[i];
    }
    // --------- Separator ---------
    cout << Ans << endl;
    // --------- Separator ---------
    return 0;
}