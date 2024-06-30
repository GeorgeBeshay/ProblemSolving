/*
 * Created By George on 4/19/2024.
 */

/*
 * Problem Link:            https://leetcode.com/problems/insert-interval/
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vveci newIntervals;

        for (veci oldInterval : intervals) {
            if (oldInterval[0] > newInterval[0]) {
                insertNewInterval(newIntervals, newInterval);
                newInterval[0] = MAX_INT;
            }
            insertNewInterval(newIntervals, oldInterval);
        }
        if (newInterval[0] != MAX_INT)
            insertNewInterval(newIntervals, newInterval);

        return newIntervals;
    }

    void insertNewInterval(vveci& intervals, veci& intervalToInsert) {
        if (intervals.empty() || intervalToInsert[0] > intervals[intervals.size() - 1][1])
            intervals.push_back(intervalToInsert);
        else {
            intervals[intervals.size() - 1][0] = min(intervals[intervals.size() - 1][0], intervalToInsert[0]);
            intervals[intervals.size() - 1][1] = max(intervals[intervals.size() - 1][1], intervalToInsert[1]);
        }
    }
};

int main() {


    return 0;
}