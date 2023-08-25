/*
 * Created By George on 8/24/2023.
 */

/*
 * Problem Link:        https://codeforces.com/contest/1862/problem/C
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

    int t, n, currentIdx;
    bool good;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n], arr2[n];
        for(int i = 0 ; i < n ; i++)
            cin >> arr[i];
        if(arr[0] != n){
            cout << "NO" << endl;
            continue;
        }
        currentIdx = n - 1;
        memset(arr2, 0, sizeof(arr2));
        for(int i = 0 ; i < n ; i++) {
            if(i > 0 && arr[i] < arr[i-1]) {
                for(int k = 0 ; k < arr[i-1] - arr[i] ; k++) {
                    currentIdx--;
                    arr2[currentIdx] = arr2[currentIdx + 1];
                }
            }
            arr2[currentIdx]++;
        }
        while(currentIdx > 0){
            currentIdx--;
            arr2[currentIdx] = arr2[currentIdx + 1];
        }
        good = true;
        for(int i = 0 ; i < n ; i++)
            if(arr2[i] != arr[i]){
                good = false;
                break;
            }
        cout << ((good) ? "YES" : "NO") << endl;
    }

    return 0;
}