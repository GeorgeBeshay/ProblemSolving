/*
 * Created By George on 6/26/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/game-of-life/
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

    bool isValidPosition(int& m, int& n, veci& position) {
        if (position[0] >= m || position[0] < 0 || position[1] >= n || position[1] < 0)
            return false;
        return true;
    }

    int countAliveNeighbours(vveci& board, int rowIdx, int colIdx) {
        int ans = 0;
        int m = (int) board.size();
        int n = (int) board[0].size();

        vveci neighboursOffset = {
                {-1, -1},
                {-1, 0},
                {-1, 1},
                {0, -1},
                {0, 1},
                {+1, -1},
                {+1, 0},
                {+1, 1},
        };

        for (auto offset : neighboursOffset) {
            veci tempNeighbourPosition = {rowIdx + offset[0], colIdx + offset[1]};
            if (
                    isValidPosition(m, n, tempNeighbourPosition) &&
                    board[tempNeighbourPosition[0]][tempNeighbourPosition[1]] == 1
                    ) {
                ans++;
            }
        }

        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vveci newVals(board.size(), veci(board[0].size(), 0));

        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0; j < board[0].size(); j++) {

                int tempLivingNeighbours = countAliveNeighbours(board, i, j);
                bool tempIsLiving = (board[i][j] == 1);

                if (
                        (tempIsLiving && (tempLivingNeighbours >= 2) && (tempLivingNeighbours <= 3))
                        || (!tempIsLiving && (tempLivingNeighbours == 3))
                        )
                    newVals[i][j] = 1;
            }
        }

        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0 ; j < board[0].size() ; j++) {
                board[i][j] = newVals[i][j];
            }
        }
    }
};

int main() {

    vveci board = {{0,1,0},{0,0,1}, {1,1,1},{0,0,0}};
//    vveci board = {{1,1},{1,0}};

    Solution solution;
    solution.gameOfLife(board);

    for (auto& row : board) {
        for ( auto& cell : row) {
            cout << cell << ", ";
        }
        cout << endl;
    }

    return 0;
}