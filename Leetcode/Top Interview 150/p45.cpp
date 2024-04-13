/*
 * Created By George on 4/10/2024.
 */

/*
 * Problem Link:            https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150
 * Problem Status:          Accepted.
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
    int jump(vector<int>& nums) {
        int jumps[nums.size()];
        for (int i = 0 ; i < nums.size() ; i++)
            jumps[i] = 10000 + 1; // max len + 1
        jumps[nums.size() - 1] = 0;

        for (int i = nums.size() - 2 ; i >= 0 ; i--) {
            jumps[i] = 1 + jumps[min(i + nums[i], int(nums.size() - 1))];
            if (jumps[i] < jumps[i+1]) {
                for (int j = i + 1; j < nums.size() ; j++) {
                    if (jumps[j] > jumps[i])
                        jumps[j] = jumps[i];
                    else
                        break;
                }
            }
        }

        return jumps[0];
    }
};

int main() {

    return 0;
}