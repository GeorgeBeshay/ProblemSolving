//
// Created by George on 12/26/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/919/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double n, m, a, b, ans = 0;
    cin >> n >> m;
    while(int(n--)){
        cin >> a >> b;
        if(a / b < ans || ans == 0)
            ans = a / b;
    }
    cout << setprecision(20) << ans*m << endl;
    return 0;
}