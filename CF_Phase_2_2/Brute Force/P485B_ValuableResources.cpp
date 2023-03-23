/*
 * Created By George on 3/23/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/485/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    ll area;
    int n;
    cin >> n;
    vector<ll> minesX(n), minesY(n);
    // ---------------- Separator ----------------
    ffor(i, n){cin >> minesX[i] >> minesY[i];}
    sort(minesX.begin(), minesX.end());
    sort(minesY.begin(), minesY.end());
    // ---------------- Separator ----------------
    area = max(minesX[n-1] - minesX[0], minesY[n-1] - minesY[0]);
    area *= area;
    cout << area << endl;
    // ---------------- Separator ----------------
    return 0;
}