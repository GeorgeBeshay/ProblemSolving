//
// Created by George on 11/23/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/231/A?f0a28=1
 * Problem Status:      Accepted.
 */

#include <iostream>

using namespace std;

int main(){
    int N, tempSum = 0, tempNumContainer, Answer = 0;
    cin >> N;
    while(N){
        N--;
        for(int i = 0 ; i < 3 ; i++) {
            cin >> tempNumContainer;
            tempSum += tempNumContainer;
        }
        if(tempSum >= 2)
            Answer++;
        tempSum = 0;
    }
    cout << Answer << endl;
    return 0;
}