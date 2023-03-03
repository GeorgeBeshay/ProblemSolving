/*
 * Created By George on 3/3/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/1800/problem/C2
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(veci in);

int main() {
    // ---------------- Separator ----------------
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        veci in(n);ffor(i, n){cin >> in[i];}
        cout << solve(in) << endl;
    }
    // ---------------- Separator ----------------    
    return 0;
}

ll solve(veci in){
    ll ans = 0;
    priority_queue<int> bonuses;
    ffor(i, in.size()){
        if(in[i] > 0)
            bonuses.push(in[i]);
        else {
            if(bonuses.size() > 0) {
                ans += bonuses.top();
                bonuses.pop();
            }
        }
    }
    return ans;
}