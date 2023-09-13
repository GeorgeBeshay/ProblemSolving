/*
 * Created By George on 9/7/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/1872/problem/A
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

    int t, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        cout << ceil(ceil(abs(a - b) / 2.0)    / c) << endl;
    }

    return 0;
}