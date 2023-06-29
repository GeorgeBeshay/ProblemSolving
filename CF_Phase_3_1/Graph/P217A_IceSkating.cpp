/*
 * Created By George on 6/29/23.
 */

/*
 * Problem Link:            https://codeforces.com/contest/217/problem/A
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

class DisjointSet {
public:
    // Constructor
    DisjointSet(int size) {

        // Initially, each element is its own parent and has rank 0
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    // Union two sets by rank
    void unionSets(int i, int j) {
        parent[findSet(i)] = parent[findSet(j)];
    }

    // Find the representative (root) of the set that i belongs to
    int findSet(int i) {
        if (i != parent[i])
            parent[i] = findSet(parent[i]); // Path compression

        return parent[i];
    }

private:
    int parent[1001];
};

int main() {
    // ---------------- Separator ----------------
    // # new points needed = # of SCC - 1
    int n, count = 0;
    cin >> n;
    vector<pr> points(n);
    veci rows(n);

    for(int i = 0 ; i < n ; i++) {
        cin >> points[i].first >> points[i].second;
        rows[i] = points[i].first;
    }

    DisjointSet unionFind = DisjointSet(1001);
    for(int i = 0 ; i < n - 1 ; i++)
        for(int j = i + 1 ; j < n ; j++)
            if (points[j].second == points[i].second)
                unionFind.unionSets(points[i].first, points[j].first);

    map<int, bool> checked;
    for(int i = 0 ; i < n ; i++)
        if(unionFind.findSet(rows[i]) == rows[i] && !checked[rows[i]]){
            count++;
            checked[rows[i]] = true;
        }

    cout << count - 1 << endl;
    // ---------------- Separator ----------------    
    return 0;
}