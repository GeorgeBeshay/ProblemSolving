/*
 * Created By George on 6/21/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/rotate-image/
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
    void rotate(vector<vector<int>>& matrix) {
        vveci rotatedMatrix(matrix[0].size(), veci(matrix.size()));

        for (int i = 0 ; i < matrix.size() ; i++) {
            for (int j = 0 ; j < matrix[0].size() ; j++) {
                rotatedMatrix[j][i] = matrix[matrix.size() - i - 1][j];
            }
        }

        for (int i = 0 ; i < rotatedMatrix.size() ; i++) {
            for (int j = 0 ; j < rotatedMatrix[0].size() ; j++) {
                matrix[i][j] = rotatedMatrix[i][j];
            }
        }
    }
};

int main() {


    return 0;
}