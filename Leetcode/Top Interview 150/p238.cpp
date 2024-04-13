/*
 * Created By George on 4/10/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150
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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int zeroCount = 0;
        int totalProduct = 1;

        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] == 0)
                zeroCount++;
            else
                totalProduct *= nums[i];
        }
        for (int i = 0 ; i < nums.size() ; i++) {
            if ((nums[i] != 0 && zeroCount == 1) || (zeroCount > 1))
                ans[i] = 0;
            else if (nums[i] == 0)
                ans[i] = totalProduct;
            else
                ans[i] = totalProduct / nums[i];
        }

        return ans;
    }
};

int main() {


    return 0;
}