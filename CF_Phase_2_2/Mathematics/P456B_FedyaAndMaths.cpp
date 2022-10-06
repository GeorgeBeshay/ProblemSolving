//
// Created by George on 10/6/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/456/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    // ---------- Separator ----------
    string bigNum;
    int temp;
    getline(cin , bigNum);
    // ---------- Separator ----------
    if(bigNum.size() == 1)
        temp = stoi(bigNum);
    else
        temp = stoi(bigNum.substr(bigNum.size()-2, 2));
    // ---------- Separator ----------
    if(temp % 4 == 0)
        cout << 4 << endl;
    else
        cout << 0 << endl;
    // ---------- Separator ----------
    return 0;
}