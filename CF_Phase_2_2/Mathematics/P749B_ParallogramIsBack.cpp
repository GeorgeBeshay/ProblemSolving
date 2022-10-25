//
// Created by George on 10/23/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/749/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <set>
#include <vector>
#include <math.h>
using namespace std;

bool checkAcute(pair<int, int> X, pair<int, int> Y);

int main(){
    // -------------- Separator --------------
    pair<int, int> X, Y, Z;
    set< pair<int, int> > W;
    // -------------- Separator --------------
    cin >> X.first >> X.second >> Y.first >> Y.second >> Z.first >> Z.second;
    vector< pair<int, int> > V = {X, Y, Z};
    // -------------- Separator --------------
    int DiffX = 0;
    int DiffY = 0;
    bool acuteFlag;
    pair<int, int> Temp;
    pair<int, int> Other;
    for(int i = 0 ; i < 3 ; i++){
        switch (i) {
            case 0:
                Other = {1, 2};
                break;
            case 1:
                Other = {0, 2};
                break;
            case 2:
                Other = {1, 0};
                break;
            default:
                break;
        }
        DiffX = abs(V[Other.first].first - V[Other.second].first);
        DiffY = abs(V[Other.first].second - V[Other.second].second);
        acuteFlag = checkAcute(V[Other.first], V[Other.second]);
        if(!acuteFlag) {
            Temp = {V[i].first + DiffX, V[i].second - DiffY};
            W.insert(Temp);
            Temp = {V[i].first - DiffX, V[i].second + DiffY};
            W.insert({Temp.first, Temp.second});
        } else {
            Temp = {V[i].first + DiffX, V[i].second + DiffY};
            W.insert(Temp);
            Temp = {V[i].first - DiffX, V[i].second - DiffY};
            W.insert(Temp);
        }
    }
    // -------------- Separator --------------
    cout << W.size() << endl;
    for(auto I : W)
        cout << I.first << " " << I.second << endl;
    // -------------- Separator --------------
    return 0;
}

bool checkAcute(pair<int, int> X, pair<int, int> Y){
    if(X.first == Y.first || X.second == Y.second)
        return false;
    pair<int, int> D, U;
    if(X.second < Y.second) {
        D = X;
        U = Y;
    } else {
        D = Y;
        U = X;
    }
    if(D.first < U.first)
        return true;
    else
        return false;
}