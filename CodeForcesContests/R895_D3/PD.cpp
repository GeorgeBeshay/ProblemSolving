/*
 * Created By George on 9/7/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/1872/problem/D
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

int main() {

    ll t, n, x, y, div_x, div_y, c, ans, temp;
    map<ll, ll> cache;
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        div_x = n / x;
        div_y = n / y;
        temp = lcm(x, y);
        div_x = max(0, int(div_x - floor(n / temp)));
        div_y = max(0, int(div_y - floor(n / temp)));
        ans = ((n * (n+1)) / 2) - (((n - div_x) * ((n - div_x) + 1)) / 2);
        ans -= (div_y * (div_y + 1)) / 2;
        cout << ans << endl;
    }
    return 0;
}