/*
 * Created By George on 7/4/23.
 */

/*
 * Problem Link:            https://codeforces.com/contest/108/problem/C
 * Problem Status:          Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> veci;
typedef vector<vector<ll>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_DIAMETER 1000001

void dfs(vector<vector<pr>>& adjList, map<int, pr>& answers, int start, int currentEnd, vector<bool>& visited, int currentBottleNeck);

int main() {

    int n, p, a, b, d, tmp;
    cin >> n >> p;

    vector<vector<pr>> adjList(n);
    map<int, pr> tmp_answers, answers;       // {to, {from, diameter}}
    vector<bool> visited(n, false);

    while(p--){
        cin >> a >> b >> d;
        adjList[--a].emplace_back(--b, d);
    }

    for(int i = 0 ; i < n ; i++){
        if(!visited[i] && !adjList[i].empty())
            dfs(adjList, tmp_answers, i, i, visited, MAX_DIAMETER);
    }
    for(auto it : tmp_answers)
        answers[it.second.first] = {it.first, it.second.second};

    cout << answers.size() << endl;
    for(auto it : answers)
        cout << it.first + 1 << " " << it.second.first + 1 << " " << it.second.second << endl;


    return 0;
}

void dfs(vector<vector<pr>>& adjList, map<int, pr>& answers, int start, int currentEnd, vector<bool>& visited, int currentBottleNeck){
        visited[currentEnd] = true;

        if(adjList[currentEnd].empty())
            answers[currentEnd] = {start, currentBottleNeck};

        for(pr toGo : adjList[currentEnd]){
            if(toGo.first != start){
                if(toGo.second < currentBottleNeck)
                    currentBottleNeck = toGo.second;
                dfs(adjList, answers, start, toGo.first, visited, currentBottleNeck);
            } else
                return;
        }
}