/*
 * Created By George on 9/18/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/516/problem/A
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

int main() {

    map<char, veci> map = {
            {'2', {2}},
            {'3', {3}},
            {'4', {2, 2, 3}},
            {'5', {5}},
            {'6', {3, 5}},
            {'7', {7}},
            {'8', {2, 2, 2, 7}},
            {'9', {2, 3, 3, 7}}
    };

    int n;
    string s;
    veci ans;
    cin >> n;
    cin >> s;
    for(char c : s)
        if(c != '0' && c != '1') {
            veci tmp = map[c];
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for(int x : ans)
        cout << x;
    cout << endl;
    return 0;
}