/*
 * Created By George on 4/28/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/579/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int n, tempStrength;
    cin >> n;
    n *= 2;
    // ---------------- Separator ----------------
    veci paired(n, -1);
    map<int, pr> strengthsToPairs;
    for(int i = 1 ; i < n ; i++) {
        for (int j = 0; j < i; j++) {
            cin >> tempStrength;
            strengthsToPairs[tempStrength] = make_pair(i, j);
        }
    }
    // ---------------- Separator ----------------
    for(auto I  = strengthsToPairs.rbegin() ; I != strengthsToPairs.rend() ; I++){
        if(paired[I->second.first] == -1 && paired[I->second.second] == -1){
            paired[I->second.first] = I->second.second;
            paired[I->second.second] = I->second.first;
        }
    }
    // ---------------- Separator ----------------
    for(int i = 0 ; i < n ; i++)
        cout << paired[i]+1 << " ";
    // ---------------- Separator ----------------
    return 0;
}