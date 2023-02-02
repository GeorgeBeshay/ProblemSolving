//
// Created by George on 2/2/2023.
//

/**
* Problem Link:     https://codeforces.com/problemset/problem/189/B
 * Problem Status:  Accepted.
*/

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int w, h;
    cin >> w >> h;
    long long ans = 0;
    for(int diagLengthY = 2 ; diagLengthY <= h ; diagLengthY += 2){
        for(int diagLengthX = 2 ; diagLengthX <= w ; diagLengthX += 2){
            ans += (h - diagLengthY + 1) * (w - diagLengthX + 1);
        }
    }
    cout << ans << endl;
    return 0;
}