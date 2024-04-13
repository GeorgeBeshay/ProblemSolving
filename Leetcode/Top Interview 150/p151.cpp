/*
 * Created By George on 4/11/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150
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
    string reverseWords(string s) {
        int wordsCount = 0;
        bool startOfWord = true;

        for (char c : s) {
            if (c == ' ')
                startOfWord = true;
            else if (startOfWord) {
                wordsCount++;
                startOfWord = false;
            }
        }

        vector<string> words(wordsCount, "");
        startOfWord = true;
        int currentWord = 0;
        for (char c : s) {
            if (c == ' ' && !startOfWord) {
                currentWord++;
                startOfWord = true;
            }
            else if (c != ' ') {
                words[currentWord] += c;
                startOfWord = false;
            }
        }

        string ans = "";
        for (int i = wordsCount - 1 ; i >= 0 ; i--) {
            ans += words[i];
            if (i != 0)
                ans += " ";
        }

        return ans;
    }
};

int main() {

    string s = "  hello world  ";
    Solution solution;
    cout << solution.reverseWords(s);

    return 0;
}