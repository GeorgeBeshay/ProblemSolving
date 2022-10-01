//
// Created by George on 10/1/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/828/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    // ---------- Separator ----------
    int N, M;
    string ignore;
    cin >> N >> M;
    string A[N];
    getline(cin, ignore);
    // ---------- Separator ----------
    for(int i = 0 ; i < N ; i++){
        getline(cin, A[i]);
    }
    // ---------- Separator ----------
    int B_Count = 0;
    long long greatest_side = 0;
    vector <int> rows_occurrence;
    vector <int> cols_occurrence;
    // ---------- Separator ----------
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < A[i].size() ; j++){
            if(A[i][j] == 'B') {
                // ---------- Separator ----------
                B_Count++;
                // ---------- Separator ----------
                rows_occurrence.push_back(i);
                cols_occurrence.push_back(j);
                // ---------- Separator ----------
            }
        }
    }
    // ---------- Separator ----------
    sort(rows_occurrence.begin(), rows_occurrence.end());
    sort(cols_occurrence.begin(), cols_occurrence.end());
    // ---------- Separator ----------
    if(rows_occurrence.size() == 0 && cols_occurrence.size() == 0)
        greatest_side = 1;
    if(rows_occurrence.size() != 0){
        greatest_side = rows_occurrence[rows_occurrence.size()-1] - rows_occurrence[0] + 1;
    }
    if(cols_occurrence.size() != 0){
        if(greatest_side < cols_occurrence[cols_occurrence.size() - 1] - cols_occurrence[0] + 1)
            greatest_side = cols_occurrence[cols_occurrence.size() - 1] - cols_occurrence[0] + 1;
    }
    // ---------- Separator ----------
    if(greatest_side > min(N, M))
        cout << -1 << endl;
    else
        cout << (greatest_side * greatest_side) - B_Count << endl;
    // ---------- Separator ----------
    return 0;
}