/*
 * Created By George on 4/14/23.
 */

/*
 * Problem Link:            https://codeforces.com/problemset/problem/707/B
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
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_DIST 1000000001

int main() {
    // ---------------- Separator ----------------
    ll n, m, k, from, to, weight, temp_storage, ans = MAX_DIST;    // number of cities, number of roads, number of flour supplies.
    cin >> n >> m >> k;
    map<ll, vector<pr>> adjacency_list;    // [from -> [(to, weight), ..]]
    map<ll, bool> flour_supplies;
    vector<ll> answers(n, MAX_DIST);
    ffor(i, m){
        cin >> from >> to >> weight;
        adjacency_list[from].emplace_back(to, weight);
        adjacency_list[to].emplace_back(from, weight);
    }
    ffor(i, k){cin >> temp_storage; flour_supplies[temp_storage] = true;}
    // ---------------- Separator ----------------
    for(auto I : flour_supplies){
        if(!I.second)
            continue;
        for(auto J : adjacency_list[I.first])
            if(!flour_supplies[J.first] && J.second < ans)
                ans = J.second;
    }
    if(ans == MAX_DIST)
        ans = -1;
    cout << ans;
    // ---------------- Separator ----------------
    return 0;
}
