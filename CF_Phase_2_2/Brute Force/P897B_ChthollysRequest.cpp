/*
 * Created By George on 3/25/23.
 */

/*
 * Problem Link:            https://codeforces.com/problemset/problem/897/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main() {
    // ---------------- Separator ----------------
    ll ans = 0, p, k, temp = 1;
    cin >> k >> p;
    // ---------------- Separator ----------------
    while(k--){
        string tempAns = to_string(temp);
        string tempS = to_string(temp);
        reverse(tempS.begin(), tempS.end());
        tempAns.append(tempS);
        ans += stoll(tempAns);
        temp++;
    }
    // ---------------- Separator ----------------
    cout << ans % p << endl;
    // ---------------- Separator ----------------
    return 0;
}