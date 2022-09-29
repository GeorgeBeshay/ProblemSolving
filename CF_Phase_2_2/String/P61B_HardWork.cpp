//
// Created by George on 9/29/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/61/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>

using namespace std;

void showVec(vector <string> V);
string remove_extra(string S);
string convert_to_small(string S);

int main(){
    vector <string> A(3);
    int N;
    string temp;
    // ----------------- Separator -----------------
    for(int i = 0 ; i < 3 ; i++) {
        getline(cin, temp);
        A[i] = convert_to_small(remove_extra(temp));
    }
    // ----------------- Separator -----------------
    cin >> N;
    getline(cin, temp);
    vector <string> Answers(N);
    // ----------------- Separator -----------------
    for(int i = 0 ; i < N ; i++) {
        getline(cin, temp);
        Answers[i] = convert_to_small(remove_extra(temp));
    }
    // ----------------- Separator -----------------
    vector<string> Z;
    for(int i = 0 ; i < 3 ; i++){
        for(int u = 0 ; u < 3 ; u++) {
            if(i == u){
                continue;
            } else {
                for (int j = 0; j < 3; j++) {
                    if (i == j || u == j)
                        continue;
                    else {
                        Z.push_back(A[i] + A[u] +  A[j]);
                    }
                }
            }
        }
    }
    for(int i = 0 ; i < N ; i++){
        if(Answers[i].size() != (A[0].size() + A[1].size() + A[2].size())){
            cout << "WA" << endl;
        } else {
            bool flag = false;
            for(int j = 0 ; j < 6 ; j++){
                if(Answers[i] == Z[j]){
                    cout << "ACC" << endl;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout << "WA" << endl;
            }
        }
    }
    // ----------------- Separator -----------------
    return 0;
}

string convert_to_small(string S){
    for(int i = 0 ; i < S.size() ; i++){
        if(int(S[i]) >= 65 && int(S[i] <= 90)){
            S[i] = char(int(S[i]) + 32);
        } else {
            continue;
        }
    }
    return S;
}

string remove_extra(string S){
    for(int i = 0 ; i < S.size() ; i++){
        if(S[i] == '_' || S[i] == ';' || S[i] == '-'){
            S.erase(i, 1);
            i--;
        } else {
            continue;
        }
    }
    return S;
}

void showVec(vector <string> V){
    for(auto X : V)
        cout << X << endl;
}