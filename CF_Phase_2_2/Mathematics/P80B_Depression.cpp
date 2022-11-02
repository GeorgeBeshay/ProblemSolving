//
// Created by George on 11/2/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/80/B
 * Problem Status:      Accepted.
 */

#include<iostream>
using namespace std;

int main(){
    string input;
    getline(cin, input);
    int HR, M;
    double HA, MA;
    HR = stoi(input.substr(0, 2));
    M = stoi(input.substr(3, 2));
    HA = ( (HR * 30) % 360 ) + M/2.0;
    MA = ( M * 6);
    cout << HA << " " << MA << endl;
    return 0;
}