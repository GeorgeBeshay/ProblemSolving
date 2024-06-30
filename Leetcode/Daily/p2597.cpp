/*
 * Created By George on 5/24/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/the-number-of-beautiful-subsets/
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

    void dfsAndBacktrack(vector<int>& nums,
                         int k,
                         int currentIdx,
                         unordered_map<int, int>& currentElementsInSet,
                         int* ans,
                         int* currentElementsCount) {
        if (currentIdx == nums.size()) {
            *ans += (*currentElementsCount > 0 ? 1 : 0);
            return;
        }

        // in case that we won't take this element
        dfsAndBacktrack(nums, k, currentIdx + 1, currentElementsInSet, ans, currentElementsCount);

        // in case that we can take this element
        if (currentElementsInSet[nums[currentIdx] - k] == 0 && currentElementsInSet[nums[currentIdx] + k] == 0) {

            currentElementsInSet[nums[currentIdx]] += 1;
            (*currentElementsCount)++;
            dfsAndBacktrack(nums, k, currentIdx + 1, currentElementsInSet, ans, currentElementsCount);
            (*currentElementsCount)--;
            currentElementsInSet[nums[currentIdx]] -= 1;

        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> tempSetElements;
        int ans = 0;
        int currentElementsCount = 0;
        dfsAndBacktrack(nums, k, 0, tempSetElements, &ans, &currentElementsCount);
        return ans;
    }
};

int main() {

    Solution solution;

    veci v = {18, 12, 10, 5, 6, 2, 18, 3};

    cout << solution.beautifulSubsets(v, 8);

    return 0;
}