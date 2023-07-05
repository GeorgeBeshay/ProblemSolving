/*
 * Created By George on 7/5/23.
 */
 
 /*
  * Problem Link:       https://codeforces.com/contest/403/problem/A
  * Problem Status:     Accepted.
  */
  
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> veci;
typedef vector<vector<ll>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    
    int t, n, p;

    cin >> t;
    while(t--){
        cin >> n >> p;
        p = 2 * n + p;
        for(int i = 1 ; i <= n - 1; i++) {
            if(p == 0)
                break;
            for (int j = i + 1; j <= n; j++) {
                if (p == 0)
                    break;
                cout << i << " " << j << endl;
                p--;
            }
        }
    }
        
    return 0;
}