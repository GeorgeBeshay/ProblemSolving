/*
 * Created By George on 3/5/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/378/B
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

string repeatChar(char c, int x);

int main() {
    // ---------------- Separator ----------------
    ll n, temp1, temp2, k = 0;
    cin >> n;
    string s1Ans = repeatChar('0', n), s2Ans = repeatChar('0', n);
    map<ll, pr> m;
    ffor(i, n){
        cin >> temp1 >> temp2;
        m[temp1] = make_pair(0, i);
        m[temp2] = make_pair(1, i);
    }
    temp1 = 0;
    for(auto I : m){
        if(I.second.first == 0)
            s1Ans[I.second.second] = '1';
        else
            s2Ans[I.second.second] = '1';
        temp1++;
        if(temp1 >= n)
            break;
    }
    ffor(i, n/2){s1Ans[i] = '1';s2Ans[i] = '1';}
    cout << s1Ans << endl << s2Ans << endl;
    // ---------------- Separator ----------------
    return 0;
}

string repeatChar(char c, int x){
    string ans = "";
    while(x--){
        ans += c;
    }
    return ans;
}