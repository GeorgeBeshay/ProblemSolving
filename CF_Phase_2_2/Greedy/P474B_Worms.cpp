//
// Created by George on 2/11/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/474/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n, m;
    cin >> n;
    vector<int> v(n);
    vector<int> x(n);
    map<int, int> cache;
    for(int i = 0 ; i < n ; i++) {
        cin >> v[i];
        if(i > 0)
            x[i] = x[i-1] + v[i-1];
        else
            x[0] = 1;
        cache[x[i]] = i+1;
    }
    cin >> m;
    vector<int> queries(m);
    for(int i = 0 ; i < m ; i++)
        cin >> queries[i];
    for(int i = 0 ; i < m ; i++){
        int tempQuery = queries[i];
        vector<int> temp;
        while(cache[tempQuery] == 0){
            cache.erase(tempQuery);
            temp.push_back(tempQuery--);
        }
        for(int u = 0 ; u < temp.size() ; u++)
            cache[temp[u]] = cache[tempQuery];
        cout << cache[queries[i]] << endl;
    }
    return 0;
}