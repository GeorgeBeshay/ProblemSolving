/*
 * Created By George on 9/7/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/1872/problem/C
 * Problem Status:          Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> veci;
typedef vector<vector<ll>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int> getDivisors(int x){
    vector<int> v;
    for(int i = 2 ; i <= sqrt(x) ; i++)
        if(x % i == 0)
            v.push_back(i);
    return v;
}

int main() {

    int t, l, r, a, b;
    cin >> t;
    while(t--){
        a = -1; b = -1;
        cin >> l >> r;
        for(int i = l ; i <= r ; i++){
            vector<int> v = getDivisors(i);
            for(int tmp : v){
                if(__gcd(tmp, i - tmp) != 1){
                    a = tmp;
                    b = i - tmp;
                    break;
                }
            }
            if(a != -1)
                break;
        }
        if(a == -1)
            cout << -1 << endl;
        else
            cout << a << " " << b << endl;
    }

    return 0;
}