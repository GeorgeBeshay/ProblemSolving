//
// Created by George on 12/30/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/796/A
 * Problem Status:
 */

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m, k, tempAns = 0, tempAns2 = 0;
    cin >> n >> m >> k;
    m--;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    for(int i = m+1 ; i < n ; i++){
        if(v[i] <= k && v[i] > 0) {
            tempAns += 10;
            break;
        } else {
            tempAns += 10;
            if(i == n-1)
                tempAns = 0;
        }
    }
    for(int i = m-1 ; i >= 0 ; i--){
        if(v[i] <= k && v[i] > 0) {
            tempAns2 += 10;
            break;
        } else {
            tempAns2 += 10;
            if(i == 0)
                tempAns2 = 0;
        }
    }
    if(tempAns > 0 && tempAns2 > 0)
        cout << min(tempAns, tempAns2) << endl;
    else
        cout << max(tempAns, tempAns2) << endl;
    return 0;
}