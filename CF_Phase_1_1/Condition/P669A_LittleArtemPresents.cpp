//
// Created by George on 10/29/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/669/A
 * Problem Status:
 */

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    int N;
    cin >> N;
    cout << setprecision(10) << 2*(N/3)+(ceil(N/3.0)-(N/3)) << endl;
    return 0;
}