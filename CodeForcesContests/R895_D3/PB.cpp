/*
 * Created By George on 9/7/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/1872/problem/B
 * Problem Status:          Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> veci;
typedef vector<vector<ll>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INTEGER numeric_limits<int>::max();

int main() {
    int t, n, ans;
    cin >> t;
    while(t--){
        cin >> n;
        ans = MAX_INTEGER;
        vector<pair<int, int>> traps(n);
        for(int i = 0 ; i < n ; i++)
            cin >> traps[i].first >> traps[i].second;
        for(int i = n-1 ; i >= 0 ; i--)
            ans = min(ans, int(traps[i].first + floor((traps[i].second - 1) / 2)));
        cout << ans << endl;
    }


    return 0;
}