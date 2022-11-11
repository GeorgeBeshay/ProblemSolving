//
// Created by George on 11/11/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/950/A
 * Problem Status:          Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int L, R, A, Ans;
    cin >> L >> R >> A;
    Ans = min(L, R);
    if(A <= abs(R-L))
        Ans += A;
    else {
        Ans += abs(R-L);
        A -= abs(R-L);
        Ans += A / 2;
    }
    Ans *= 2;
    cout << Ans << endl;
    return 0;
}