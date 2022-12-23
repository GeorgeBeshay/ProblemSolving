//
// Created by George on 12/23/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/681/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i <= floor(n / double(1234567)) ; i++){
        for(int j = 0 ; j <= floor((n - (i * 1234567)) / 123456.0) ; j++){
            if( (n - (i * 1234567 + j * 123456)) % 1234 == 0 ) {
                cout << "YES" << endl;
                exit(0);
            }
        }
    }
    cout << "NO" << endl;


    return 0;
}