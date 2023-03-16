/*
 * Created By George on 3/15/23.
 */

/*
 * Problem Link:            https://codeforces.com/problemset/problem/1011/B
 * Problem Status:          Accepted.
 */

#include <iostream>
#include <iomanip>
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
    int n, m, tempType, maxFreq = 0, ans = 0;
    cin >> n >> m;
    map<int, int> typeToFreq;
    map<int, veci> freqToType;
    veci answers, in(m);
    // ---------------- Separator ----------------
    ffor(i, m){
        cin >> tempType;
        in[i] = tempType;
        typeToFreq[tempType]++;
        freqToType[typeToFreq[tempType]].push_back(tempType);
        if(typeToFreq[tempType] > maxFreq)
            maxFreq = typeToFreq[tempType];
    }
    // ---------------- Separator ----------------
    for(int i = 1 ; i <= maxFreq ; i++){
        int tempCount = 0;
        for(auto I : typeToFreq){
            tempCount += (I.second) / i;
        }
        if(i > ans && tempCount >= n)
            ans = i;
    }
    // ---------------- Separator ----------------
    cout << ans << endl;
    // ---------------- Separator ----------------
    return 0;
}