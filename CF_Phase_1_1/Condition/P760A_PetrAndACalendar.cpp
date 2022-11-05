//
// Created by George on 11/5/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/760/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int M, D, Months, Days, Ans;
    Months = 31;
    cin >> M >> D;
    switch(M) {
        case 2:
            Months = 28;
            break;
        case 4:
            Months = 30;
            break;
        case 6:
            Months = 30;
            break;
        case 9:
            Months = 30;
            break;
        case 11:
            Months = 30;
            break;
        default:
            break;
    }
    Ans = 0;
    Ans += 1;
    Months -= (7 - D + 1);
    Ans += ceil(float(Months) / 7);
    cout << Ans << endl;
    return 0;
}