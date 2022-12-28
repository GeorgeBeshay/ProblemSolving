//
// Created by George on 12/26/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/761/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int mod(int a, int b);
int getVecSum(vector<int> V);

int main(){
    int n, l;
    cin >> n >> l;
    vector <int> v1(n), v2(n);
    map<int, int> M;
    for(int i = 0 ; i < n ; i++){cin >> v1[i];}
    for(int i = 0 ; i < n ; i++){cin >> v2[i];}
    for(int i = 1 ; i < n ; i++){v1[i] -= v1[0];v2[i] -= v2[0];}
    v1[0] = 0;v2[0] = 0;
    vector<int> tempV1(v1), tempV2(v2);
    for(int i = 1 ; i < n ; i++){v1[i] -= tempV1[i-1];v2[i] -= tempV2[i-1];}
    if(v1 == v2){
        cout << "YES" << endl;
        exit(0);
    }
    for(int i = 0 ; i < n ; i++){
        vector<int> tempV(v2);
        v2[1] = mod(0 - getVecSum(v2), l);
        for(int j = 2 ; j < n ; j++)
            v2[j] = tempV[j-1];

        if(v1 == v2){
            cout << "YES" << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;
    return 0;
}

int getVecSum(vector<int> V){
    int ans = 0;
    for(auto I : V)
        ans += I;
    return ans;
}

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}