//
// Created by George on 12/16/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/248/A
 * Problem Status:          Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int N, tempAns1 = 0, tempAns2 = 0, tempAns3 = 0, tempAns4 = 0, X, Y;
    cin >> N;
    while(N--){
        cin >> X >> Y;
        if(X != 0)
            tempAns3++;
        if(Y != 0)
            tempAns3++;
        if(X != 0)
            tempAns1++;
        if(Y != 1)
            tempAns1++;
        if(X != 1)
            tempAns2++;
        if(Y != 0)
            tempAns2++;
        if(X != 1)
            tempAns4++;
        if(Y != 1)
            tempAns4++;

    }
    cout << min(min(tempAns3, tempAns4), min(tempAns1, tempAns2)) << endl;
    return 0;
}