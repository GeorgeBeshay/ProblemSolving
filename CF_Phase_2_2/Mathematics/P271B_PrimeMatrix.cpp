//
// Created by George on 2/3/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/271/B
 * Problem Status:
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
bool isPrime(int x);
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);       // row wise
    vector<vector<int>> z(m);   // col wise
    vector<int> answers;
    map<int, int> cache;
    cache.insert(make_pair(1, 1));
    for(int i = 0 ; i < n ; i++){
        v[i] = vector<int>(m);
        for(int j = 0 ; j < m ; j++) {
            cin >> v[i][j];
        }
    }
    for(int j = 0 ; j < m ; j++){
        z[j] = vector<int>(n);
        for(int i = 0 ; i < n ; i++){
            z[j][i] = v[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++){
        int tempC = 0;
        for(int j = 0 ; j < m ; j++){
            int x = v[i][j];
            auto  I = cache.find(x);
            if(I->first == x){
                tempC += I->second;
                continue;
            }
            while(!isPrime(x)) {
                x++;
                tempC++;
            }
            cache.insert(make_pair(v[i][j], x - v[i][j]));
        }
        answers.push_back(tempC);
    }
    for(int j = 0 ; j < m ; j++){
        int tempC = 0;
        for(int i = 0 ; i < n ; i++){
            int x = z[j][i];
            auto  I = cache.find(x);
            if(I->first == x){
                tempC += I->second;
                continue;
            }
            while(!isPrime(x)) {
                x++;
                tempC++;
            }
            cache.insert(make_pair(z[j][i], x - z[j][i]));
        }
        answers.push_back(tempC);
    }
    sort(answers.begin(), answers.end());
    cout << answers[0] << endl;
    return 0;
}

bool isPrime(int x){
    if(x == 1)
        return false;
    for(int i = 2 ; i <= sqrt(x) ; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}