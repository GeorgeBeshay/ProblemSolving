/*
 * Created By George on 8/7/2023.
 */

/*
 * Problem Link:        https://codeforces.com/contest/1857/problem/A
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <ll> veci;
typedef vector <vector<ll>> vveci;
typedef pair <ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool solve(vector<int>& v){
    int oddCount = 0, evenCount = 0;
    for(int x : v) {
        if (x % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }
    return oddCount % 2 == 0;
}

int main() {
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++)
            cin >> v[i];
        if(solve(v))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}