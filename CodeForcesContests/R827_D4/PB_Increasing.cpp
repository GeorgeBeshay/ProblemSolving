//
// Created by George on 10/13/2022.
//

/*
 * Problem Link:        https://codeforces.com/contest/1742/problem/B
 * Problem Status:
 */

#include <iostream>
#include <set>

using namespace std;

int main(){
    int T, tempLen, temp;
    set<int> X;
    cin >> T;
    while(T){
        T--;
        cin >> tempLen;
        for(int i = 0 ; i < tempLen ; i++){
            cin >> temp;
            X.insert(temp);
        }
        if(X.size() == tempLen)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        X.clear();
    }
    return 0;
}