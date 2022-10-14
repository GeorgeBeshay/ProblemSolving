//
// Created by George on 10/13/2022.
//

/*
 * Problem Link:        https://codeforces.com/contest/1742/problem/A
 * Problem Status:      Accepted.
 */

#include <iostream>

using namespace std;

int main(){
    int T, X, Y, Z;
    cin >> T;
    while(T){
        T--;
        // ---------- Separator ----------
        cin >> X >> Y >> Z;
        if(X + Y == Z || X + Z == Y || Y + Z == X)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        // ---------- Separator ----------
    }
    return 0;
}