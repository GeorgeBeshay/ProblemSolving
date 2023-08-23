/*
 * Created By George on 8/23/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/978/problem/C
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

    int n, m;
    cin >> n >> m;
    ll rooms[n], letters[m], ans;
    memset(rooms, 0, sizeof(rooms));memset(letters, 0, sizeof(letters));
    for(int i = 0 ; i < n ; i++) {
        cin >> rooms[i];
        if(i < 1)
            continue;
        rooms[i] += rooms[i-1];
    }
    int left = 0, right, mid;
    for(int i = 0 ; i < m ; i++) {
        cin >> letters[i];
        right = n-1, mid = left + (right - left) / 2;
        while(left < right){
            if(rooms[mid] >= letters[i] && rooms[mid - 1] < letters[i])
                break;
            if(rooms[mid] < letters[i])
                left = mid + 1;
            else
                right = mid - 1;
            mid = left + (right - left) / 2;
        }
        ans = letters[i] - ((mid > 0) ? rooms[mid-1] : 0);
        cout << mid + 1 << " " << ans << endl;
    }


    return 0;
}