//
// Created by George on 12/4/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/195/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <cmath>

using namespace std;
int main(){
    // -------- Separator --------
    int N, M, currentLeast = 0, tempAns, tempAns1, tempAns2, center;
    cin >> N >> M;
    int Baskets[M];
    // -------- Separator --------
    for(int i = 0 ; i < M ; i++) {
        Baskets[i] = 0;
    }
    // -------- Separator --------
    if(M % 2 == 1)
        center = (M+1) / 2;
    else
        center = M / 2;
    center--;
    if(M % 2 == 1) {
        tempAns1 = center;
        tempAns2 = center;
    } else {
        tempAns1 = center;
        tempAns2 = center+1;
    }
    for(int i = 0 ; i < N ; i++){
        while(Baskets[tempAns1] != currentLeast && Baskets[tempAns2] != currentLeast){
            tempAns1--;
            tempAns2++;
        }
        if(Baskets[tempAns1] == currentLeast)
            tempAns = tempAns1;
        else
            tempAns = tempAns2;
        Baskets[tempAns]++;
        if(tempAns == M-1) {
            currentLeast++;
            if(M % 2 == 1) {
                tempAns1 = center;
                tempAns2 = center;
            } else {
                tempAns1 = center;
                tempAns2 = center+1;
            }
        }
        cout << tempAns+1 << endl;
    }
    return 0;
}