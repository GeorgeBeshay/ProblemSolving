//
// Created by George on 1/3/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/711/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int n;
    bool flag = false;
    cin >> n;
    string bus[n];
    for(int i = 0 ; i < n ; i++){
        cin >> bus[i];
    }
    for(int i = 0 ; i < n ; i++){
        if(bus[i][0] == 'O' && bus[i][1] == 'O'){
            bus[i][0] = '+'; bus[i][1] = '+';
            flag = true;
            break;
        } else if(bus[i][3] == 'O' && bus[i][4] == 'O'){
            bus[i][3] = '+'; bus[i][4] = '+';
            flag = true;
            break;
        }
    }
    if(flag) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << bus[i] << endl;
    } else
        cout << "NO" << endl;
    return 0;
}