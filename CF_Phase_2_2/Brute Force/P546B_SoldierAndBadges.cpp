/*
 * Created By George on 3/9/23.
 */

/*
 * Problem Link:    https://codeforces.com/problemset/problem/546/B
 * Problem Status:  Accepted.
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
    map<int, int> frequency, extra;
    int n, answer = 0;cin >> n;veci in(n), missing;ffor(i, n){cin >> in[i];frequency[in[i]]++;}
    sort(in.begin(), in.end());
    // ---------------- Separator ----------------
    for(auto I : frequency){
        if(I.second > 1) {
            frequency[I.first + 1] += I.second - 1;
            answer += I.second - 1;
            I.second = 1;
        }
    }
    // ---------------- Separator ----------------
    cout << answer << endl;
    return 0;
}