/*
 * Created By George on 1/28/2024.
 */

/*
 * Problem Link:
 * Problem Status:
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
    int removeElement(vector<int>& nums, int val) {
        int availableIndex = nums.size() - 1;
        int bad = 0;
        while (availableIndex >= 0 && nums[availableIndex] == val)
            availableIndex--;
        int i;
        for (i = 0 ; i < availableIndex ; i++) {
            if (nums[i] == val) {
                nums[i] = nums[availableIndex];
                nums[availableIndex] = val;
                while (availableIndex >= 0 && nums[availableIndex] == val)
                    availableIndex--;
            }
        }
        return availableIndex + 1;
    }
};

int main() {


    veci v = {3, 2, 2, 3};
    Solution solution;
    solution.removeElement(v, 3);

    return 0;
}