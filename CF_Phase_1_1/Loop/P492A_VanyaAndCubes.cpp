//
// Created by George on 12/19/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/492/A
 * Problem Status:          Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int n, ans = 0, i = 1;
    cin >> n;
    while( (i*(i+1))/2 <= n ){
        n-= (i*(i+1)/2);
        ans++;
        i++;
    }
    cout << ans << endl;
    return 0;
}