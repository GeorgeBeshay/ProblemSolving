/*
 * Created By George on 4/22/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/edit-distance/description/?envType=study-plan-v2&envId=top-interview-150
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
    int minDistance(string text1, string text2) {
        int dp[text1.size() + 1][text2.size() + 1];
        // init dp array
        for (int i = 0 ; i < text1.size() + 1 ; i++) {
            for (int j = 0 ; j < text2.size() + 1 ; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                }
                if (j == 0) {
                    dp[i][j] = i;
                }
            }
        }

        // compute the lcs length
        for (int i = 1 ; i < text1.size() + 1 ; i++) {
            for (int j = 1 ; j < text2.size() + 1 ; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(
                            min(
                                    dp[i-1][j] + 1,      // delete
                                    dp[i][j-1] + 1       // insert
                            ),
                            dp[i-1][j-1] + 1        // replace
                            );
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};

int main() {

    Solution solution;
    cout << solution.minDistance("algorithm", "altruistic") << endl;
    return 0;
}