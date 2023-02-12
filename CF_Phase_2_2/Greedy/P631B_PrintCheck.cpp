//
// Created By George.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/631/B
 * Problem Status:      Accpeted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {
    int n, m, k, operation, id, color;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n);
    vector<vector<int>> queries(k);
    map<int, bool> rowColored;
    map<int, bool> colColored;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++)
            grid[i].push_back(0);
    }
    for(int i = 0 ; i < k ; i++){
        cin >> operation >> id >> color;
        id--;
        vector<int> temp;
        temp.push_back(operation);
        temp.push_back(id);
        temp.push_back(color);
        queries[i] = temp;
    }
    for(int i = k-1 ; i >= 0 ; i--){
        if(queries[i][0] == 1){
            if(rowColored[queries[i][1]])
                continue;
            for(int j = 0 ; j < m ; j++){
                if(grid[queries[i][1]][j] != 0)
                    continue;
                grid[queries[i][1]][j] = queries[i][2];
            }
            rowColored[queries[i][1]] = true;
        } else {
            if(colColored[queries[i][1]])
                continue;
            for(int j = 0 ; j < n ; j++){
                if(grid[j][queries[i][1]] != 0)
                    continue;
                grid[j][queries[i][1]] = queries[i][2];
            }
            colColored[queries[i][1]] = true;
        }
    }
    for(int i = 0 ; i < n ; i++) {
        for (int j = 0; j < m; j++)
           cout << grid[i][j] << " ";
        cout << endl;
    }
    return 0;
}