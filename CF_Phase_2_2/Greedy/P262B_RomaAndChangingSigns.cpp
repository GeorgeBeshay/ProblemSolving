//
// Created by George on 2/8/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/262/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    while(k > 0) {
        if(v[0] >= 0){
            if(k % 2 == 1)
                v[0] *= -1;
            k = 0;
            break;
        }
        for (int i = 0; i < n; i++) {
            if(v[i] <= 0) {
                v[i] *= -1;
                k--;
            }
            if (k == 0)
                break;
        }
        sort(v.begin(), v.end());
    }
    int ans = 0;
    for(int x : v)
        ans += x;
    cout << ans << endl;
    return 0;
}