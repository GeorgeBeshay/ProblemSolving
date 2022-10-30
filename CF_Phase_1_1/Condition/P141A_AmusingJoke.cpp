//
// Created by George on 10/30/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/141/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
using namespace std;

int main(){
    // ---------------- Separator ----------------
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    // ---------------- Separator ----------------
    map<char, int> M;
    for(int i = 0 ; i < s3.length() ; i++)
        M[s3[i]]++;
    for(int i = 0 ; i < s1.length() ; i++){
        if(M[s1[i]] == 0) {
            cout << "NO" << endl;
            exit(0);
        } else
            M[s1[i]]--;
    }
    for(int i = 0 ; i < s2.length() ; i++){
        if(M[s2[i]] == 0) {
            cout << "NO" << endl;
            exit(0);
        } else
            M[s2[i]]--;
    }
    for(auto I : M){
        if(I.second != 0){
            cout << "NO" << endl;
            exit(0);
        }
    }
    // ---------------- Separator ----------------
    cout << "YES" << endl;
    // ---------------- Separator ----------------
    return 0;
}