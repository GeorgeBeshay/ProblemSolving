/*
 * Created By George on 4/13/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/group-anagrams/
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> occurrence;
        vector<vector<string>> ans;
        for (string s : strs) {
            string tempCopy(s);
            sort(tempCopy.begin(), tempCopy.end());
            if (occurrence[tempCopy] != 0)
                ans[occurrence[tempCopy] - 1].push_back(s);
            else {
                vector<string> tempVec = {s};
                ans.push_back(tempVec);
                occurrence[tempCopy] = ans.size();
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}