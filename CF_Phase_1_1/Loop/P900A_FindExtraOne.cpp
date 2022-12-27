//
// Created by George on 12/27/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/900/A
 * Problem Status:
 */

#include <iostream>
using namespace std;
int main(){
    int n, l = 0, r = 0, temp;
    cin >> n;
    while(n--){
        cin >> temp;
        if(temp < 0)
            l++;
        else
            r++;
        cin >> temp;
    }
    if(l <= 1 || r <= 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}