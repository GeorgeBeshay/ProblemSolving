/*
 * Created By George on 5/21/2024.
 */

/*
 * Problem Link:            https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
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

    static int searchForTarget(veci& nums, int target, bool beginning) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {

                if (
                        (beginning && (mid == 0 || nums[mid - 1] != target)) ||
                        (!beginning && (mid == nums.size() - 1 || nums[mid + 1] != target))
                        ) {
                    return  mid;
                }
                if (beginning)
                    right = mid - 1;
                else
                    left = mid + 1;

            } else {
                if (nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        veci ans = {-1, -1};

        // search for the starting index first
        ans[0] = searchForTarget(nums, target, true);
        // search for the ending index
        ans[1] = searchForTarget(nums, target, false);

        return ans;
    }
};

int main() {

    Solution solution;

    vveci v = {
            {5, 7, 7, 8, 8, 10},
            {5,7,7,8,8,10},
            {},
            {1, 2, 3, 4, 5, 100, 200}
    };
    veci t = {8, 6, 0, 100};
    vveci answers = {
            {3, 4},
            {-1, -1},
            {-1 , -1},
            {5, 5}
    };

    for (int i = 0 ; i < v.size() ; i++) {
        veci tempAns = solution.searchRange(v[i], t[i]);
        cout << "Expected: {" << answers[i][0] << ", " << answers[i][1] << "}" << endl;
        cout << "Found: {" << tempAns[0] << ", " << tempAns[1] << "}" << endl;
        cout << endl << endl;
    }

    return 0;
}