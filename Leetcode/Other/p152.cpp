/*
 * Created By George on 4/14/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/maximum-product-subarray/
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
    int maxProduct(vector<int>& nums) {
        int dp[nums.size()][2];
        dp[0][0] = nums[0]; dp[0][1] = nums[0];
        int ans = nums[0];
        for (int i = 1 ; i < nums.size() ; i++) {
            dp[i][0] = min(nums[i], min(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]));
            dp[i][1] = max(nums[i], max(dp[i - 1][1] * nums[i], dp[i - 1][0] * nums[i]));
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }

        return ans;
    }
};

int main() {


    return 0;
}