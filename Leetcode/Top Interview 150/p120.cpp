/*
 * Created By George on 4/22/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/triangle/
 * Problem Status:          Accepted.
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
    int minimumTotal(vector<vector<int>>& triangle) {
        map<pair<int, int>, int> cache;
        return recursiveMinimumTotal(triangle, 0, 0, cache);
    }

    int recursiveMinimumTotal(vector<vector<int>>& triangle, int row, int col, map<pair<int, int>, int>& cache) {
        pair<int, int> tempV = {row, col};
        if (cache.count(tempV) == 0) {
            if (row == triangle.size() - 1) {
                cache[tempV] = triangle[row][col];
            } else {
                cache[tempV] = triangle[row][col] + min(
                    recursiveMinimumTotal(triangle, row+1, col, cache),
                    recursiveMinimumTotal(triangle, row+1, col+1, cache)
                    );
            }
        }

        return cache[tempV];
    }

    int anotherSolution(vector<vector<int>>& triangle) {
        int ans = MAX_INT;
        int lastRowIdx = triangle.size() - 1;

        for (int i = 1; i <= lastRowIdx;  i++) {
            triangle[i][0] += triangle[i-1][0];
            triangle[i][triangle[i].size() - 1] += triangle[i-1][triangle[i-1].size() - 1];
            for (int j = 1; j < triangle[i].size() - 1; j++) {
                triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }

        for (int j = 0; j < triangle[triangle.size() - 1].size(); j++) {
            if (triangle[lastRowIdx][j] < ans) {
                ans = triangle[lastRowIdx][j];
            }
        }

        return ans;
    }
};

int main() {

//    vveci v = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    vveci v = {{-1}, {2, 3}, {1, -1, -3}};
    Solution solution;

    cout << solution.minimumTotal(v) << endl;

    return 0;
}