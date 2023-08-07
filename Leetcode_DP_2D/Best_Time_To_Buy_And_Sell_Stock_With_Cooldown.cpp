/*
 * Created By George on 8/7/2023.
 */

/*
 * Problem Link:        https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
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
    int maxProfit(vector<int>& prices) {
        map<pair<int, bool>, int> cache;
        return dfs(0, true, prices, cache);
    }

    int dfs(int i, bool isBuying, vector<int>& prices, map<pair<int, bool>, int>& cache){
        if(i >= prices.size())
            return 0;

        if(cache[{i, isBuying}] != 0)
            return cache[{i, isBuying}];


        int tempAns;
        if(isBuying)
            tempAns = max(dfs(i + 1, false, prices, cache) - prices[i],
                              dfs(i + 1, true, prices, cache));
        else
            tempAns = max(dfs(i + 2, true, prices, cache) + prices[i],
                       dfs(i + 1, false, prices, cache));
        cache[{i, isBuying}] = tempAns;

        return tempAns;
    }
};

int main() {


    return 0;
}