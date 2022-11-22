//
// Created by George on 11/22/2022.
//

/*
 * Problem Link:    https://codeforces.com/problemset/problem/703/A?f0a28=1
 * Problem Status:  Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int N, p1 = 0, p2 = 0, temp1, temp2;
    cin >> N;
    while(N){
        N--;
        cin >> temp1 >> temp2;
        if(temp1 > temp2)
            p1++;
        else if(temp2 > temp1)
            p2++;
    }
    if(p1 > p2)
        cout << "Mishka" << endl;
    else if(p2 > p1)
        cout << "Chris" << endl;
    else
        cout << "Friendship is magic!^^" << endl;

    return 0;
}