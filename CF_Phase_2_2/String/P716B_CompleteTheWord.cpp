//
// Created by George on 9/26/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/716/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void check_end(string S, int begin, int end, int A[], int Q);

int main(){
    string S;
    getline(cin, S);
    int A[26] = {0};
    int Q = 0;
    // ------------ Separator ------------
    if(S.size() < 26){
        cout << "-1" << endl;
        exit(0);
    }
    // ------------ Separator ------------
    string temp = S.substr(S.size()-26, 26);
    for(auto X : temp){
        if(X == '?')
            Q++;
        else {
            A[int(X) - 65]++;
        }
    }
    // ------------ Separator ------------
    int last = S.size()-1;
    for(int i = S.size() - 26 ; i >= 0 ; i--){
        if(i != S.size() - 26) {
            if (S[last] == '?') {
                Q--;
            } else {
                A[int(S[last]) - 65]--;
            }
            if (S[i] == '?') {
                Q++;
            } else {
                A[int(S[i]) - 65]++;
            }
            last--;
        }
        check_end(S, i, last, A, Q);
    }
    cout << "-1" << endl;
    // ------------ Separator ------------
    return 0;
}

void check_end(string S, int begin, int end, int A[], int Q){
    int count = 0;
    vector<char> U;
    int index = 0;
    for(int i = 0 ; i < 26 ; i++){
        if(A[i] == 0){
            count++;
            U.push_back(char(i+65));
        }
    }
    if(Q >= count){
        for(int i = begin ; i <= end ; i++){
            if(S[i] == '?') {
                S[i] = U[index];
                index++;
                index %= U.size();
            }
        }
        for(int i = 0 ; i < S.size() ; i++){
            if(S[i] == '?') {
                S[i] = U[index];
                index++;
                index %= U.size();
            }
        }
        cout << S << endl;
        exit(0);
    }
}