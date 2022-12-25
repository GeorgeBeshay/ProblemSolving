//
// Created by George on 12/25/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/935/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int n, ans = 0;
    cin >> n;
    for(int i = 1 ; i < n ; i++){
        if((n-i) % i == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}