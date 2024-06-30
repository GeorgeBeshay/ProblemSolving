/*
 * Created By George on 6/27/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/jump-game/
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
    bool canJump(vector<int>& nums) {
        int maxReached = 0;

        for (int i = 0 ; i < nums.size() ; i++) {

            if (i > maxReached)
                return false;

            maxReached = max(maxReached, i + nums[i]);
        }

        return true;
    }
};

int main() {

    veci nums = {2,3,1,1,4};
//    veci nums = {3,2,1,0,4};

    Solution solution;

    cout << solution.canJump(nums) << endl;

    return 0;
}