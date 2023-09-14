/*
 * Created By George on 9/13/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/1857/problem/C
 * Problem Status:          Accepted
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

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int b_size = (n * (n-1)) / 2;
        veci b(b_size);
        veci a(n, -1);
        vector<bool> changed(n, false);
        map<int, int> frequency;
        map<int, int> mapper;
        for(int i = 0 ; i < b_size ; i++) {
            cin >> b[i];
            frequency[b[i]]++;
        }
        for(int i = 0 ; i < n ; i++)
            mapper[n - i - 1] = i;
        for(auto p : frequency){
            while(mapper.count(p.second) == 0){
                a[mapper.crbegin()->second] = p.first;
                changed[mapper.crbegin()->second] = true;
                p.second -= mapper.crbegin()->first;
                mapper.erase(mapper.crbegin()->first);
            }
            if(mapper.count(p.second) > 0){
                a[mapper[p.second]] = p.first;
                changed[mapper[p.second]] = true;
                mapper.erase(p.second);
            }
        }
        for(int i = 0 ; i < n ; i++)
            cout << (changed[i] ? a[i] : 1000000000) << " ";
        cout << endl;
    }

    return 0;
}