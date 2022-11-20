//
// Created by George on 11/20/2022.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/705/A
 * Problem Status:      Accepted.
 */

#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        if(i != 0)
            cout << "that ";
        if(i % 2 == 0)
            cout << "I hate ";
        else
            cout << "I love ";
    }
    cout << "it" << endl;
    return 0;
}