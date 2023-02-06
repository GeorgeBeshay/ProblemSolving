//
// Created by George on 2/6/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/302/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n, m, c, t, total = 0;       // n => number of songs - m => the moments he liked
    cin >> n >> m;
    map<int, int> songs;
    vector<int> moments(m);
    for(int i = 0 ; i < n ; i++){
        cin >> c >> t;
        songs[total + c * t] = i+1;
        total += c * t;
    }
    auto I = songs.begin();
    for(int i = 0 ; i < m ; i++) {
        cin >> moments[i];
        while(moments[i] > I->first){
            I++;
        }
        cout << I->second << endl;
    }
    return 0;
}