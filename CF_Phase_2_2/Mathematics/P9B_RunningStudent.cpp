//
// Created by George on 10/31/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/9/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

double calcDist(pair<int, int> P, int X);
int mySolver(vector<int> Stops, int Vb, int Vs, pair<int, int> P);

int main(){
    int N, Vb, Vs;
    cin >> N >> Vb >> Vs;
    vector<int> Stops(N);
    // ------------- Separator -------------
    pair<int, int> P;
    for(int i = 0 ; i < N ; i++)
        cin >> Stops[i];
    cin >> P.first >> P.second;
    // ------------- Separator -------------
    cout << mySolver(Stops, Vb, Vs, P) << endl;
    // ------------- Separator -------------
    return 0;
}

int mySolver(vector<int> Stops, int Vb, int Vs, pair<int, int> P){
    map<double, int> M;
    double TotalTime;
    // ------------- Separator -------------
    if(Vs > Vb)
        return 2;
    for(int i = 1 ; i < Stops.size() ; i++){
        TotalTime = (Stops[i]/double(Vb)) + (calcDist(P, Stops[i])/Vs);
        M[TotalTime] = i+1;
    }
    // ------------- Separator -------------
    return M.begin()->second;
}

double calcDist(pair<int, int> P, int X){
    return sqrt(pow(P.first - X, 2) + pow(P.second, 2));
}