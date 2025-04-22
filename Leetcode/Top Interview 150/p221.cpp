/*
 * Created By George on 4/22/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/maximal-square/
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
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> cols(matrix[0].size(), 0);
        vector<int> colsNeg(matrix[0].size(), -1);
        vector<vector<int>> maxSquares(matrix.size(), colsNeg);
        vector<vector<int>> maximalWidths(matrix.size(), cols), maximalHeights(matrix.size(), cols);
        prepareMaximalHeights(matrix, maximalHeights);
        prepareMaximalWidths(matrix, maximalWidths);

        maxSquareDims(matrix, 0, 0, maximalWidths, maximalHeights, maxSquares);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (maxSquares[i][j] == -1) {
                    maxSquareDims(matrix, i, j, maximalWidths, maximalHeights, maxSquares);
                }
            }
        }

        int maxSquareDims = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (maxSquares[i][j] > maxSquareDims) {
                    maxSquareDims = maxSquares[i][j];
                }
            }
        }

        return maxSquareDims * maxSquareDims;
    }

    void maxSquareDims(
        vector<vector<char>>& matrix,
        int i,
        int j,
        vector<vector<int>>& maximalWidths,
        vector<vector<int>>& maximalHeights,
        vector<vector<int>>& maximalSquares
    ) {

        if (maximalSquares[i][j] != -1){
            return;
        }

        if (matrix[i][j] == '0') {
            maximalSquares[i][j] = 0;
            return;
        } else {
            maximalSquares[i][j] = 1;
        }

        if (i+1 >= matrix.size() || j+1 >= matrix[0].size()) {
            return;
        }
        maxSquareDims(matrix, i+1, j+1, maximalWidths, maximalHeights, maximalSquares);

        if (maximalSquares[i+1][j+1] > 0) {
            maximalSquares[i][j] = min(maximalSquares[i + 1][j + 1], min(maximalHeights[i+1][j], maximalWidths[i][j+1])) + 1;
        }
    }

    void prepareMaximalHeights(vector<vector<char>>& matrix, vector<vector<int>>& maximalHeights) {
        for (int i = matrix.size() - 1; i >= 0; i--) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i < matrix.size() - 1) {
                    if (matrix[i][j] == '0') {
                        maximalHeights[i][j] = 0;
                    } else {
                        maximalHeights[i][j] = 1 + maximalHeights[i+1][j];
                    }
                } else {
                    maximalHeights[i][j] = (matrix[i][j] == '1' ? 1 : 0);
                }
            }
        }
    }

    void prepareMaximalWidths(vector<vector<char>>& matrix, vector<vector<int>>& maximalWidths) {
        for (int j = matrix[0].size() - 1; j >= 0; j--) {
            for (int i = 0; i < matrix.size(); i++) {
                if (j < matrix[0].size() - 1) {
                    if (matrix[i][j] == '0') {
                        maximalWidths[i][j] = 0;
                    } else {
                        maximalWidths[i][j] = 1 + maximalWidths[i][j+1];
                    }
                } else {
                    maximalWidths[i][j] = (matrix[i][j] == '1' ? 1 : 0);
                }
            }
        }
    }
};

int main() {

    vector<vector<char>> v = {
        {'1','0','1','1','0','1'},
        {'1','1','1','1','1','1'},
        {'0','1','1','0','1','1'},
        {'1','1','1','0','1','0'},
        {'0','1','1','1','1','1'},
        {'1','1','0','1','1','1'}
    };

//    vector<vector<char>> v = {
//        {'0','0'},
//        {'0', '0'}
//    };

//    vector<vector<char>> v = {
//        {'1','1','1','1','0'},
//        {'1','1','1','1','0'},
//        {'1','1','1','1','1'},
//        {'1','1','1','1','1'},
//        {'0','0','1','1','1'}
//    };

    Solution solution;

    cout << solution.maximalSquare(v);

    return 0;
}