//
// Created by George on 11/21/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/344/A
 * Problem status:      Accepted.
 */

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Ans = 1;
    string temp;
    vector<string> input;
    cin >> N;
    getline(cin, temp);
    while(N){
        N--;
        getline(cin, temp);
        input.push_back(temp);
        if(input.size() > 1) {
            if (input[input.size()-1] != input[input.size()-2]) {
                Ans++;
            }
        }
    }
    cout << Ans << endl;
    return 0;
}