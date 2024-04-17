/*
 * Created By George on 4/13/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/longest-consecutive-sequence/
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
    int longestConsecutive(vector<int>& nums) {
        int longestSeq = 0;
        int tempSeq = nums.size() > 0 ? 1 : 0;
        set<int> s;

        for (int num : nums)
            s.insert(num);

        auto pt = s.begin();
        int lastVal = -MAX_INT;

        while (pt != s.end()) {
            if (lastVal != -MAX_INT) {
                if (*pt == lastVal + 1) {
                    tempSeq++;
                } else {
                    if (tempSeq > longestSeq)
                        longestSeq = tempSeq;
                    tempSeq = 1;
                }
            }
            lastVal = *pt;
            pt++;
        }
        if (tempSeq > longestSeq)
            longestSeq = tempSeq;

        return longestSeq;
    }
};

int main() {

    veci x = {9,1,-3,2,4,8,3,-1,6,-2,-4,7};
    Solution solution;
    solution.longestConsecutive(x);
    return 0;
}