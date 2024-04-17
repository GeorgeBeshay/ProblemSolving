/*
 * Created By George on 4/17/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
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
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] < nums[(mid - 1 + nums.size()) % nums.size()])
                return nums[mid];
            else {
                if (nums[mid] > nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            if (nums[mid] > nums[(mid + 1) % nums.size()])
                return nums[(mid + 1) % nums.size()];

        }
        return -1;
    }
};

int main() {

    Solution solution;
    veci v = {5,1,2,3,4};
    cout << solution.findMin(v);


    return 0;
}