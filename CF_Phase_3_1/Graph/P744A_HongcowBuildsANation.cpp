/*
 * Created By George on 7/6/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/744/problem/A
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> veci;
typedef vector<vector<ll>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void dfs(vector<vector<int>>& adjList, int* componentsSize, int node, int currentComponent, bool* visited);

int main() {

    int n, m, k, tmp1, tmp2, componentNumber = 0, maxEdges = 0, maxCompSizeAt = 0, compNodesSum = 0;
    cin >> n >> m >> k;

    bool isGovernmentHome[n], visited[n];
    vector<vector<int>> adjList(n);
    int componentsSize[k];

    for(int i = 0 ; i < n ; i++) {
        isGovernmentHome[i] = false;
        visited[i] = false;
    }

    for(int i = 0 ; i < k ; i++){
        cin >> tmp1;
        isGovernmentHome[tmp1-1] = true;
        componentsSize[i] = 0;
    }

    for(int i = 0 ; i < m ; i++){
        cin >> tmp1 >> tmp2;
        tmp1--;tmp2--;
        adjList[tmp1].push_back(tmp2);
        adjList[tmp2].push_back(tmp1);
    }

    for(int i = 0 ; i < n ; i++)
        if(isGovernmentHome[i]) {
            dfs(adjList, componentsSize, i, componentNumber, visited);
            componentNumber++;
        }

    for(int i = 0 ; i < k ; i++) {
        if (componentsSize[i] > componentsSize[maxCompSizeAt])
            maxCompSizeAt = i;
        compNodesSum += componentsSize[i];
    }
    componentsSize[maxCompSizeAt] += n - compNodesSum;


    for(int i = 0 ; i < k ; i++)
        maxEdges += (componentsSize[i] * (componentsSize[i] - 1)) / 2;

    cout << maxEdges - m << endl;

    return 0;
}

void dfs(vector<vector<int>>& adjList, int* componentsSize, int node, int currentComponent, bool* visited){
    visited[node] = true;
    componentsSize[currentComponent]++;
    for(int adj : adjList[node]){
        if(!visited[adj])
            dfs(adjList, componentsSize, adj, currentComponent, visited);
    }
}