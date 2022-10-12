//
// Created by George on 10/12/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/912/A
 * Problem Status:      Accepted.
 */

#include <iostream>

using namespace std;

int main(){
    // ---------- Separator ----------
    long long X, Y, Z, Y_Crys_Got, B_Crys_Got, Y_Crys_Needed, B_Crys_Needed, Needed;
    Needed = 0;
    Y_Crys_Needed = 0;
    B_Crys_Needed = 0;
    // ---------- Separator ----------
    cin >> Y_Crys_Got >> B_Crys_Got;
    cin >> X >> Y >> Z;
    // ---------- Separator ----------
    Y_Crys_Needed += 2 * X;
    Y_Crys_Needed += 1 * Y;
    B_Crys_Needed += 1 * Y;
    B_Crys_Needed += 3 * Z;
    Y_Crys_Needed -= Y_Crys_Got;
    B_Crys_Needed -= B_Crys_Got;
    // ---------- Separator ----------
    if(Y_Crys_Needed < 0 || B_Crys_Needed < 0){
        if(Y_Crys_Needed < 0){
            if(B_Crys_Needed >= 0) {
                cout << B_Crys_Needed << endl;
                exit(0);
            } else {
                cout << 0 << endl;
                exit(0);
            }
        } else {
            cout << Y_Crys_Needed << endl;
        }
    } else {
        cout << Y_Crys_Needed + B_Crys_Needed << endl;
    }
    // ---------- Separator ----------
    return 0;
}