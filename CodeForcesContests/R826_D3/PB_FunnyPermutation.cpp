//
// Created by George on 10/11/2022.
//

/*
 * Problem Link:        https://codeforces.com/contest/1741/problem/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
using namespace std;

void showVec(vector<int> V);
void theAmazingFunction(int X);

int main(){
    // --------------- Separator ---------------
    int T;
    int X;
    cin >> T;
    while(T){
        T--;
        // --------------- Separator ---------------
        cin >> X;
        // --------------- Separator ---------------
        theAmazingFunction(X);
        // --------------- Separator ---------------
    }
    // --------------- Separator ---------------
    return 0;
}

void theAmazingFunction(int X){
    if(X == 3){
        cout << -1 << endl;
        return;
    }
    vector<int> Ans(X);
    for(int i = 0 ; i < X ; i++)
        Ans[i] = i+1;
    if(X % 2 == 0){
        for(int i = 0 ; i < X ; i+= 2)
            swap(Ans[i], Ans[i+1]);
        showVec(Ans);
    } else {
        for(int i = 0 ; i < X - 3 ; i+= 2)
            swap(Ans[i], Ans[i+1]);
        vector<int> Ans2(X);
        Ans2[0] = X - 2 ;
        Ans2[1] = X - 1;
        Ans2[2] = X - 0;
        for(int i = 3 ; i < X ; i++)
            Ans2[i] = Ans[i-3];
        showVec(Ans2);
    }
}

void showVec(vector<int> V){
    for(auto I : V)
        cout << I << " ";
    cout << endl;
}