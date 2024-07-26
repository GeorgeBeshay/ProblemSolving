/*
 * Created By George on 10/10/2023.
 */

/*
 * Problem Link:        https://leetcode.com/problems/search-insert-position/
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
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int target, int left, int right){
        if(nums[0] > target)
            return 0;
        if(nums[nums.size() - 1] < target)
            return nums.size();

        if(right < left) {
            if(nums[left] > target)
                return left;
            else
                return left + 1;
        }
        if(right == left) {
            if (nums[right] >= target)
                return right;
            else
                return right + 1;
        }

        int mid = left + ((right - left) / 2);
        // recursive cases
        if(nums[mid] < target)
            return binarySearch(nums, target, mid + 1, right);
        else if(nums[mid] > target)
            return binarySearch(nums, target, left, mid - 1);
        else
            return mid;     // base case
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> v = {1, 3, 5, 6};
    vector<int> v = {1};
    cout << sol.searchInsert(v, 1);

    return 0;
}