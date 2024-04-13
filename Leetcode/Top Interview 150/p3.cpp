/*
 * Created By George on 4/12/2024.
 */

/*
 * Problem Link:            https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150
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
    int lengthOfLongestSubstring(string s) {
        map<char, int> occurred;
        int leftPtr = 0;
        int rightPtr = 0;
        int ans = 0;
        occurred[s[leftPtr]] = 1;

        while (leftPtr <= rightPtr && rightPtr < s.size()) {
            if (rightPtr - leftPtr + 1 > ans) {
                ans = rightPtr - leftPtr + 1;
            }
            if (rightPtr < s.size() - 1) {
                rightPtr++;
                occurred[s[rightPtr]]++;
                if (occurred[s[rightPtr]] > 1) {
                    occurred[s[leftPtr]]--;
                    leftPtr++;
                    while (occurred[s[rightPtr]] > 1) {
                        occurred[s[leftPtr]]--;
                        leftPtr++;
                    }
                }
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {

    string s = "abcabcbb";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s);

    return 0;
}