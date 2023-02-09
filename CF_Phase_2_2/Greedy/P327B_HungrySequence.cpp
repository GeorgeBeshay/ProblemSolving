//
// Created by George on 2/9/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/327/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
using namespace std;
vector<int> getPrimesUpTo(int x);
void anotherSolution(int x);
int main(){
    int n;
    cin >> n;
    anotherSolution(n);
    return 0;
}

void anotherSolution(int x){
    int st = 2 * x;
    while(x--)
        cout << st++ << endl;
}