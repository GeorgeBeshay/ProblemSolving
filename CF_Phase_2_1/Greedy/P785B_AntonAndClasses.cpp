//
// Created by George on 12/2/2022.
//

/*
 * Problem Link:    https://codeforces.com/problemset/problem/785/B
 * Problem Status:  Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M, temp;
    cin >> N;
    vector<int> V1(N);
    vector<int> V3(N);
    for(int i = 0 ; i < N ; i++){
        cin >> V1[i] >> V3[i];
    }
    cin >> M;
    vector<int> V2(M);
    vector<int> V4(M);
    for(int i = 0 ; i < M ; i++){
        cin >> V2[i] >> V4[i];
    }
    sort(V1.begin(), V1.end());
    sort(V3.begin(), V3.end());
    sort(V2.begin(), V2.end());
    sort(V4.begin(), V4.end());
    if(V2[V2.size()-1] - V3[0] <= 0  && V1[V1.size() - 1] - V4[0] <= 0)
        cout << 0 << endl;
    else
        cout << max(V2[V2.size()-1] - V3[0], V1[V1.size() - 1] - V4[0]) << endl;
    return 0;
}