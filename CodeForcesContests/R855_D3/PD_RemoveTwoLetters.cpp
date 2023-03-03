/*
 * Created By George on 3/2/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/1800/problem/D
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;
#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int solve(string s);

int main() {
    // ---------------- Separator ----------------
    int t, n;
    string in;
    cin >> t;
    while(t--){
        cin >> n >> in;
        cout << solve(in) << endl;
    }
    // ---------------- Separator ----------------    
    return 0;
}

int solve(string s){
    int skip = 0;
    for(int i = 2 ; i < s.size() ; i++){
        if(s[i] == s[i-2])
            skip++;
    }
    return s.length() - 1 - skip;
}