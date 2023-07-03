/*
 * Created By George on 7/3/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/899/problem/C
 * Problem Status:
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

    ll n, c = 0, grpSum = 0;
    cin >> n;

    veci grp;

    for(ll i = n ; i >= 1 ; i--){
        if(c == 0 || c == 3) {
            grp.push_back(i);
            grpSum += i;
        }
        c++;
        c %= 4;
    }

    cout << grpSum - (n * (n+1) / 2 - grpSum) << endl;
    cout << grp.size() << " ";
    for(ll x : grp)
        cout << x << " ";

    return 0;
}