/*
 * Created By George on 5/16/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/simplify-path/
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
    string simplifyPath(string path) {
        stack<string> trace;
        string tempToken;
        int currentTokenStartIdx = 1;

        while (currentTokenStartIdx < path.size()) {
            tempToken = getNextToken(path, &currentTokenStartIdx);
            if (tempToken == ".." && !trace.empty()) {
                trace.pop();
            } else if (tempToken != "." && tempToken != ".."){
                trace.push(tempToken);
            }
        }

        stack<string> tempTraceStack;
        while (!trace.empty()) {
            tempTraceStack.push(trace.top());
            trace.pop();
        }

        string simplifiedCanonicalPath = "/";
        while (!tempTraceStack.empty()) {
            if (simplifiedCanonicalPath != "/")
                simplifiedCanonicalPath += "/";
            simplifiedCanonicalPath += tempTraceStack.top();

            tempTraceStack.pop();
        }

        return simplifiedCanonicalPath;
    }

    string getNextToken(string& tokens, int* startingIdx) {

        string newToken;

        for (; *startingIdx < tokens.size() ; (*startingIdx)++) {
            if (tokens[*startingIdx] == '/') {
                while (*startingIdx < tokens.size() && tokens[*startingIdx] == '/')
                    (*startingIdx)++;
                break;
            }
            newToken += tokens[*startingIdx];
        }

        return newToken;
    }
};

int main() {

    Solution solution;
    string path = "/home//foo/";

    cout << solution.simplifyPath(path);


    return 0;
}