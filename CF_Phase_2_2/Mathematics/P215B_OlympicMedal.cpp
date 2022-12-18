//
// Created by George on 12/18/2022.
//

/*
 * Problem Link:        https://codeforces.com/contest/215/problem/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    int n, m, k, temp, a, b, R1 = 0, P1 = 0, P2 = -1;
    cin >> n;
    while(n > 0){
        n--;
        cin >> temp;
        if(temp > R1)
            R1 = temp;
    }
    cin >> m;
    while(m){
        m--;
        cin >> temp;
        if(temp > P1)
            P1 = temp;
    }
    cin >> k;
    while(k){
        k--;
        cin >> temp;
        if(temp < P2 || P2 == -1)
            P2 = temp;
    }
    cin >> a >> b;
    // --------------- Separator ---------------
    cout << setprecision(15) << sqrt( (pow(R1, 2.0)) / ((double(P2) / P1) * ( (double(a)/b) + (double(P1)/P2) )) ) << endl;
    // --------------- Separator ---------------
    return 0;
}