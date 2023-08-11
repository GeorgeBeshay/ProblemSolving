/*
 * Created By George on 8/11/2023.
 */

/*
 * Problem Link:        https://leetcode.com/problems/coin-change-ii/
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

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int dpGrid[amount+1][coins.size()+1];
        for(int i = 0 ; i < coins.size()+1 ; i++)
            dpGrid[0][i] = 1;
        for(int i = 1 ; i <= amount ; i++)
            dpGrid[i][0] = 0;

        for(int i = 1 ; i <= amount ; i++)
            for(int j = 1 ; j <= coins.size() ; j++)
                dpGrid[i][j] = dpGrid[i][j-1] + ((i - coins[j-1] >= 0) ? (dpGrid[i - coins[j-1]][j]) : 0);
        return dpGrid[amount][coins.size()];
    }
};

int main() {

    Solution sol = Solution();
    vector<int> v = {1, 2, 5};
    cout << sol.change(5, v) << endl;
    return 0;
}