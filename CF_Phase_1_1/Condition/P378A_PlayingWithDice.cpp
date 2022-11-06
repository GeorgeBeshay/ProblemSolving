//
// Created by George on 11/6/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/378/A
 * Problem Status:      Accepted
 */

#include <iostream>
using namespace std;

int main(){
    int A, B, F, D, S;
    F = 0;
    D = 0;
    S = 0;
    cin >> A >> B;
    for(int i = 1 ; i < 7 ; i++){
        if(abs(A-i) < abs(B-i))
            F++;
        else if(abs(A-i) > abs(B-i))
            S++;
        else
            D++;
    }
    cout << F << " " << D << " " << S << endl;
    return 0;
}
