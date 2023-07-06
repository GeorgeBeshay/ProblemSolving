/*
 * Created By George on 7/6/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/687/problem/A
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

int main() {

    int n, m, tmp1, tmp2;
    cin >> n >> m;
    bool visited[n], impossible = false;
    int color[n];
    for(int i = 0 ; i < n ; i++){
        color[i] = 0;
        visited[i] = false;
    }
    vector<vector<int>> adjList(n);
    vector<int> set1;
    vector<int> set2;

    for(int i = 0 ; i < m ; i++){
        cin >> tmp1 >> tmp2;
        tmp1--;tmp2--;
        adjList[tmp1].push_back(tmp2);
        adjList[tmp2].push_back(tmp1);
    }

    for(int i = 0 ; i < n ; i++){
        if(adjList[i].empty() || visited[i])
            continue;
        queue<int> q;
        q.push(i);
        color[i] = 1;
        while(!q.empty()){
            int x = q.front();
            visited[x] = true;
            q.pop();
            for(int adj : adjList[x]){
                if(color[x] == color[adj]){
                    impossible = true;
                    break;
                }
                if(color[adj] == 0) {
                    color[adj] = (color[x] == 1) ? 2 : 1;
                    q.push(adj);
                }
            }
            if(impossible)
                break;
        }
        if(impossible)
            break;
    }

    if(impossible){
        cout << -1 << endl;
        exit(0);
    }

    for(int i = 0 ; i < n ; i++){
        if(color[i] == 1)
            set1.push_back(i+1);
        else if(color[i] == 2)
            set2.push_back(i+1);
    }

    cout << set1.size() << endl;
    for(auto x : set1)
        cout << x << " ";
    cout << endl << set2.size() << endl;
    for(auto x : set2)
        cout << x << " ";
    cout << endl;


    return 0;
}