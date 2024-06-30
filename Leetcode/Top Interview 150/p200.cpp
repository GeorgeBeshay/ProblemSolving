/*
 * Created By George on 4/19/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/number-of-islands/description/
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
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0 ; i < grid.size() ; i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    solveRecursive(grid, i, j);
                }
            }
        }
        return ans;
    }

    void solveRecursive(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        if (j < grid[0].size() - 1 && grid[i][j + 1] == '1')
            solveRecursive(grid, i, j + 1);
        if (j > 0 && grid[i][j - 1] == '1')
            solveRecursive(grid, i, j - 1);
        if (i < grid.size() - 1 && grid[i + 1][j] == '1')
            solveRecursive(grid, i + 1, j);
        if (i > 0 && grid[i - 1][j] == '1')
            solveRecursive(grid, i - 1, j);
    }
};

int main() {


    return 0;
}