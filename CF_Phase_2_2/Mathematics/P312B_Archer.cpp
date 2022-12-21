//
// Created by George on 12/21/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/312/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main(){
    double a, b, c, d;
    double f1, f2, f3;
    cin >> a >> b >> c >> d;
    f1 = a / b; f2 = c / d;
    f3 = (1-f1)*(1-f2);
    cout << setprecision(20) << f1*((1- pow(f3, 100000)) / (1-f3)) << endl;
    return 0;
}