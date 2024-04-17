/*
 * Created By George on 4/14/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
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
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = points.size();
        sort(points.begin(), points.end());
        veci currentBoundaries = points[0];
        for (int i = 1 ; i < points.size() ; i++)
            if (points[i][0] <= currentBoundaries[1] && points[i][0] >= currentBoundaries[0]) {
                ans--;
                currentBoundaries[0] = points[i][0];
                currentBoundaries[1] = min(currentBoundaries[1], points[i][1]);
            }
            else
                currentBoundaries = points[i];

        return ans;
    }
};

int main() {


    return 0;
}