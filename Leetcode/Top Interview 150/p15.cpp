/*
 * Created By George on 4/11/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/3sum/?envType=study-plan-v2&envId=top-interview-150
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vveci ans;
        int tempValueLookingFor;
        int leftPtr;
        int rightPtr;
        map<veci, bool> foundBefore;

        for (int i = 0 ; i < nums.size() ; i++) {
            tempValueLookingFor = 0 - nums[i];
            leftPtr = 0;
            rightPtr = nums.size() - 1;
            while (leftPtr < rightPtr) {
                if (leftPtr == i)
                    leftPtr++;
                else if (rightPtr == i)
                    rightPtr--;
                else {
                    if (nums[leftPtr] + nums[rightPtr] == tempValueLookingFor) {
                        veci tempVec = {nums[i], nums[leftPtr], nums[rightPtr]};
                        sort(tempVec.begin(), tempVec.end());
                        if (!foundBefore[tempVec]) {
                            ans.push_back(tempVec);
                            foundBefore[tempVec] = true;
                        }
                        leftPtr++;

                        while ((leftPtr < nums.size()) && nums[leftPtr] == nums[leftPtr - 1])
                            leftPtr++;
                        rightPtr--;
                        while ((rightPtr >= 0) && nums[rightPtr] == nums[rightPtr + 1])
                            rightPtr--;
                    } else if (nums[leftPtr] + nums[rightPtr] < tempValueLookingFor)
                        leftPtr++;
                    else
                        rightPtr--;
                }
            }
        }

        return ans;
    }
};

int main() {

    veci nums = {-1,0,1,2,-1,-4};
    Solution solution;
    solution.threeSum(nums);
    return 0;
}