/*
 * Created By George on 6/29/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/116/problem/C
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int n, tempDepth, ans = 1;
    cin >> n;
    int manager[n];

    for(int i = 0 ; i < n ; i++) {
        cin >> manager[i];
        manager[i]--;
    }

    for(int i = 0 ; i < n ; i++){
        tempDepth = 1;
        int j = manager[i];
        while(j >= 0){
            j = manager[j];
            tempDepth++;
        }
        if(tempDepth > ans)
            ans = tempDepth;
    }

    cout << ans << endl;
    // ---------------- Separator ----------------    
    return 0;
}