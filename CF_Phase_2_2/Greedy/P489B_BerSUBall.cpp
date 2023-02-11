//
// Created by George on 2/11/2023.
//

/*
 * Problem Link:        https://codeforces.com/contest/489/problem/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    int n, m, ans = 0, temp;
    cin >> n;
    vector<int> boys(n);
    for(int i = 0 ; i < n ; i++)
        cin >> boys[i];
    cin >> m;
    vector<int> girls(m);
    for(int i = 0 ; i < m ; i++)
        cin >> girls[i];
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(abs(girls[j] - boys[i]) <= 1){
                ans++;
                girls[j] = -1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}