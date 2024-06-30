/*
 * Created By George on 6/26/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/set-matrix-zeroes/
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
    void setZeroes(vector<vector<int>>& matrix) {
        // store the rows and cols numbers that are to be zeroed out.
        veci colsToBeZeroed;
        veci rowsToBeZeroed;

        for (int i = 0 ; i < matrix.size() ; i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    colsToBeZeroed.push_back(j);
                    rowsToBeZeroed.push_back(i);
                }
            }
        }

        // O( n x m )
        for (int colIdx : colsToBeZeroed) {
            for (auto & tempRow : matrix) {
                tempRow[colIdx] = 0;
            }
        }

        // O( m x n)
        for (int rowIdx : rowsToBeZeroed) {
            for (int & tempCell : matrix[rowIdx]) {
                tempCell = 0;
            }
        }
    }
};

int main() {

    vveci matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
//    vveci matrix = {{1,1,1},{1,0,1},{1,1,1}};
    Solution solution;

    solution.setZeroes(matrix);

    for (auto & tempRow : matrix) {
        for (auto & tempCell : tempRow) {
            cout << tempCell << ", ";
        }
        cout << endl;
    }

    return 0;
}