/*
 * Created By George on 5/21/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/subsets/
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
    string intToBinaryString(int num) {
        std::bitset<32> binary(num);
        return binary.to_string();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vveci ans;

        for (int i = 0 ; i < pow(2, nums.size()) ; i++) {
            string binaryRepresentation = intToBinaryString(i).substr(32 - nums.size());
            veci tempAns = {};
            for (int j = 0 ; j < binaryRepresentation.size() ; j++) {
                if (binaryRepresentation[j] == '1') {
                    tempAns.push_back(nums[nums.size() - 1 - j]);
                }
            }
            ans.push_back(tempAns);
        }

        return ans;
    }
};

int main() {


    veci v = {1, 2, 3};
    Solution solution;

    vveci ans = solution.subsets(v);

    for (auto & an : ans) {
        for (int j : an) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}