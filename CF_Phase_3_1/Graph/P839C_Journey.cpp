/*
 * Created By George on 7/7/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/839/problem/C
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector<ll> veci;
typedef vector<vector<ll>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void dfs(int node, vector<vector<int>>& adjList, bool* visited, double& answer, double currentProbability, double currentLength);

int main() {

    int n, tmp1, tmp2;          // n is the number of nodes, tmp1 and tmp2 to scan the nodes of the edge
    double answer = 0;
    cin >> n;
    vector<vector<int>> adjList(n);
    bool visited[n];
    visited[n-1] = false;

    for(int i = 0 ; i < n - 1 ; i++){
        cin >> tmp1 >> tmp2;
        tmp1--;tmp2--;
        adjList[tmp1].push_back(tmp2);
        adjList[tmp2].push_back(tmp1);
        visited[i] = false;
    }

    dfs(0, adjList, visited, answer, 1, 0);

    cout << fixed << setprecision(20) << answer << endl;

    return 0;
}

void dfs(int node, vector<vector<int>>& adjList, bool* visited, double& answer, double currentProbability, double currentLength){

    if(adjList[node].size() <= 1)
        answer += currentLength * currentProbability;

    visited[node] = true;
    currentLength++;
    if(node != 0)
        currentProbability /= (adjList[node].size() - 1);
    else
        currentProbability /= adjList[node].size();

    for(int adjNode : adjList[node])
        if(!visited[adjNode])
            dfs(adjNode, adjList, visited, answer, currentProbability, currentLength);
}