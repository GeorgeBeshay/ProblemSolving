/*
 * Created By George on 1/26/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/search-in-rotated-sorted-array/
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
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[left] < nums[right]) {
                // normal case
                if (target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // new case
                if (nums[mid] > nums[right]) {
                    if (target < nums[left]) {
                        left = mid + 1;
                    } else {
                        if (target > nums[mid])
                            left = mid + 1;
                        else
                            right = mid - 1;

                    }
                } else {
                    if (target > nums[right]) {
                        right = mid - 1;
                    } else {
                        if (target > nums[mid])
                            left = mid + 1;
                        else
                            right = mid - 1;

                    }
                }
            }
        }

        return -1;
    }
};

int main() {


    return 0;
}