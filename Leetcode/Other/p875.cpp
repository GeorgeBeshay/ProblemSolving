/*
 * Created By George on 4/17/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/koko-eating-bananas/description/
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
#define MAX_LONG numeric_limits<long long>::max()

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll min = ceil(sum(piles) / double(h));
        ll max = maxOfVector(piles);
        ll mid = min;
        ll tempNeededHours;
        while (min <= max) {
            mid = (min + max) / 2;
            tempNeededHours = computeHoursNeeded(piles, mid);
            if (tempNeededHours <= h && computeHoursNeeded(piles, mid-1) > h)
                return mid;
            else {
                if (tempNeededHours <= h)
                    max = mid - 1;
                else
                    min = mid + 1;
            }
        }
        return mid;
    }

    static ll sum(veci v) {
        ll sum = 0;
        for (int x : v)
            sum += x;
        return sum;
    }

    static ll maxOfVector(veci v) {
        ll currentMax = -1;
        for (int x : v)
            if (x > currentMax)
                currentMax = x;
        return currentMax;
    }

    static ll computeHoursNeeded(veci& piles, int k) {
        if (k == 0)
            return MAX_LONG;

        ll currentHours = 0;

        for (int pile : piles)
            currentHours += ceil(pile / double(k));

        return currentHours;
    }
};

int main() {

    Solution solution;
    veci piles = {312884470};
    int h = 968709470;
    cout << solution.minEatingSpeed(piles, h);

    return 0;
}