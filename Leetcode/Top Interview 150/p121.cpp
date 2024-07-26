/*
 * Created By George on 7/26/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = MAX_INT;
        int ans = 0;
        for (int price : prices) {
            if (price < min) {
                min = price;
            } else {
                if (price - min > ans)
                    ans = price - min;
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}