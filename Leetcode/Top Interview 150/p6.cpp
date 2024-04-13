/*
 * Created By George on 4/11/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/zigzag-conversion/?envType=study-plan-v2&envId=top-interview-150
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
    string convert(string s, int numRows) {

        // to get the number of columns
        int remainingChars = s.size();
        int columnsCount = 0;
        int zigzagCount = 0;
        while (remainingChars > 0) {
            if (zigzagCount == 0) {
                remainingChars -= numRows;
                if (numRows > 2)
                zigzagCount = 1;
            } else {
                remainingChars -= 1;
                if (zigzagCount == numRows - 2)
                    zigzagCount = 0;
                else
                    zigzagCount++;
            }
            columnsCount++;
        }

        char arr[numRows][columnsCount];
        for (int i = 0 ; i < numRows ; i++)
            for (int j = 0 ; j < columnsCount ; j++)
                arr[i][j] = ' ';

        int currentRow = 0;
        int currentCol = 0;
        zigzagCount = 0;
        for (char c : s) {
            arr[currentRow][currentCol] = c;
            if (zigzagCount == 0) {
                if (currentRow == numRows - 1) {
                    currentCol++;
                    if (currentRow > 0)
                        currentRow--;
                    if (numRows > 2)
                        zigzagCount = 1;
                } else
                    currentRow++;
            } else {
                if (zigzagCount == numRows - 2) {
                    zigzagCount = 0;
                } else
                    zigzagCount++;
                if (currentRow > 0)
                    currentRow--;
                currentCol++;

            }
        }

        string ans = "";

        for (int i = 0 ; i < numRows ; i++) {
            for (int j = 0 ; j < columnsCount ; j++) {
//                cout << arr[i][j];
                if (arr[i][j] != ' ')
                    ans += arr[i][j];
            }
//            cout << endl;
        }

        return ans;

    }
};

int main() {
    string s = "ABCD";
    Solution solution;
    cout << solution.convert(s, 2);

    return 0;
}