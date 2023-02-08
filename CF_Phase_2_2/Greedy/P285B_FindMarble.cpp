//
// Created by George on 2/8/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/285/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int ans = 0, n, s, t, current;
    cin >> n >> s >> t;
    vector<int> v(n);
    map<int, int> m;
    map<int, bool> passed;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
        m[v[i]] = i;
    }
    current = s;
    while(true){
        if(v[v[m[current]] - 1] == current || current == t)
            break;
        current = v[v[m[current]] - 1];
        ans++;
        if(passed[current])
            break;
        passed[current] = true;
    }
    if(current == t)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}