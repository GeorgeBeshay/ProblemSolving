/*
 * Created By George on 9/11/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
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
    int strStr(string haystack, string needle) {

        int tempStartIdx = 0;

        while (tempStartIdx <= (int)(haystack.size() - needle.size())) {
            for (int i = tempStartIdx ; i < haystack.size() ; i++) {
                if (haystack[i] != needle[i - tempStartIdx])
                    break;
                if (i - tempStartIdx == needle.size() - 1)
                    return tempStartIdx;
            }
            tempStartIdx++;
        }

        return -1;

    }
};

int main() {

    Solution solution;
    cout << solution.strStr("aaa", "aaaa") << endl;


    return 0;
}