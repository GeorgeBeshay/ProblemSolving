/*
 * Created By George on 10/7/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/is-subsequence/
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
    bool isSubsequence(string s, string t) {

        int p1 = 0, p2 = 0;

        while (p1 != s.size()) {
            while (s[p1] != t[p2] && p2 < t.size()) {
                p2++;
            }
            if (p2 >= t.size())
                return false;
            p1++;
            p2++;
        }

        return true;
    }
};

int main() {


    return 0;
}