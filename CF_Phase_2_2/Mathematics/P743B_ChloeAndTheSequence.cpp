//
// Created by George on 10/9/2022.
//
/*
 * Problem Link:            https://codeforces.com/contest/743/problem/B
 * Problem Status:          Accepted.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

template <typename T>
void showVec(vector<T> V);
long long init_pos(int X);
long long step(int X);

int main(){
    // ---------- Variables ----------
    int N;
    long long K;
    vector<int> A;
    A.push_back(1);
    int i = 1;
    bool flag = true;
    // ---------- Separator ----------
    cin >> N >> K;
    N--;
    K--;
    // ---------- Separator ----------
    while(i <= N + 1){
        if(K % step(i) == init_pos(i)){
            cout << i << endl;
            break;
        } else {
            i++;
        }
    }
    // ---------- Separator ----------
    return 0;
}

template <typename T>
void showVec(vector<T> V){
    for(auto I : V)
        cout << I << " ";
    cout << endl;
}

long long step(int X){
    if(X == 1)
        return 2;
    if(X == 2)
        return 4;
    return 2*init_pos(X) + 2;
}

long long init_pos(int X){
    return pow(2, X-1)-1;
}