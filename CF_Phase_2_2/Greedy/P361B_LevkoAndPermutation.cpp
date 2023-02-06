//
// Created by George on 2/6/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/361/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        v[i] = i+1;
    for(int i = 1 ; i < n - 1 ; i++){
        if(k == 0)
            swap(v[i], v[i+1]);
        else
            k--;
    }
    if(k == 0)
        swap(v[0], v[n-1]);
    else if(k > 1 || n == 1){
        cout << -1 << endl;
        exit(0);
    }
    for(auto I : v)
        cout << I << " ";

}