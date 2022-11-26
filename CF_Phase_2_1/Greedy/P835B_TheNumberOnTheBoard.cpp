//
// Created by George on 11/25/2022.
//

/*
 * Problem Link:            https://codeforces.com/problemset/problem/835/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int getSumOfDigits(string s);
vector<int> getFrequencyTable(string s);
int main(){
    int n;
    string input;
    cin >> n;
    getline(cin, input);
    getline(cin, input);
    if(getSumOfDigits(input) >= n)
        cout << 0 << endl;
    else {
        double diff = n - getSumOfDigits(input);
        int ans = 0;
        int temp = 0;
        vector<int> V = getFrequencyTable(input);
        while(diff > 0 && temp <= 9) {
            if (V[temp] != 0) {
                if (diff >= V[temp] * (9-temp)) {
                    ans += V[temp];
                    diff -= V[temp]*(9-temp);
                    V[temp] = 0;
                } else {
                    ans += min(int(ceil(diff / (9-temp))), V[temp]);
                    int temppo = diff;
                    diff -= min(int(ceil(diff / (9-temp))), V[temp])*(9-temp);
                    V[temp] -= min(int(ceil(temppo / (9-temp))), V[temp]);
                }
            }
            temp++;
        }
        temp = 0;
        while(diff > 0 && temp <= 9){
            if(V[temp] != 0 && temp <= diff){
                    ans += min(int(ceil(diff / temp)), V[temp]);
                    int temppo = diff;
                    diff -= (min(int(ceil(diff / temp)), V[temp])*9 - temp*min(int(ceil(diff / temp)), V[temp]));
                    V[temp] -= min(int(ceil(temppo / temp)), V[temp]);
                }
            temp++;
            }
        cout << ans << endl;
    }
    return 0;
}

int getSumOfDigits(string s){
    int ans = 0;
    string temp = "";
    for(char c : s) {
        temp = "";
        temp += c;
        ans += stoi(temp);
    }
    return ans;
}
vector<int> getFrequencyTable(string s){
    vector<int> V(10);
    string temp = "";
    for(char c : s) {
        temp = "";
        temp+=c;
        V[stoi(temp)]++;
    }
    return V;
}