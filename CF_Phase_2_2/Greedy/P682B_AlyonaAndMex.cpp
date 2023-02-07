//
// Created by George on 2/7/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/682/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, max = 1;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0 ; i < n ; i++){
        if(v[i] >= max) {
            v[i] = max;
            max++;
        }
    }
    cout << max << endl;
    return 0;
}