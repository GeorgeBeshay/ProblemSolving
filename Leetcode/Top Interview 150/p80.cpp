/*
 * Created By George on 2/4/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
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
    int removeDuplicates(vector<int>& nums) {

        int lastNumVal = -100000, firstDuplicateIndex = -1, lastNumCount = 0, k = 0;
        int temp;

        for (int i = 0 ; i < nums.size() ; i++) {

            if (nums[i] == lastNumVal)
                lastNumCount++;
            else {
                lastNumCount = 1;
                lastNumVal = nums[i];
            }

            if (lastNumCount <= 2) {
                k++;
                if (firstDuplicateIndex >= 0) {
                    temp = nums[firstDuplicateIndex];
                    nums[firstDuplicateIndex] = nums[i];
                    nums[i] = nums[firstDuplicateIndex];
                    firstDuplicateIndex++;
                }
            } else {
                if (firstDuplicateIndex < 0)
                    firstDuplicateIndex = i;
            }
        }

        return k;
    }
};

int main() {

    Solution solution;
    veci v = {1, 1, 1, 2, 2, 3};
    solution.removeDuplicates(v);

    return 0;
}