/*
 * Created By George on 4/11/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/remove-k-digits/?envType=daily-question&envId=2024-04-11
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
    string removeKdigits(string num, int k) {
        stack<char> s;
        for (int i = 0 ; i < num.size() ; i++) {
            if (s.empty())
                s.push(num[i]);
            else {
                if (!s.empty() && (s.top() - '0' > num[i] - '0') && k > 0) {
                    s.pop();
                    k--;
                    while (!s.empty() && (s.top() - '0' > num[i] - '0') && k > 0) {
                        s.pop();
                        k--;
                    }
                    s.push(num[i]);
                } else {
                    if (k == num.size() - i) {
                        k--;
                        continue;
                    }
                    s.push(num[i]);
                }
            }
        }

        string res(num.size() - k, '0');
        int idx = res.size() - 1;
        while (!s.empty() && idx >= 0) {
            res[idx] = s.top();
            s.pop();
            idx--;
        }
        int zeroCount = 0;
        for (int i = 0 ; i < res.size() ; i++) {
            char c = res[i];
            if (c != '0')
                break;
            else
                zeroCount++;
        }
        if(zeroCount == res.size() && (zeroCount > 0))
            zeroCount--;
        if (res.empty())
            return "0";
        return res.substr(zeroCount);
    }
};

int main() {

    Solution solution;
    string s = "1234567890";
    cout << solution.removeKdigits(s, 9);

    return 0;
}