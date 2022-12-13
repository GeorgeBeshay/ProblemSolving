//
// Created by George on 12/13/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/148/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int  ans = 0, k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    for(int i = 1 ; i <= d ; i++){
        if(i % k == 0)
            ans++;
        else if(i % l == 0)
            ans++;
        else if(i % m == 0)
            ans++;
        else if(i % n == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}