/*
 * Created By George on 7/26/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/length-of-last-word/
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
    int lengthOfLastWord(string s) {
        int ans = 0;

        for (int i = s.size() - 1 ; i >= 0 ; i--) {
            if (s[i] == ' ' && ans > 0)
                return ans;
            if (s[i] != ' ')
                ans++;
        }

        return ans;
    }
};

int main() {


    return 0;
}