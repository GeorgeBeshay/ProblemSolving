/*
 * Created By George on 9/17/2023.
 */

/*
 * Problem Link:        https://codeforces.com/contest/987/problem/C
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

int solve(veci& fonts, veci& costs){
    int ans = MAX_INT, tmpAns;
    for(int i = 1 ; i < fonts.size() - 1 ; i++){
        veci v = {-1, i, -1};
        for(int j = 0 ; j < i ; j++){
            if(fonts[j] < fonts[v[1]] && (costs[j] < costs[v[0]] || (costs[v[0]] == -1)))
                v[0] = j;
        }
        for(int k = i+1 ; k < fonts.size() ; k++){
            if(fonts[k] > fonts[v[1]] && (costs[k] < costs[v[2]] || (costs[v[2]] == -1)))
                v[2] = k;
        }
        tmpAns = 0;
        for(auto x : v)
            if(x != -1)
                tmpAns += costs[x];
            else {
                tmpAns = MAX_INT;
                break;
            }
        if(tmpAns < ans)
            ans = tmpAns;
    }
    return ans == numeric_limits<int>::max() ? -1 : ans;
}

int main() {

    int n;
    cin >> n;
    veci tmpFonts(n), tmpCosts(n);
    map<int, int> fontCostMap;

    for(int i = 0 ; i < n ; i++)
        cin >> tmpFonts[i];
    for(int i = 0 ; i < n ; i++) {
        cin >> tmpCosts[i];
    }

    cout << solve(tmpFonts, tmpCosts) << endl;

    return 0;
}

