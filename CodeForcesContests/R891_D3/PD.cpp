/*
 * Created By George on 9/14/2023.
 */

/*
 * Problem Link:        https://codeforces.com/contest/1857/problem/D
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {

    int t, n, maxNum;
    cin >> t;
    while(t--){
        cin >> n;
        veci a(n), b(n), c(n);
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        for(int i = 0 ; i < n ; i++)
            cin >> b[i];
        for(int i = 0 ; i < n ; i++)        // condition was Au - Av >= Bu - Bv -> Au - Bu >= Av - Bv
            c[i] = a[i] - b[i];
        veci strongVertices;
        maxNum = c[0];
        strongVertices.push_back(0);
        for(int i = 1 ; i < n ; i++) {
            if (c[i] == maxNum)
                strongVertices.push_back(i);
            else if (c[i] > maxNum) {
                maxNum = c[i];
                strongVertices.clear();
                strongVertices.push_back(i);
            }
        }
        cout << strongVertices.size() << endl;
        for(int v : strongVertices)
            cout << v + 1 << " ";
        cout << endl;
    }

    return 0;
}