//
// Created by George on 11/18/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/47/A
 * Problem Status:          Accepted.
 */

#include <iostream>
using namespace std;
int main(){
    int N, i = 1, temp;
    cin >> N;
    while(true){
        temp = (i*(i+1))/2;
        if(temp == N) {
            cout << "YES" << endl;
            break;
        } else if(temp > N){
            cout << "NO" << endl;
            break;
        }
        i++;
    }
    return 0;
}