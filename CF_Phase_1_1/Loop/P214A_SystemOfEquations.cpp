//
// Created by George on 12/23/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/214/A
 * Problem status:          Accepted.
 */

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 0 ; i * i <= n ; i++){
        for(int j = 0 ; j* j <= m ; j++){
            if(pow(i, 2) + j == n && pow(j, 2) + i == m)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}