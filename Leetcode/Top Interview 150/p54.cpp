/*
 * Created By George on 6/19/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/spiral-matrix/
 * Problem Status:      Accepted
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
         * Moving Directions Defined
         * 0 = >>
         * 1 = <<
         * 2 = ^^
         * 3 = down
         */
        int movingDirection = 0;
        veci currentIdx = {0, 0};

        veci ans(matrix.size() * matrix[0].size());
        int ansIdx = 0;

        map<veci, bool> visitedCells;



        while (ansIdx < ans.size()) {

            ans[ansIdx] = matrix[currentIdx[0]][currentIdx[1]];
            visitedCells[currentIdx] = true;

            switch (movingDirection) {

                case 0:
                    currentIdx[1]++;
                    if (currentIdx[1] == matrix[0].size() || visitedCells[currentIdx]) {
                        movingDirection = 3;
                        currentIdx[0]++;
                        currentIdx[1]--;
                    }
                    break;

                case 1:
                    currentIdx[1]--;
                    if (currentIdx[1] == -1 || visitedCells[currentIdx]) {
                        movingDirection = 2;
                        currentIdx[0]--;
                        currentIdx[1]++;
                    }
                    break;

                case 2:
                    currentIdx[0]--;
                    if (currentIdx[0] == -1 || visitedCells[currentIdx]) {
                        movingDirection = 0;
                        currentIdx[0]++;
                        currentIdx[1]++;
                    }
                    break;

                case 3:
                    currentIdx[0]++;
                    if (currentIdx[0] == matrix.size() || visitedCells[currentIdx]) {
                        movingDirection = 1;
                        currentIdx[0]--;
                        currentIdx[1]--;
                    }
                    break;
            }

            ansIdx++;
        }

        return ans;

    }
};

int main() {

    Solution solution;
    vector<veci> v = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//    vector<veci> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    veci tempAns = solution.spiralOrder(v);

    for(int x : tempAns)
        cout << x << ", ";
    cout << endl;

    return 0;
}