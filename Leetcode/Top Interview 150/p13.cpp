/*
 * Created By George on 7/26/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/roman-to-integer/
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
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;

        for (int i = 0 ; i < s.size() ; i++) {
            if (i < s.size() - 1 && m[s[i]] < m[s[i+1]]) {
                ans += m[s[i+1]] - m[s[i]];
                i++;
            } else {
                ans += m[s[i]];
            }
        }

        return ans;
    }
};

int main() {


    return 0;
}