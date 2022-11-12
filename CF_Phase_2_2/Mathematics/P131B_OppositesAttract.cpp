//
// Created by George on 11/12/2022.
//

/*
 * Problem Link:    https://codeforces.com/problemset/problem/131/B
 * Problem Status:  Accepted.
 */

#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

long long fact(int X, int untill);
double combination(int  N, int R);

int main(){
    map<int, int> M;
    long long Ans = 0, temp, N;
    cin >> N;
    while(N){
        cin >> temp;
        M[temp]++;
        N--;
    }
    for(auto X : M){
        if(X.second == 0)
            continue;
        if(X.first != 0)
            Ans += (long long)(X.second) * (long long)(M[-1*X.first]);
        else
            Ans += (long long)(combination(X.second, 2));
        M[X.first] = 0;
        M[-X.first] = 0;
    }
    cout << setprecision(30) << Ans << endl;
    return 0;
}

long long fact(int X, int untill){
    long long Ans = 1;
    for(int i = X ; i >= untill ; i--)
        Ans = Ans * i;
    return Ans;
}

double combination(int  N, int R){
        return fact(N, N-R+1) / fact(R, 2);
}