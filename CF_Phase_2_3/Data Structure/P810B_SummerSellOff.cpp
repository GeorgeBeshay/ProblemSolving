/*
 * Created By George on 6/26/23.
 */

 /*
  * Problem Link:       https://codeforces.com/problemset/problem/810/B
  * Problem Status:     Accepted.
  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<ll>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    // ---------------- Separator ----------------
    ll n, f, ans = 0;
    cin >> n >> f;
    vector<pr> input(n);
    veci answers(n);
    vector<pr> temp(n);

    for(int i = 0 ; i < n ; i++) {
        cin >> input[i].first >> input[i].second;
        answers[i] = min(input[i].first, input[i].second);
        temp[i] = {min(2 * input[i].first, input[i].second) - answers[i], i};
    }
    sort(temp.begin(), temp.end());

    ll tempPtr = n-1;
    for(int i = 0 ; i < min(f, n) ; i++){
        answers[temp[tempPtr].second] = min(2 * input[temp[tempPtr].second].first, input[temp[tempPtr].second].second);
        tempPtr--;
    }

    for(ll k : answers)
        ans += k;

    cout << ans << endl;
    // ---------------- Separator ----------------    
    return 0;
}