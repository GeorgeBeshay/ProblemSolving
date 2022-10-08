//
// Created by George on 10/8/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/740/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ---------- Functions Prototype ----------
int getSumOfSubArray(vector<int> V, int L, int R);
bool checkMood(int U);
// ---------------- Separator ----------------

int main(){
    // ---------- Variables ----------
    int N, M, E, F, temp;
    vector<int> A;
    vector< pair<int, int> > B;
    vector<int> R;
    // ---------- Separator ----------
    cin >> N >> M;
    // ---------- Separator ----------
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        A.push_back(temp);
    }
    for(int i = 0 ; i < M ; i++){
        cin >> E >> F;
        B.push_back(make_pair(E, F));
    }
    // ---------- Separator ----------
    for(int i = 0 ; i < M ; i++){
        temp = getSumOfSubArray(A, B[i].first, B[i].second);
        if(checkMood(temp)){
            R.push_back(temp);
        } else
            continue;
    }
    // ---------- Separator ----------
    cout << getSumOfSubArray(R, 1, R.size()) << endl;
    // ---------- Separator ----------
    return 0;
}

int getSumOfSubArray(vector<int> V, int L, int R){
    int Answer = 0;
    // ---------- Separator ----------
    for(int i = L - 1 ; i <= R - 1 ; i++)
        Answer += V[i];
    // ---------- Separator ----------
    return Answer;
}

bool checkMood(int U){
    if(U > 0)
        return true;
    return false;
}