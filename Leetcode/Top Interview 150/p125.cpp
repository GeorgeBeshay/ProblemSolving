/*
 * Created By George on 10/7/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/valid-palindrome/
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
    static bool isAlphanumericChar(char c) {
        if ( (int) 'a' <= (int) c && (int) c <= (int) 'z' )
            return true;
        if ( (int) 'A' <= (int) c && (int) c <= (int) 'Z' )
            return true;
        if ( (int) '0' <= (int) c && (int) c <= (int) '9' )
            return true;
        return false;
    }

    bool isPalindrome(string s) {
        string sNew = "";
        for (char c : s) {
            if (isAlphanumericChar(c)) {
                sNew += (char) tolower(c);
            }
        }
        for (int i = 0 ; i < sNew.size() ; i++) {
            if (sNew[i] != sNew[sNew.size() - i - 1])
                return false;
        }
        return true;
    }
};

int main() {

    Solution solution;

    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;

    return 0;
}