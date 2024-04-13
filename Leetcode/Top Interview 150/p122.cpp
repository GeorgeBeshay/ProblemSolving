/*
 * Created By George on 4/10/2024.
 */

/*
 * Problem Link:            https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
 * Problem Status:          Accepted.
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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentProfit = 0;
        int lastStockValue = MAX_INT;

        for (int price : prices) {
            if (price > lastStockValue) {
                currentProfit += price - lastStockValue;
            }
            lastStockValue = price;
        }

        return currentProfit;
    }
};

int main() {

    return 0;
}