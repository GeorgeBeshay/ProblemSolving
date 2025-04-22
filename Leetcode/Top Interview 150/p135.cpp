/*
 * Created By George on 10/1/2024.
 */

/*
 * Problem Link:            https://leetcode.com/problems/candy/
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

    bool isMin(veci& v, int idx) {
        if (v.size() == 1) {
            return true;
        }
        if (idx == 0) {
            return v[0] <= v[1];
        }
        if (idx == v.size() - 1) {
            return v[v.size() - 1] <= v[v.size() - 2];
        }
        return v[idx] <= v[idx - 1] && v[idx] <= v[idx + 1];
    }

    int candy(vector<int>& ratings) {
        int ans = 0;

        veci candy(ratings.size(), 1);

        for (int i = 0 ; i < ratings.size() ; i++) {
            if (i > 0 && ratings[i] > ratings[i-1] && candy[i] <= candy[i-1]) {
                candy[i] = candy[i-1] + 1;
            }
        }
        for (int i = (int) ratings.size() - 1 ; i >= 0 ; i--) {
            if (i < ratings.size() - 1 && ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]) {
                candy[i] = candy[i+1] + 1;
            }
            ans += candy[i];
        }

        return ans;
    }
};

int main() {


    return 0;
}