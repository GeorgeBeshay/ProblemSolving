/*
 * Created By George on 10/10/2023.
 */

/*
 * Problem Link:            https://leetcode.com/problems/majority-element/description/
 * Problem Status:          Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>

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
    int majorityElement(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }

    int solve(vector<int>& nums, int start, int end){
        // base case
        if(start == end)
            return nums[start];
        // recursive case
        int midIdx = start + ((end - start) / 2);
        int leftMajor = solve(nums, start, midIdx);
        int rightMajor = solve(nums, midIdx + 1, end);
        int major;
        if(leftMajor != rightMajor){
            if(countMajorInSubarray(leftMajor, start, midIdx, nums)
            > countMajorInSubarray(rightMajor, midIdx + 1, end, nums))
                major = leftMajor;
            else
                major = rightMajor;
        } else
            major = rightMajor;
        return major;
    }

    int countMajorInSubarray(int num, int leftIdx, int rightIdx, vector<int>& nums){
        int count = 0;
        for(int i = leftIdx ; i <= rightIdx ; i++)
            if(nums[i] == num)
                count++;
        return count;
    }
};

int main() {

//    veci temp = {2, 2};
//    veci temp = {3, 2, 3};
//    veci temp = {6, 6, 6, 7, 7};
//    veci temp = {12,52,12,70,12,61,12,12,50,72,82,12,11,25,28,43,40,12,12,53,12,12,98,12,12,92,81,2,12,15,40,12,12,9,12,31,12,12,12,12,77,12,12,50,12,12,12,93,41,92,12,12,12,12,12,12,12,12,12,37,48,14,12,70,82,12,80,12,12,12,12,56,30,12,8,12,50,12,20,12,21,97,12,42,12,10,12,38,73,15,9,11,79,12,12,28,51,12,15,12};
    veci temp = {6, 5, 5};
    Solution solution = Solution();
    cout << solution.majorityElement(temp);

    return 0;
}

