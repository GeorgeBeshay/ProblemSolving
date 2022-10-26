//
// Created by George on 10/26/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/705/B
 * Problem Status:          Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int A[N];
    bool currentWinner = 1; // Player 2
    for(int i =  0 ; i < N ; i++){
        cin >> A[i];
        if(A[i] > 1){
            if( (A[i]-2) % 2 == 0)
                currentWinner = !currentWinner;
        }
        if(currentWinner)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}