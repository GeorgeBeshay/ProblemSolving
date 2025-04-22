/*
 * Created By George on 9/11/2024.
 */

/*
 * Problem Link:                https://leetcode.com/problems/longest-common-prefix/
 * Problem Status:              Accepted
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

    string getCommonPrefix(string s1, string s2) {
        string ans = "";
        int smallestSize = min((int)s1.size(), (int)s2.size());

        for (int i = 0 ; i < smallestSize ; i++) {
            if (s1[i] != s2[i])
                break;
            ans += s1[i];
        }

        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for (int i = 1 ; i < strs.size() ; i++) {
            ans = getCommonPrefix(ans, strs[i]);
        }

        return ans;
    }
};

int main() {


    return 0;
}