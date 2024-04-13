/*
 * Created By George on 4/12/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/valid-sudoku/?envType=study-plan-v2&envId=top-interview-150
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
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0 ; i < 9 ; i++) {
            // check rows
            map<char, bool> tempOccurrence;
            for (int j = 0 ; j < 9 ; j++) {
                if (board[i][j] != '.' && tempOccurrence[board[i][j]])
                    return false;
                else
                    tempOccurrence[board[i][j]] = true;
            }

            // check cols
            tempOccurrence.clear();
            for (int j = 0 ; j < 9 ; j++) {
                if (board[j][i] != '.' && tempOccurrence[board[j][i]])
                    return false;
                else
                    tempOccurrence[board[j][i]] = true;
            }

            // check boxes
            tempOccurrence.clear();
            int row = (i / 3) * 3;
            int col = (i % 3) * 3;
            for (int k = row ; k < row + 3 ; k++) {
                for (int m = col ; m < col + 3 ; m++) {
                    if (board[k][m] != '.' && tempOccurrence[board[k][m]])
                        return false;
                    else
                        tempOccurrence[board[k][m]] = true;
                }
            }

        }
        return true;
    }
};

int main() {


    return 0;
}