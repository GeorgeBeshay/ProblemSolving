/*
 * Created By George on 8/24/2023.
 */

/*
 * Problem Link:        https://codeforces.com/contest/1862/problem/B
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
    int t, n, size;
    cin >> t;
    while(t--){
        cin >> n;
        ll arr[n];
        for(int i = 0 ; i < n ; i++)
            cin >> arr[i];          // 0 0      1 2         2 4
        ll newArr[2 * n - 1];
        for(int i = 0 ; i < n ; i++)
            newArr[2 * i] = arr[i];
        for(int i = 1 ; i < 2 * n - 1 ; i += 2){
            if(newArr[i+1] >= newArr[i-1])
                newArr[i] = -1;
            else
                newArr[i] = 1;
        }
        size = 0;
        for(int i = 0 ; i < 2 * n - 1 ; i++)
            if(newArr[i] != -1)
                size++;
        cout << size << endl;
        for(int i = 0 ; i < 2 * n - 1 ; i++)
            if(newArr[i] != -1)
                cout << newArr[i] << " ";
        cout << endl;
    }

    return 0;
}