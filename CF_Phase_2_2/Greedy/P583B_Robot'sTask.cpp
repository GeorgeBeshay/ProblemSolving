//
// Created by George on 2/6/2023.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/583/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
    int n, answer = 0, currentInfo = 0;
    bool goingRight = true;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    int i = 0;
    while(currentInfo < n){
        if(goingRight && i == n) {
            i = n-1;
            goingRight = false;
            answer++;
        } else if(!goingRight && i == -1){
            i = 0;
            goingRight = true;
            answer++;
        }
        if(v[i] <= currentInfo && v[i] != -1) {
            currentInfo++;
            v[i] = -1;
        }
        if(goingRight)
            i++;
        else
            i--;
    }
    cout << answer << endl;
    return 0;
}