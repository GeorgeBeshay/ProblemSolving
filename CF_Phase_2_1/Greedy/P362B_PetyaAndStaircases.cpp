//
// Created by George on 10/21/2022.
//

/*
 * Problem Link:           https://codeforces.com/problemset/problem/362/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxConsecutive(vector<int> V);

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> V(M);
    // ------------- Separator -------------
    if(M > 0) {
        for (int i = 0; i < M; i++)
            cin >> V[i];
        // ------------- Separator -------------
        sort(V.begin(), V.end());
        // ------------- Separator -------------
        if (V[0] == 1 || V[V.size() - 1] == N || getMaxConsecutive(V) > 2)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        // ------------- Separator -------------
    } else
        cout << "YES" << endl;
    return 0;
}

int getMaxConsecutive(vector<int> V){
    int Ans = 0;
    int temp = 1;
    // ------------- Separator -------------
    for(int i = 1 ; i < V.size() ; i++){
        if(V[i] == V[i-1]+1)
            temp++;
        else
            temp = 1;
        if(temp > Ans)
            Ans = temp;
    }
    // ------------- Separator -------------
    return Ans;
}