//
// Created by George on 10/3/2022.
//

/*
 * Problem Link:    https://codeforces.com/problemset/problem/401/B
 * Problem Status:  Accepted.
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void showVec(vector<T> V);
void mySort(vector<int> *V);
pair<int ,int> theAmazingAnswer(vector<bool> V);

int main(){
    // ---------- Separator ----------
    int X, K;
    int T;
    vector<int> roundsJoined;
    vector<int> rounds;
    cin >> X >> K;
    vector<bool> flags(X-1);
    for(int i = 0 ; i < K ; i++){
        cin >> T;
        if(T == 1){
            int T2;
            cin >> T2;
            roundsJoined.push_back(T2);
            rounds.push_back(T2);
            cin >> T2;
            rounds.push_back(T2);
        } else {
            int T2;
            cin >> T2;
            roundsJoined.push_back(T2);
            rounds.push_back(T2);
        }
    }
    // ---------- Separator ----------
    mySort(&rounds);
    mySort(&roundsJoined);
    // ---------- Separator ----------
    for(int i = 0 ; i < rounds.size() ; i++){
        flags[rounds[i]-1] = true;
    }
    // ---------- Separator ----------
    cout << theAmazingAnswer(flags).first << " " << theAmazingAnswer(flags).second << endl;
    // ---------- Separator ----------
    return 0;
}

pair<int ,int> theAmazingAnswer(vector<bool> V){
    // ---------- Separator ----------
    pair<int, int> Ans = make_pair(0, 0);
    // ---------- Separator ----------
    for(int i = 0 ; i < V.size() ; i++){
        if(i == 0){
            if(!V[i]){
                Ans.second++;
                Ans.first++;
            }
            continue;
        }
        if(!V[i]){
            Ans.second++;
            if(V[i-1])
                Ans.first++;
            else {
                V[i] = true;
            }
        } else {
            continue;
        }
    }
    // ---------- Separator ----------
    return Ans;
}

template <typename T>
void showVec(vector<T> V){
    for(int i = 0 ; i <  V.size() ; i++)
        cout << V[i] << " ";
    for(auto I : V){
        cout << I << " ";
    }
    cout << endl;
}

void mySort(vector<int> *V){
    sort((*V).begin(), (*V).end());
}