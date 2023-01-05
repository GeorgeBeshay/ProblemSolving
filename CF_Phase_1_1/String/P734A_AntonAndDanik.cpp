//
// Created by George on 1/5/2023.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/734/A
 * Problem Status:          Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int n, a = 0, d = 0;
    string s;
    cin >> n;
    cin >> s;
    for(char c : s){
        if(c == 'A')
            a++;
        else
            d++;
    }
    if(a > d)
        cout << "Anton" << endl;
    else if(d > a)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
    return 0;
}

