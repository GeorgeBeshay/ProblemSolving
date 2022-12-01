//
// Created by George on 12/1/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/12/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    string input;
    string output;
    vector<char> V;
    string temp = "";
    int zerosCount = 0;
    getline(cin, input);
    getline(cin, output);
    for(char x : input){
        if(x == '0')
            zerosCount++;
        else
            V.push_back(x);
    }
    sort(V.begin(), V.end());
    for(int i = 0 ; i < V.size() ; i++){
        if(i == 1){
            while(zerosCount > 0){
                temp += "0";
                zerosCount--;
            }
            temp += V[i];
        } else {
          temp += V[i];
        }
    }
    while(zerosCount > 0){
        temp += "0";
        zerosCount--;
    }
    if(temp == output)
        cout << "OK" << endl;
    else
        cout << "WRONG_ANSWER" << endl;
    return 0;
}