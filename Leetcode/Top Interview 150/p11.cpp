/*
 * Created By George on 4/11/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150
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
    int maxArea(vector<int>& height) {
        int p1 = 0;
        int p2 = height.size() - 1;
        int currentMaxArea = 0;
        int tempArea = 0;

        while (p1 < p2) {
            tempArea = (p2 - p1) * min(height[p1], height[p2]);
            if (tempArea > currentMaxArea)
                currentMaxArea = tempArea;
            if (height[p1] <= height[p2])
                p1++;
            else
                p2--;
        }

        return currentMaxArea;
    }
};

int main() {


    return 0;
}