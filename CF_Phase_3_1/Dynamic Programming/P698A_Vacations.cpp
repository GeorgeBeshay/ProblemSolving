/*
 * Created By George on 8/20/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/698/problem/A
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

    int n, i = 0;
    cin >> n;
    int arr[n];
    int oldDp[3], currentDp[3];
    memset(oldDp, 0, sizeof(oldDp));

    for(; i < n ; i++) {
        cin >> arr[i];
        currentDp[0] = min(min(oldDp[0], oldDp[1]), oldDp[2]) + 1;
        if(arr[i] == 3 || arr[i] == 1)
            currentDp[1] = min(oldDp[0], oldDp[2]);
        else
            currentDp[1] = oldDp[1] + 1;
        if(arr[i] == 3 || arr[i] == 2)
            currentDp[2] = min(oldDp[0], oldDp[1]);
        else
            currentDp[2] = oldDp[2] + 1;
        copy(currentDp, currentDp + 3, oldDp);
    }
    cout << min(currentDp[0], min(currentDp[1], currentDp[2])) << endl;
    return 0;
}