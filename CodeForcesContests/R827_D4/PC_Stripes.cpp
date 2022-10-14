//
// Created by George on 10/13/2022.
//

/*
 * Problem Link:        https://codeforces.com/contest/1742/problem/C
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>

using namespace std;

char check(string M[8]);

int main(){
    int T;
    string M[8];
    string T_;
    string garbage;
    vector<char> Answers;
    ;
    // ------------ Separator ------------
    cin >> T;
    getline(cin, garbage);
    while(T){
        getline(cin, garbage);
        T--;
        // ------------ Separator ------------
        for(int i = 0 ; i < 8 ; i++) {
            getline(cin, M[i]);
        }
        // ------------ Separator -----------
        Answers.push_back(check(M));
        // ------------ Separator -----------
        M->clear();
    }
    for(int i = 0 ; i < Answers.size() ; i++)
        cout << Answers[i] << endl;
    return 0;
}

char check(string M[8]){
    for(int i = 0 ; i < 8 ; i++){
        if(M[i] == "RRRRRRRR"){
            return 'R';
        }
    }
    return 'B';
}
