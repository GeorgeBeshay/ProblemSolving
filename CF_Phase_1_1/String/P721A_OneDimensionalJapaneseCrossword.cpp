//
// Created by George on 1/4/2023.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/721/A
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    vector<int> answers;
    string S;
    bool flag = false;
    cin >> N;
    cin >> S;
    for(char c : S){
        if(c == 'B'){
            if(!flag)
                answers.push_back(1);
            else
                answers[answers.size()-1]++;
            flag = true;
        }else if(c == 'W'){
            flag = false;
        }
    }
    cout << answers.size() << endl;
    for(int num : answers)
        cout << num << " ";
    return 0;
}