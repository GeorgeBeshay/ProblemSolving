/*
 * Created By George on 8/24/2023.
 */

/*
 * Problem Link:        https://codeforces.com/contest/1862/problem/D
 * Problem Status:      Accepted.
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

    int t;
    ll n, sol;
    cin >> t;
    while(t--){
        cin >> n;
        sol = floor((1 + sqrt(1 - 4 * -2 * n)) / 2);
        if((sol * (sol - 1)) / 2 < n)
            sol += n - ((sol * (sol - 1)) / 2);
        cout << sol << endl;
    }
    return 0;
}