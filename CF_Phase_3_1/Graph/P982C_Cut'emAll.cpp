/*
 * Created By George on 7/7/23.
 */

/*
 * Problem Link:            https://codeforces.com/contest/982/problem/C
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

int dfs(int node, vector<vector<int>>& adjList, bool* visited, int& answer);

int main() {

    int n, answer = 0, tmp1, tmp2, nodesCount = 0;
    cin >> n;
    vector<vector<int>> adjList(n);
    bool visited[n];
    visited[n-1] = false;

    for(int i = 0 ; i < n-1 ; i++){
        cin >> tmp1 >> tmp2;
        tmp1--;tmp2--;
        adjList[tmp1].push_back(tmp2);
        adjList[tmp2].push_back(tmp1);
        visited[i] = false;
    }

    if(n % 2 == 1){
        cout << -1 << endl;
        exit(0);
    }

    dfs(0, adjList, visited, answer);
    cout << answer << endl;

    return 0;
}

int dfs(int node, vector<vector<int>>& adjList, bool* visited, int& answer){

    visited[node] = true;

    int subtreesSize = 0;
    int tempSubtreeSize;

    for(int adjNode : adjList[node])
        if(!visited[adjNode]) {
            tempSubtreeSize = dfs(adjNode, adjList, visited, answer);
            if(tempSubtreeSize % 2 == 0)
                answer++;
            subtreesSize += tempSubtreeSize;
        }

    return subtreesSize+1;
}