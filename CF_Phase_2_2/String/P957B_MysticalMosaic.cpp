//
// Created by George on 10/1/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/957/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
    // -------------- Separator --------------
    int N, M;
    string ignore;
    cin >> N >> M;
    getline(cin, ignore);
    // -------------- Separator --------------
    string A[N];
    set <string> S;
    int X[N];
    int Y[M];
    // -------------- Separator --------------
    for(int i = 0 ; i < N ; i++) {
        getline(cin, A[i]);
        S.insert(A[i]);
        X[i] = 0;
    }
    for(int i = 0 ; i < M ; i++)
        Y[i] = 0;
    // -------------- Separator --------------
    for(auto I : S){
        for(int i = 0 ; i < I.size() ; i++){
            if(I[i] == '#'){
                if(Y[i] == 0){
                    Y[i] = 1;
                    continue;
                } else {
                    cout << "NO" << endl;
                    exit(0);
                }
            } else
                continue;
        }
    }
    // -------------- Separator --------------
    cout << "YES" << endl;
    // -------------- Separator --------------
    return 0;
}