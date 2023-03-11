/*
 * Created By George on 3/11/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/931/B
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
    int n, a, b, ans = 1;
    cin >> n >> a >> b;
    a--;b--;
    while(a / 2 != b / 2) {
        ans++;
        a /= 2;
        b /= 2;
    }
    if(ans == log(n) / log(2))
        cout << "Final!" << endl;
    else
        cout << ans << endl;
    // ---------------- Separator ----------------
    return 0;
}