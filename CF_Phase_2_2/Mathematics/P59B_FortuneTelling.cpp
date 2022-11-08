//
// Created by George on 11/8/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/59/B
 * Problem Status:          Accepted.
 */

#include <iostream>

using namespace std;

int main(){
    int N, temp, leastOdd = -1, Sum = 0;
    cin >> N;
    for(int i = 0 ; i < N ; i++) {
        cin >> temp;
        Sum += temp;
        if(temp % 2 == 1 &&(leastOdd == -1 || temp < leastOdd))
            leastOdd = temp;
    }
    if(Sum % 2 == 1)
        cout <<  Sum << endl;
    else if(leastOdd != -1)
        cout <<  Sum - leastOdd<< endl;
    else
        cout << 0 << endl;
    return 0;
}