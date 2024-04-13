/*
 * Created By George on 4/11/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        veci indices = {0, (int)(numbers.size() - 1)};

        while (indices[0] < indices[1]) {
            if (numbers[indices[0]] + numbers[indices[1]] == target)
                break;
            if (numbers[indices[0]] + numbers[indices[1]] > target)
                indices[1]--;
            else
                indices[0]++;
        }

        indices[0]++;
        indices[1]++;
        return indices;
    }
};

int main() {


    return 0;
}