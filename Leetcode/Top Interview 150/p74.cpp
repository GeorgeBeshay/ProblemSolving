/*
 * Created By George on 5/22/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/search-a-2d-matrix/
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = (matrix.size() * matrix[0].size()) - 1;
        int mid;
        veci tempIdx(2);

        while (left <= right) {
            mid = (left + right) / 2;
            tempIdx = {
                    mid / int(matrix[0].size()),
                    mid - (
                            (mid / int(matrix[0].size())) * int(matrix[0].size())
                            )
            };
            if (tempIdx[0] < 0 || tempIdx[1] < 0 || tempIdx[0] >= matrix.size() || tempIdx[1] >= matrix[0].size())
                break;
            if (matrix[tempIdx[0]][tempIdx[1]] == target)
                return true;
            if (matrix[tempIdx[0]][tempIdx[1]] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};

int main() {

//    vveci matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
//    int target = 13;
    vveci matrix = {{1, 3}};
    int target = 3;
    Solution solution;
    cout << solution.searchMatrix(matrix, target);

    return 0;
}