//
// Created by George on 2/9/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/454/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, greatest = 0;
    cin >> n;
    vector<int> v(n);
    vector<int> greatestIndices;
    bool sorted = true;
    for(int i = 0 ; i < n ; i++) {
        cin >> v[i];
        if(v[i] == greatest)
            greatestIndices.push_back(i);
        if(v[i] > greatest){
            greatest = v[i];
            greatestIndices.clear();
            greatestIndices.push_back(i);
        }
        if(i > 0)
            if(v[i] < v[i-1])
                sorted = false;
    }
    if(sorted){
        cout << 0 << endl;
        exit(0);
    }
    int greatestIndex = greatestIndices[0];
    for(int i = 1 ; i < greatestIndices.size() ; i++){
        if(greatestIndices[i] == greatestIndex + 1)
            greatestIndex = greatestIndices[i];
    }
    rotate(v.begin(), v.begin() + n - (n - greatestIndex - 1), v.end());
    bool good = true;
    for(int i = 0 ; i < n - 1 ; i++){
        if(v[i] > v[i+1]){
            good = false;
            break;
        }
    }
    if(good)
        cout << n - greatestIndex - 1 << endl;
    else
        cout << -1 << endl;
    return 0;
}