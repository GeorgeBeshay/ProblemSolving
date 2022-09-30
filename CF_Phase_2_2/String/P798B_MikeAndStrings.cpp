//
// Created by George on 10/1/2022.
//

/*
 * Problem Link:            https://codeforces.com/contest/798/problem/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void showVec(vector <string> V);
string sortString(string S);
int count_steps(string F, string T);
void showVec_(vector <int> V);

int main (){
    // ------------ Separator ------------
    int N;
    string O = "";
    // ------------ Separator ------------
    cin >> N;
    vector <string> V (N);
    vector <int> Answers (N);
    getline(cin, V[0]);
    // ------------ Separator ------------
    for(int i = 0 ; i < N ; i++) {
        Answers[i] = 0;
        getline(cin, V[i]);
        if(i == 0) {
            O = sortString(V[0]);
        } else {
            if(sortString(V[i]) != O){
                cout << -1 << endl;
                exit(0);
            } else {
                continue;
            }
        }
    }
    // ------------ Separator ------------
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(j == i)
                continue;
            int temp = count_steps(V[j], V[i]);
            if(temp == -1){
                cout << -1 << endl;
                exit(0);
            }
            Answers[i] += temp;
        }
    }
    // ------------ Separator ------------
    sort(Answers.begin(), Answers.end());
    cout << Answers[0] << endl;
    // ------------ Separator ------------
    return 0;
}

int count_steps(string F, string T){
    if(F == T)
        return 0;
    // ------------ Separator ------------
    int Ans = 0;
    // ------------ Separator ------------
    for(int i = 0 ; i < F.size() ; i++){
        char C = F[0];
        F.erase(0, 1);
        F += C;
        Ans++;
        if(F == T)
            break;
    }
    if(F != T)
        return -1;
    // ------------ Separator ------------
    return Ans;
}

void showVec(vector <string> V){
    for(auto X : V){
        cout << X << " ";
    }
    cout << endl;
}

void showVec_(vector <int> V){
    for(auto X : V){
        cout << X << " ";
    }
    cout << endl;
}

string sortString(string S){
    sort(S.begin(), S.end());
    return S;
}