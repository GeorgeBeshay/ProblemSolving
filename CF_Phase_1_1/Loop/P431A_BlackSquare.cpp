//
// Created by George on 12/17/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/431/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int nums[4];
    int ans = 0;
    string s;
    char tempS[1];
    cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
    getline(cin , s);
    getline(cin , s);
    for(char X : s){
        tempS[0] = X;
        ans += nums[stoi(tempS)-1];
    }
    cout << ans << endl;
    return 0;
}