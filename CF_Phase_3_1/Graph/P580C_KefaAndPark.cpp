/*
 * Created By George on 7/6/23.
 */

/*
 * Problem Link:            https://codeforces.com/contest/580/problem/C
 * Problem Status:          Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> veci;
typedef vector<vector<ll>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void dfs(int node, vector<vector<int>>& adjList, bool* visited, const bool* hasCat, int m, int catsCount, int& ans);

int main() {

    int n, m, tmp1, tmp2, ans = 0;       // n is the number of vertices 1 -> n, m is the maximum # of consecutive cats
    cin >> n >> m;
    bool hasCat[n];
    bool visited[n];
    vector<vector<int>> adjList(n);

    for(int i = 0 ; i < n ; i++) {
        cin >> hasCat[i];
        visited[i] = false;
    }

    for(int i = 0 ; i < n-1 ; i++) {
        cin >> tmp1 >> tmp2;
        adjList[tmp1-1].push_back(tmp2-1);
        adjList[tmp2-1].push_back(tmp1-1);
    }

    dfs(0, adjList, visited, hasCat, m, 0, ans);

    cout << ans << endl;

    return 0;
}

void dfs(int node, vector<vector<int>>& adjList, bool* visited, const bool* hasCat, int m, int catsCount, int& ans){

    visited[node] = true;

    if(hasCat[node])
        catsCount++;
    else
        catsCount = 0;

    if(catsCount > m)
        return;

    if(adjList[node].size() == 1 && node != 0)
        ans++;

    for(int childNode : adjList[node])
        if(!visited[childNode])
            dfs(childNode, adjList, visited, hasCat, m, catsCount, ans);
}