//
// Created by George on 1/1/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/854/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, a = 1, b;
    int ans[2];
    cin >> n;
    if(n % 2 == 0)
        a = (n / 2) - 1;
    else
        a = n / 2;;
    b = n - a;

    ans[0] = a; ans[1] = b;
    while(a >= 1 && b <= n - 1){
        if(__gcd(a, b) == 1) {
            ans[0] = a;
            ans[1] = b;
            break;
        }
        a--;
        b++;
    }
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}