//
// Created by George on 11/7/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/78/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <string>

using namespace std;

string repeat(string S, int N);

int main(){
    int N;
    cin >> N;
    string Ans = repeat("ROYGBIV", N / 7);
    string temp = "GBIV";
    if(N % 7 > 0) {
        if(N % 7 > 4) {
            Ans += temp;
            Ans += temp.substr(0, (N % 7) - 4);
        } else
            Ans += temp.substr(0, N % 7);
    }
    cout << Ans << endl;


    return 0;
}

string repeat(string S, int N){
    string Ans = "";
    for(int i = 0 ; i < N ; i++)
        Ans += S;
    return Ans;
}