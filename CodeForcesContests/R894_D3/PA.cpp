/*
 * Created By George on 8/24/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/1862/problem/0
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

    int t, n, m, currentIdx, good;
    char lookingFor[] = {'v', 'i', 'k', 'a'};
    cin >> t;
    while(t--){
        cin >> n >> m;
        char arr[n][m];
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                cin >> arr[i][j];
        good = 0;
        currentIdx = 0;
        for(int j = 0 ; j < m ; j++)
            for(int i = 0 ; i < n ; i++)
                if(arr[i][j] == lookingFor[currentIdx]){
                    good++;
                    currentIdx++;
                    break;
                }
        cout << ((good == 4) ? "YES" : "NO") << endl;
    }

    return 0;
}