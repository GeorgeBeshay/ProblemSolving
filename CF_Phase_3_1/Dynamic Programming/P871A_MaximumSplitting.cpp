/*
 * Created By George on 8/20/2023.
 */

/*
 * Problem Link:           https://codeforces.com/contest/871/problem/A
 * Problem Status:         Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> veci;
typedef vector<vector<ll>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL << endl)

int main() {
    int q, x;
    cin >> q;
    while(q--){
        cin >> x;
        if(x <= 3)
            cout << -1 << endl;
        else if(x <= 9){
            switch (x) {
                case 4:
                    cout << 1 << endl;
                    break;
                case 5:
                    cout << -1 << endl;
                    break;
                case 6:
                    cout << 1 << endl;
                    break;
                case 7:
                    cout << -1 << endl;
                    break;
                case 8:
                    cout << 2 << endl;
                    break;
                case 9:
                    cout << 1 << endl;
                    break;
                default:
                    break;
            }
        } else {
            if(x % 4 == 0)
                cout << x / 4 << endl;
            else if(x % 4 == 1)
                cout << 1 + (x - 9) / 4 << endl;
            else if(x % 4 == 2)
                cout << 1 + (x - 6) / 4 << endl;
            else
                if(x > 11)
                    cout << 2 + (x - 15) / 4 << endl;
                else
                    cout << -1 << endl;
        }
    }

    return 0;
}