/*
 * Created By George on 5/22/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/palindrome-partitioning/
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

    static string intToBinaryString(int num, int length) {
        bitset<32> binary(num);
        return binary.to_string().substr(32 - length);
    }

    static bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left != s.size() - 1) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }

        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        string tempBitsRepresentation;
        map<vector<string>, bool> alreadyExists;

        for (int i = 0 ; i < pow(2, s.size()) ; i++) {
            tempBitsRepresentation = intToBinaryString(i, s.size());

            vector<string> possiblePartition;
            string tempPalindrome;
            bool good = true;

            for (int j = 0 ; j < s.size() ; j++) {
                if (tempBitsRepresentation[j] == '1' && !tempPalindrome.empty()) {
                    if (!isPalindrome(tempPalindrome)) {
                        good = false;
                        break;
                    }
                    possiblePartition.push_back(tempPalindrome);
                    tempPalindrome = "";
                }
                tempPalindrome += s[j];
            }
            if (!tempPalindrome.empty() && !isPalindrome(tempPalindrome))
                good = false;
            possiblePartition.push_back(tempPalindrome);

            if (good && !alreadyExists[possiblePartition]) {
                ans.push_back(possiblePartition);
                alreadyExists[possiblePartition] = true;
            }

        }

        return ans;
    }
};

int main() {

    string s = "ababcbc";
    Solution solution;

    vector<vector<string>> ans = solution.partition(s);

    for (vector<string> v : ans) {
        for (string x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}