/*
 * Created By George on 9/11/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/1860/problem/A
 * Problem Status:          Accepted.
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

int getCase(string s){
    if(s == "()")
        return 0;
    int ans = 1;        // ()()() alternating ..
    for(int i = 1 ; i < s.size() ; i++)
        if(s[i] == s[i-1]) {
            ans = 2;
            break;
        }
    return ans;
}

int main() {

    int t;
    string x;
    cin >> t;
    while(t--){
        cin >> x;
        switch (getCase(x)) {
            case 0:
                cout << "NO" << endl;
                break;
            case 1:
                cout << "YES" << endl;
                cout << string(x.size(), '(') + string(x.size(), ')') << endl;
                break;
            case 2:
                cout << "YES" << endl;
                for(int i = 0 ; i < x.size() ; i++)
                    cout << "()";
                cout << endl;
                break;
        }
    }
    return 0;
}