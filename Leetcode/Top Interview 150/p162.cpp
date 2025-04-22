/*
 * Created By George on 1/26/2025.
 */

/*
 * Problem Link:                https://leetcode.com/problems/find-peak-element/
 * Problem Status:              Accepted.
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
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (mid == 0) {
                if (nums.size() == 1 || nums[mid] > nums[mid+1])
                    return mid;

            } else if (mid == nums.size() - 1) {
                if (nums[mid] > nums[mid-1])
                    return mid;

            } else {
                if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid + 1])
                    return mid;

            }

            if (mid == 0 || nums[mid] > nums[mid - 1])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};

int main() {


    return 0;
}