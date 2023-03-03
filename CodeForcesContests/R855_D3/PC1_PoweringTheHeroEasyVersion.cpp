/*
 * Created By George on 3/2/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/1800/problem/C1
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;
#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int getSum(veci v, int count);
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
    veci u;
    for(int i = 0 ; i < in.size() ; i++){
        if(in[i] == 0){
            if(!u.empty()) {
                sort(u.begin(), u.end());
                ans += u[u.size() - 1];
                u.erase(u.end() - 1);
            }
        } else {
            u.push_back(in[i]);
        }
    }
    return ans;
}