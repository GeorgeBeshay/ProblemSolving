//
// Created by George on 10/23/2022.
//

/*
 * Problem Link:            https://codeforces.com/contest/365/problem/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // --------------- Separator ---------------
    int N;
    cin >> N;
    vector<int> V(N);
    for(int i = 0 ; i < N ; i++)
        cin >> V[i];
    // --------------- Separator ---------------
    if(V.size() == 2 || V.size() == 1){
        cout << V.size() << endl;
        exit(0);
    }
    // --------------- Separator ---------------
    int temp = 2;
    vector<int> Answers;
    // --------------- Separator ---------------
    for(int i = 2 ; i < N ; i++){
        if(V[i] == V[i-1] + V[i-2])
            temp++;
        else {
            Answers.push_back(temp);
            temp = 2;
        }
    }
    Answers.push_back(temp);
    sort(Answers.begin(), Answers.end());
    cout << Answers[Answers.size()-1] << endl;
    // --------------- Separator ---------------
    return 0;
}