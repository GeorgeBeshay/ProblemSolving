/*
 * Created By George on 6/30/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/429/problem/A
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

void dfs_and_solve(vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& answers, int* current, int* goal, int node, int level, int odd_c, int even_c);

int main() {

    int n, u, v;
    cin >> n;
    vector<vector<int>> adjList(n, vector<int>());
    vector<bool> visited(n, false);
    vector<int> answers;
    int* init = new int[n];
    int* goal = new int[n];

    for(int i = 0 ; i < n - 1 ; i++){
        cin >> u >> v;
        u--;v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i = 0 ; i < n ; i++)
        cin >> init[i];
    for(int i = 0 ; i < n ; i++)
        cin >> goal[i];

    dfs_and_solve(adjList, visited, answers, init, goal, 0, 0, 0, 0);

    cout << answers.size() << endl;
    for(int x : answers)
        cout << x << endl;


    return 0;
}

void dfs_and_solve(vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& answers, int* current, int* goal, int node, int level, int odd_c, int even_c){

    bool flip = (level % 2 == 0) ? even_c % 2 : odd_c % 2;
    int changed = 0;

    if((current[node] == goal[node] && flip)|| (!flip && current[node] != goal[node])){
        current[node] = goal[node];
        answers.push_back(node + 1);
        if(level % 2 == 0) {
            even_c++;
            changed = 1;
        }
        else {
            odd_c++;
            changed = 2;
        }
    }

    level++;
    visited[node] = true;
    for(int x : adjList[node]){
        if(!visited[x])
            dfs_and_solve(adjList, visited, answers, current, goal, x, level, odd_c, even_c);
    }

    if(changed == 1)
        even_c--;
    else if(changed == 2)
        odd_c--;
}