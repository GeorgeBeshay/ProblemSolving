//
// Created by George on 9/25/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/276/B
 * Problem Status:      Accepted.
 */

#include <iostream>

using namespace std;

void showArr(int A[], int m);
bool check(int A[]);

int main() {
    string S;
    int chars[26] = {0};
    // ------------------ Separator ------------------
    getline(cin, S);
    // ------------------ Separator ------------------
    for(auto X : S)
        chars[int(X)-97]++;
//     ------------------ Separator ------------------
    bool first_turn = true;
    while(S.size() > 0){
        if(check(chars)){
               if(first_turn){
                   cout << "First" << endl;
                   exit(0);
               } else {
                   cout << "Second" << endl;
                   exit(0);
               }
        } else {
            first_turn = !first_turn;
            for(int i = 0 ; i < 26 ; i++){
                if(chars[i] % 2 == 1){
                    chars[i]--;
                    break;
                }
            }
        }
    }
    return 0;
}

bool check(int A[]){
    int odd_count = 0;
    for(int i = 0 ; i < 26 ; i++){
        if(A[i] % 2 == 0)
            continue;
        else {
            odd_count++;
        }
    }
    if(odd_count <= 1)
        return true;
    else
        return false;
}

void showArr(int A[], int m){
    for(int i = 0 ; i < m ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
