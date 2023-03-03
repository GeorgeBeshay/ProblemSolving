/*
 * Created By George on 3/2/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/1800/problem/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <cctype>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;
#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


bool isUpper(char c);
int solve(string s, int k);

int main() {
    // ---------------- Separator ----------------
    int t, n, k;
    string in;
    cin >> t;
    while(t--){
        cin >> n >> k >> in;
        cout << solve(in, k) << endl;
    }
    // ---------------- Separator ----------------    
    return 0;
}

int solve(string s, int k){
    int ans = 0, index;
    vector<pr> vec(26);
    for(char c : s){
        index = int(tolower(c)) - 97;
        isUpper(c) ? vec[index].second++ : vec[index].first++;
    }
    for(int i = 0 ; i < 26 ; i++){
        ans += min(vec[i].first, vec[i].second);
        int diff = (max(vec[i].first, vec[i].second) - min(vec[i].first, vec[i].second));
        if(k > 0) {
            if (k >= diff / 2) {
                ans += diff / 2;
                k -= diff / 2;
            } else {
                ans += k;
                k = 0;
            }
        }
    }
    return ans;
}

bool isUpper(char c){
    if(c == ::toupper(c))
        return true;
    return false;
}