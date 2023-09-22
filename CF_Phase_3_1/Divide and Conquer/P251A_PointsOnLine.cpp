/*
 * Created By George on 9/22/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/251/problem/A
 * Problem Status:          Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

int binarySearch(veci& v, int elem){
    int l = 0, r = (int)v.size()-1, mid;
    if(v[v.size()-1] <= elem)
        return v.size()-1;
    if(v[0] > elem)
        return -1;
    while(l < r){
        mid = l + ((r-l) / 2);
        if(mid < v.size() && v[mid+1] > elem && v[mid] <= elem)
            return mid;
        if(v[mid] < elem)
            l = mid;
        else if(v[mid] > elem)
            r = mid;
    }
    return -2;
}

ll custom_fact(int x){
    ll ans = x;
    ans *= (x-1);
    ans *= (x-2);
    return ans;
}

int main() {
    int n, d, tmpIdx, lastIdx = -1;
    ll ans = 0;
    cin >> n >> d;
    veci v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];

    for(int i = 0 ; i < n ; i++){
        tmpIdx = binarySearch(v, v[i] + d);
        if((tmpIdx <= lastIdx) || tmpIdx - i + 1 < 3)
            continue;
        if(lastIdx - i + 1 >= 3)
            ans -= custom_fact(lastIdx - i + 1) / 6;
        ll tmpAns = custom_fact(tmpIdx - i + 1);
        tmpAns /= 6;
        ans += tmpAns;
        lastIdx = tmpIdx;
    }
    cout << ans << endl;
    return 0;
}