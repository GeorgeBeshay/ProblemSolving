//
// Created by George on 12/14/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/271/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
bool distinct(int K);
using namespace std;
int main(){
    int N;
    cin >> N;
    N++;
    while(!distinct(N)){
        N++;
    }
    cout << N << endl;
    return 0;
}

bool distinct(int K){
    string s = to_string(K);
    map<char, int> M;
    bool ans = true;
    for(char X : s){
        if(M[X] != 0){
            ans = false;
            break;
        } else {
            M[X]++;
        }
    }
    return ans;
}