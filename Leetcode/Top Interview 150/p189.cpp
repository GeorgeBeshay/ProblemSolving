/*
 * Created By George on 6/27/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/rotate-array/
 * Problem Status:      Accepted
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
    void rotate(vector<int>& nums, int k) {
        veci rotatedNums(nums.size(), -1);

        for (int i = 0 ; i < nums.size() ; i++) {
            rotatedNums[(i + k) % (int)nums.size()] = nums[i];
        }

        for (int i = 0 ; i < nums.size() ; i++) {
            nums[i] = rotatedNums[i];
        }

    }
};

int main() {

//    veci nums = {1,2,3,4,5,6,7};
//    int k = 3;

    veci nums = {-1,-100,3,99};
    int k = 2;

    Solution solution;

    solution.rotate(nums, k);

    for (auto& num : nums)
        cout << num << ", ";
    cout << endl;


    return 0;
}