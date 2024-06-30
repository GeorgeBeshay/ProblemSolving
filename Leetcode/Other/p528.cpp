/*
 * Created By George on 4/18/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/random-pick-with-weight/
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>
#include <random>

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
    veci weights;
    vector<vector<double>> normalized_sorted;
    ll requestsCount = 0;

    Solution(vector<int>& w) {
        weights = w;
        prepare();
    }

    int pickIndex() {
        requestsCount++;

        for (int i = 0 ; i < normalized_sorted.size() ; i++) {
            ll shouldAppear = floor(normalized_sorted[i][0] * requestsCount);
            ll actualAppearance = normalized_sorted[i][2];
            if (shouldAppear > actualAppearance) {
                normalized_sorted[i][2]++;
                return normalized_sorted[i][1];
            }
        }
        normalized_sorted[normalized_sorted.size() - 1][2]++;
        return normalized_sorted[normalized_sorted.size() - 1][1];
    }

    void prepare() {
        ll sum = getSum();
        for (int i = 0 ; i < weights.size() ; i++) {
            normalized_sorted.push_back({ (double) weights[i] / sum, (double) i, (double) 0 });
        }

        // sort based on the first element
        auto compare = [](const std::vector<double>& a, const std::vector<double>& b) {
            return a[0] < b[0];
        };
        sort(normalized_sorted.begin(), normalized_sorted.end(), compare);
    }

    ll getSum() {
        ll ans = 0;
        for (int x : weights)
            ans += x;
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main() {

    veci v = {3, 14, 1, 7};
    Solution* obj = new Solution(v);

    for (int i = 0 ; i < 20 ; i++)
        cout << obj->pickIndex() << endl;

    return 0;
}