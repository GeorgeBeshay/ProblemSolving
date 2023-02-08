//
// Created by George on 2/8/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/714/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n, temp;
    cin >> n;
    map<int, int> m;
    vector<int> v;
    for(int i = 0 ; i < n ; i++) {
        cin >> temp;
        m[temp]++;
    }
    if(m.size() > 3) {
        cout << "NO" << endl;
        exit(0);
    } else if(m.size() == 1 || m.size() == 2){
        cout << "YES" << endl;
        exit(0);
    }
    for(auto I : m)
        v.push_back(I.first);
    if(v[1] - v[0] == v[2] - v[1])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}