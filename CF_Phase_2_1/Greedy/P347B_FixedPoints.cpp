//
// Created by George on 10/14/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/347/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solveTheProb(vector<int> *V);

int main(){
    // ------------- Separator -------------
    int N;
    // ------------- Separator -------------
    cin >> N;
    vector<int> V(N);
    for(int i = 0 ; i < N ; i++)
        cin >> V[i];
    // ------------- Separator -------------
    cout << solveTheProb(&V) << endl;
    // ------------- Separator -------------
    return 0;
}

int solveTheProb(vector<int> *V){
    int Ans = 0;
    int MaxSwapVal = 0;
    for(int i = 0 ; i < (*V).size() ; i++){
        int val = (*V)[i];
        if(i == val)
            Ans++;
        else {
            if((*V)[val] == i) {
                MaxSwapVal = 2;
            }
            else {
                if(MaxSwapVal == 0)
                    MaxSwapVal = 1;
            }
        }
    }
    return Ans + MaxSwapVal;
}