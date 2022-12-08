//
// Created by George on 12/8/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/467/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int N, temp1, temp2, ans = 0;
    cin >> N;
    while(N--){
        cin >> temp1 >> temp2;
        if(temp2-temp1 >= 2)
            ans++;
    }
    cout << ans;
    return 0;
}