/*
 * Created By George on 4/10/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/621/B
 * Problem Status:
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

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    ll c, x, y, ans = 0;
    map<ll, ll> myMap, myMap_sec;
    // ---------------- Separator ----------------
    cin >> c;
    while(c--){
        cin >> x >> y;
        myMap[x + y]++;
        myMap_sec[x - y]++;
    }
    // ---------------- Separator ----------------
    for(auto I : myMap){
        if(I.second > 1)
            ans += (I.second * (I.second - 1) / 2);
    }
    for(auto I : myMap_sec){
        if(I.second > 1)
            ans += (I.second * (I.second - 1) / 2);
    }
    // ---------------- Separator ----------------
    cout << ans << endl;
    // ---------------- Separator ----------------
    return 0;
}