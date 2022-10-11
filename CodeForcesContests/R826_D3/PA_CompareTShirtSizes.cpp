//
// Created by George on 10/11/2022.
//

/*
 * Problem Link:        https://codeforces.com/contest/1741/problem/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;

char whoIsBigger(string A, string B);

int main(){
    int T;
    string Line;
    string A;
    string B;
    cin >> T;
    getline(cin, Line);
    // ------------ Separator ------------
    while(T){
        T--;
        // ------------ Separator ------------
        getline(cin, Line);
        A = Line.substr(0, Line.find(' '));
        B = Line.substr(Line.find(' ')+1);
        // ------------ Separator ------------
        cout << whoIsBigger(A, B) << endl;
        // ------------ Separator ------------
    }
    // ------------ Separator ------------
    return 0;
}

char whoIsBigger(string A, string B){
    double c1 = 0;
    double c2 = 0;
    switch (A[A.size()-1]) {
        case 'L':
            c1 = 3;
            break;
        case 'M':
            c1 = 2;
        default:
            c1 = 1;
            break;
    }
    switch (B[B.size()-1]) {
        case 'L':
            c2 = 3;
            break;
        case 'M':
            c2 = 2;
        default:
            c2 = 1;
            break;
    }
    if(A[A.size()-1] == 'S'){
        c1 = c1 / A.size()-1;
    } else if(A[A.size()-1] == 'L'){
        c1 = c1 * A.size() - 1;
    }
    if(B[B.size()-1] == 'S'){
        c2 = c2 / B.size()-1;
    } else if(B[B.size()-1] == 'L'){
        c2 = c2 * B.size() - 1;
    }
    if(c1 > c2)
        return '>';
    else if(c2 > c1)
        return '<';
    else
        return '=';
}