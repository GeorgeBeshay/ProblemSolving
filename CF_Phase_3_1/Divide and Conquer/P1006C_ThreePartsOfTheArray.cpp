/*
 * Created By George on 8/25/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/1006/problem/C
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
    ll n, left, right, lastFound = 0;
    cin >> n;
    ll arr[n], arr1[n], arr2[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    arr1[0] = arr[0];
    arr2[n-1] = arr[n-1];
    for(int i = 1 ; i < n ; i++) {
        arr1[i] = arr[i] + arr1[i - 1];
        arr2[n-i-1] = arr[n-i-1] + arr2[n-i];
    }
    left = 0;
    right = n - 1;
    while(left < right){
        if(arr1[left] == arr2[right]){
            lastFound = arr1[left];
            left++;
            right--;
        } else if(arr1[left] < arr2[right])
            left++;
        else
            right--;
    }
    cout << lastFound << endl;
    return 0;
}