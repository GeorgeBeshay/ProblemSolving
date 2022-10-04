//
// Created by George on 10/4/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/424/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

template <typename T>
void showVec(vector< T > V);
void showMap(map< double, int > M);

int main(){
    // ---------- Variables And Scanning Input ----------
    int N, S;
    cin >> N >> S;
    int R = 1000000 - S;
    vector< pair< int, int > > V(N);
    int A[N];
    for(int i = 0 ; i < N ; i++)
        cin >> V[i].first >> V[i].second >> A[i];
    // ---------- Separator ----------
    vector <double> Radius(N);
    map <double, int> Table;
    for(int i = 0 ; i < N ; i++) {
        Radius[i] = sqrt(pow(V[i].first, 2) + pow(V[i].second, 2));
        Table[Radius[i]] += A[i];
    }
    // ---------- Separator ----------
    if(R == 0){
        cout << 0 << endl;
        exit(0);
    }
    for(auto I : Table){
        R -= I.second;
        if(R <= 0){
            cout << setprecision(10) << I.first << endl;
            exit(0);
        }
    }
    if(R <= 0){
        cout << setprecision(10) << (*Table.end()).second << endl;
        exit(0);
    } else {
        cout << -1 << endl;
        exit(0);
    }
    // ---------- Separator ----------
    return 0;
}

template <typename T>
void showVec(vector< T > V){
    for(int i = 0 ; i < V.size() ; i++){
        cout << setprecision(10) << V[i] << endl;
    }
}

void showMap(map< double, int > M){
    for(auto I : M)
        cout << I.first << " : " << I.second << endl;
}