/*
 * Created By George on 4/15/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/515/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int n, m, tempCount, tempIdx;
    cin >> n >> m;
    veci boys(n, 0), girls(m, 0);
    cin >> tempCount;
    while(tempCount--){
        cin >> tempIdx;
        boys[tempIdx] = 1;
    }
    cin >> tempCount;
    while(tempCount--){
        cin >> tempIdx;
        girls[tempIdx] = 1;
    }
    // ---------------- Separator ----------------
    for(int i = 0 ; i < 100 * max(n, m) ; i++){
        if(boys[i % n] == 1 || girls[i % m] == 1){
            boys[i % n] = 1;
            girls[i % m] = 1;
        }
    }
    // ---------------- Separator ----------------
    for(int i = 0 ; i < max(n, m) ; i++){
        if(boys[i % n ] == 0 || girls[i % m] == 0){
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
    // ---------------- Separator ----------------
    return 0;
}