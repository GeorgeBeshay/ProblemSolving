/*
 * Created By George on 3/2/23.
 */

/*
 * Problem Link:            https://codeforces.com/contest/1800/problem/A
 * Problem Status:          Accepted.
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

bool check(string s);
int main() {
    // ---------------- Separator ----------------
    int t, n;
    string in;
    cin >> t;
    while(t--){
        cin >> n >> in;
        if(check(in))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    // ---------------- Separator ----------------    
    return 0;
}

bool check(string s){
    bool m = false, e = false, o = false, w = false;
    ffor(i, s.size()){
        if(s[i] == 'm' || s[i] == 'M'){
            if(e || o || w)
                return false;
            m = true;
        } else if(s[i] == 'e' || s[i] == 'E'){
            if(!m || o || w)
                return false;
            e = true;
        } else if(s[i] == 'o' || s[i] == 'O'){
            if(!m || !e || w)
                return false;
            o = true;
        } else if(s[i] == 'w' || s[i] == 'W'){
            if(!m || !e || !o)
                return false;
            w = true;
        } else
            return false;
    }
    if(m && e && o && w)
        return true;
    return false;
}