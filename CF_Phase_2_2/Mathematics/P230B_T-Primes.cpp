//
// Created by George on 12/20/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/230/B
 * Problem status:          Accepted.
 */

#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(double N);
int main(){
    int n;
    long long temp;
    cin >> n;
    while(n){
        n--;
        cin >> temp;
        if(isPrime(sqrt(temp)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

bool isPrime(double N){
    if((int(N) % 2 == 0 && int(N) != 2) || int(N) != N || int(N) == 1)
        return false;
    for(int i = 2 ; i <= sqrt(N) ; i++){
        if(int(N) % i == 0) {
            return false;
        }
    }
    return true;
}