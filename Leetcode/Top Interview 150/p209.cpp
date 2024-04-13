/*
 * Created By George on 4/12/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/minimum-size-subarray-sum/description/
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int leftPtr = 0;
        int rightPtr = 1;
        int prefixSum[nums.size() + 1];
        int minLen = MAX_INT;
        prefixSum[0] = 0;

        for (int i = 0 ; i < nums.size() ; i++)
            prefixSum[i+1] = prefixSum[i] + nums[i];

        while (leftPtr < rightPtr && rightPtr <= nums.size()) {
            if (prefixSum[rightPtr] - prefixSum[leftPtr] >= target) {
                if (rightPtr - leftPtr < minLen)
                    minLen = rightPtr - leftPtr;
                leftPtr++;
            } else {
                rightPtr++;
            }
        }

        return minLen == MAX_INT ? 0 : minLen;
    }
};

int main() {


    return 0;
}