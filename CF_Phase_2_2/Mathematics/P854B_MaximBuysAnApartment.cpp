//
// Created by George on 11/1/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/854/B
 * Problem Status:          Accepted.
 */

#include <iostream>
using namespace std;

int getMaxAns(int N, int K);
int getMinAns(int N, int K);

int main(){
    int N, K;
    cin >> N >> K;
    cout << getMinAns(N, K) << " " << getMaxAns(N, K) << endl;
    return 0;
}

int getMinAns(int N, int K){
    if(N == K || K == 0)
        return 0;
    return 1;
}

int getMaxAns(int N, int K){
    if(K == 0)
        return 0;
    int Answer = N - K;
    if(Answer >= 2*K)
        Answer = 2*K;
    return Answer;
}