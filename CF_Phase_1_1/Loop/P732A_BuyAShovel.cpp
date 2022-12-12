//
// Created by George on 12/12/2022.
//

/*
 * Problem Link:    https://codeforces.com/problemset/problem/732/A?f0a28=1
 * Problem Status:  Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int K, R, Count = 1;
    cin >> K >> R;
    while(Count <= 10000000){
        if(((K * Count) - R) % 10 == 0 || (K * Count) % 10 == 0)
            break;
        else
            Count++;
    }
    cout << Count << endl;
    return 0;
}