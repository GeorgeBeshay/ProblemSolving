//
// Created by George on 10/7/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/492/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    // ---------- Separator ----------
    int N, L;
    cin >> N >> L;
    vector <int> V(N);
    for(int i = 0 ; i < N ; i++)
        cin >> V[i];
    // ---------- Separator ----------
    sort(V.begin(), V.end());
    // ---------- Separator ----------
    vector<int> Answers;
    Answers.push_back(V[0]);
    Answers.push_back(L - V[N-1]);
    sort(Answers.begin(), Answers.end());
    double Max = Answers[1];
    for(int i = 1 ; i < N ; i++){
        double temp = (V[i] - V[i-1]) / 2.0;
        if(temp > Max)
            Max = temp;
    }
    // ---------- Separator ----------
    cout << fixed << setprecision(10) << Max << endl;
    // ---------- Separator ----------
    return 0;
}