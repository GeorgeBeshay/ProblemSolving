/*
 * Problem Link:        https://codeforces.com/problemset/problem/454/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int N, center;
    string tempString = "";
    cin >> N;
    center = floor(N / 2);
    string Ans[N];
    // ----------- Separator -----------
    for(int i = 0 ; i <= floor(N / 2) ; i++, tempString += '*'){
        Ans[center + i] = tempString + string(N - (i * 2), 'D') + tempString;
        Ans[center - i] = tempString + string(N - (i * 2), 'D') + tempString;
    }
    // ----------- Separator -----------
    for(int i = 0 ; i < N ; i++)
        cout << Ans[i] << endl;
    return 0;
}