//
// Created by George on 12/5/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/361/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int N, K, C, O, currentSum = 0;
    cin >> N >> K;
    int ans[N][N];
    C = K;
    O = K;
    for(int i = 0 ; i < N ; i++){
        currentSum = 0;
        for(int u = 0 ; u < i ; u++){
            currentSum += ans[i][u];
        }
        O = K - currentSum;
        for(int j = i ; j < N ; j++){
            ans[i][j] = ceil(O / float(N-j));
            ans[j][i] = ans[i][j];
            O -= ans[i][j];
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}