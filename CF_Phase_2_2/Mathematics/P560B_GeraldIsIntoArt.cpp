//
// Created by George on 10/22/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/560/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <vector>
using namespace std;

int maxOfPair(pair<int, int> U);
bool checkMaxSide(pair<int, int> Board, pair<int, int> PaintingA, pair<int, int> PaintingB);

int main(){
    // ----------- Separator -----------
    pair<int, int> Board, PA, PB;
    vector< pair<int, int> > P;     // P -> Possibilities
    vector< pair<int, int> > O;     // P -> Possibilities_Filtered
    // ----------- Separator -----------
    cin >> Board.first >> Board.second >> PA.first >> PA.second >> PB.first >> PB.second;
    // ----------- Separator -----------
    if(checkMaxSide(Board, PA, PB)){
        cout << "NO" << endl;
        exit(0);
    }
    // ----------- Separator -----------
    P = {
            {PA.first + PB.first, max(PA.second, PB.second)},
            {PA.first + PB.second, max(PA.second, PB.first)},
            {PA.second + PB.first, max(PA.first, PB.second)},
            {PA.second + PB.second, max(PA.first, PB.first)}
    };
    for(auto I = P.begin(); I != P.end() ; I++)
        if(maxOfPair(*I) <= maxOfPair(Board))
            O.push_back(*I);
    for(auto I : O)
        if(I.first * I.second <= Board.first * Board.second) {
            cout << "YES" << endl;
            exit(0);
        }
    // ----------- Separator -----------
    cout << "NO" << endl;
    // ----------- Separator -----------
    return 0;
}

bool checkMaxSide(pair<int, int> Board, pair<int, int> PaintingA, pair<int, int> PaintingB){
    if(maxOfPair(PaintingA) > maxOfPair(Board) || maxOfPair(PaintingB) > maxOfPair(Board))
        return true;
    return false;
}

int maxOfPair(pair<int, int> U){
    return max(U.first, U.second);
}