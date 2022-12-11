//
// Created by George on 12/11/2022.
//

/*
 * Problem Link:        https://codeforces.com/contest/686/problem/A
 * Problem Status:      Accepted.
 */

#include <iostream>
using namespace std;

int main() {
    long long N, X, sadPeople = 0;
    string input;
    cin >> N >> X;
    getline(cin, input);
    while(N){
        getline(cin, input);
        if(input[0] == '+'){
            X += stoi(input.substr(2, input.size()));
        } else {
            if(X >= stoi(input.substr(2, input.size()))){
                X -= stoi(input.substr(2, input.size()));
            } else {
                sadPeople++;
            }
        }
        N--;
    }
    cout << X << " " << sadPeople << endl;
    return 0;
}