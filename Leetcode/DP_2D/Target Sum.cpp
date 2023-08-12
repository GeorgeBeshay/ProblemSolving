/*
 * Created By George on 8/12/2023.
 */

/*
 * Problem Link:            https://leetcode.com/problems/target-sum/
 * Problem Status:          Accepted.
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int answer = 0;
        solve(0, 0, nums, target, answer);
        return answer;
    }
    void solve(int i, long long currentSum, vector<int>& nums, int target, int& answer){
        if(i >= nums.size() && currentSum == target){
            answer++;
            return;
        } else if(i >= nums.size())
            return;
        solve(i+1, currentSum + nums[i], nums, target, answer);
        solve(i+1, currentSum - nums[i], nums, target, answer);
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << sol.findTargetSumWays(nums, 3);
    return 0;
}