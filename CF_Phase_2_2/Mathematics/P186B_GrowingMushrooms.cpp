//
// Created by George on 10/2/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/186/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

int main(){
    // ------------ Separator ------------
    int N, T1, T2, K;
    cin >> N >> T1 >> T2 >> K;
    K = 100 - K;
    // ------------ Separator ------------
    vector< pair<int, int> > V(N);
    for(int i = 0 ; i < N ; i++)
        cin >> V[i].first >> V[i].second;
    // ------------ Separator ------------
    vector <double> Answers (N);
    map <double, vector<int>, greater<double> > index;
    for(int i = 0 ; i < N ; i++){
        if( (V[i].first * T1 * K / double(100)) + (V[i].second * T2)  >=  (V[i].second * T1 * K / double(100)) + (V[i].first * T2) )
            Answers[i] = (V[i].first * T1 * K / double(100)) + (V[i].second * T2);
        else
            Answers[i] = (V[i].second * T1 * K / double(100)) + (V[i].first * T2);
        index[Answers[i]].push_back(i+1);
    }
    for(auto I : index)
        for(int i = 0 ; i < I.second.size() ; i++)
            cout << fixed << setprecision(2) << I.second[i] << " " << I.first << endl;
    // ------------ Separator ------------
    return 0;
}