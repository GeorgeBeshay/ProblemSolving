//
// Created by George on 10/15/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/355/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getAns(int C1, int C2, int C3, int C4, vector<int> B, vector<int> T);

int main(){
    // ----------- Separator -----------
    int C1, C2, C3, C4, N, M;
    cin >> C1 >> C2 >> C3 >> C4 >> N >> M;
    vector<int> B(N);
    vector<int> T(M);
    // ----------- Separator -----------
    for (int i = 0 ; i < N ; i++)
        cin >> B[i];
    for (int i = 0 ; i < M ; i++)
        cin >> T[i];
    // ----------- Separator -----------
    cout << getAns(C1, C2, C3, C4, B, T) << endl;
    // ----------- Separator -----------
    return 0;
}

int getAns(int C1, int C2, int C3, int C4, vector<int> B, vector<int> T){
    int Ans1 = 0;
    int Ans2 = 0;
    if(C4 >= 2 * C3)
        C4 = 2 * C3;
    for(auto I : B){
        if(I * C1 < C2){
            Ans1 += I * C1;
        } else {
            Ans1 += C2;
        }
        if(Ans1 >= C3){
            Ans1 = C3;
            if(Ans1 + Ans2 < C4)
                break;
            else
                return C4;
        }
        if(Ans2 + Ans1 >= C4){
            return C4;
        }
    }
    for(auto I : T){
        if(I * C1 < C2){
            Ans2 += I * C1;
        } else {
            Ans2 += C2;
        }
        if(Ans2 >= C3){
            Ans2 = C3;
            if(Ans1 + Ans2 < C4)
                break;
            else
                return C4;
        }
        if(Ans2 + Ans1 >= C4){
            return C4;
        }
    }
    return Ans1 + Ans2;
}