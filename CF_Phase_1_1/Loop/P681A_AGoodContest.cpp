//
// Created by George on 12/10/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/681/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(){
    int N;
    string Answer = "NO", lineInput;
    string pString[3];
    cin >> N;
    getline(cin, lineInput);
    while(N){
        N--;
        int i = 0;
        for(; i < 3 ; i++){
            pString[i] = "";
        }
        i = 0;
        getline(cin, lineInput);
        for (char X : lineInput){
            if(X == ' '){
                i++;
            } else {
                pString[i] += X;
            }
        }
        string temp1 = pString[1];
        string temp2 = pString[2];
        if(stoi(temp2) > stoi(temp1) && stoi(temp1) >= 2400){
            Answer = "YES";
        }
    }
    cout << Answer << endl;
    return 0;
}