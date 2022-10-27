//
// Created by George on 10/28/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/281/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;

int main(){
    string input;
    getline(cin, input);
    char C;
    if(int(input[0]) >= 97) {
        cout << char(int(input[0])-32);
        input = input.erase(0, 1);
        cout << input << endl;
    } else
        cout << input << endl;
    return 0;
}