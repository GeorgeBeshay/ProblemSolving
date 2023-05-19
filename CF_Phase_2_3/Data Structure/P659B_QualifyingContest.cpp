/*
 * Created By George on 5/19/23.
 */

/*
 * Problem Link:    https://codeforces.com/problemset/problem/659/B
 * Problem Status:  Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int n, m, region, score;
    string surname;
    cin >> n >> m;
    vector<vector<pair<int, string>>> data(m);
    while(n--){
        cin >> surname >> region >> score;
        data[region-1].emplace_back(score, surname);
    }
    // ---------------- Separator ----------------
    for(int i = 0 ; i < m ; i++)
        sort(data[i].rbegin(), data[i].rend());
    // ---------------- Separator ----------------
    for(auto V : data)
        cout << ((V.size() == 2 || V[2].first < V[1].first) ? V[0].second + " " + V[1].second: "?") << endl;
    // ---------------- Separator ----------------
    return 0;
}