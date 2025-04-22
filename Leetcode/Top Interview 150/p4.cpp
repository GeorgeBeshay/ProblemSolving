/*
 * Created By George on 1/27/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/median-of-two-sorted-arrays/
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int totalSize = nums1.size() + nums2.size();
        int smallerSize = min(nums1.size(), nums2.size());
        int largerSize = max(nums1.size(), nums2.size());
        int left, right, mid, mid2;

        auto smallerVec = [&](int idx) {
            return !nums1.empty() && nums1.size() <= nums2.size() ? nums1[idx] : nums2[idx];
        };
        auto largerVec = [&](int idx) {
            return nums2.size() >= nums1.size() ? nums2[idx] : nums1[idx];
        };

        left = 0;
        right = smallerSize - 1;

        while (true) {
            mid = floor((left + right) / 2.0);
            mid2 = ((totalSize+1) / 2) - mid - 2;

            int nums1End = mid >= 0 ? smallerVec(mid) : -(MAX_INT);
            int nums2End = mid2 >= 0 ? largerVec(mid2) : -(MAX_INT);
            int nums1Start = mid+1 >= smallerSize ? MAX_INT : smallerVec(mid+1);
            int nums2Start = mid2+1 >= largerSize ? MAX_INT : largerVec(mid2+1);

            if (nums1End <= nums2Start && nums2End <= nums1Start) {
                // partition is good
                if (totalSize % 2 == 0) {
                    return (max(nums1End, nums2End) + min(nums1Start, nums2Start)) / 2.0;
                } else {
                    return max(nums1End, nums2End);
                }
            } else if (nums1End > nums2Start) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
};

int main() {

    veci v1 = {3};
    veci v2 = {-2, -1};

    Solution solution;

    cout << solution.findMedianSortedArrays(v1, v2) << endl;

    return 0;
}