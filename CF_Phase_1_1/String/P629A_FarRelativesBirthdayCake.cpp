/*
 * Created By George on 3/4/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/629/A
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int n; cin >> n;
    ll ans = 0;
    vector<string> cake(n);ffor(i, n){cin >> cake[i];}
    ffor(i, n){
        int temp = 0;
        ffor(j, n){
            if(cake[i][j] == 'C')
                temp++;
        }
        ans += (temp*(temp-1)) / 2;
        temp = 0;
        ffor(j, n){
            if(cake[j][i] == 'C')
                temp++;
        }
        ans += (temp*(temp-1)) / 2;
    }
    cout << ans << endl;
    // ---------------- Separator ----------------    
    return 0;
}