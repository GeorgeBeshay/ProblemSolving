/*
 * Created By George on 1/26/2024.
 */

/*
 * Problem Link:
 * Problem Status:
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // nums1 pointer
        int j = n - 1;      // nums2 pointer
        int k = m + n - 1;

        while (j >= 0) {

            if (i >= 0 && (nums1[i] >= nums2[j]) ) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;

        }
    }

};

int main() {

    veci v1 = {1, 5, 7, 0, 0, 0};
    veci v2 = {2, 6, 9};

    Solution solution;
    solution.merge(v1, 3, v2, 3);

    for (int i = 0 ; i < 6 ; i++) {
        cout << v1[i] << " ";
    }

    return 0;
}