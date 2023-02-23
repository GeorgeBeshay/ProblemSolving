/*
 * Created By George on 2/23/23.
 */

/*
 * Problem Link:    https://codeforces.com/problemset/problem/872/B
 * Problem Status:  Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;
#define loop(loopVar, upTo) for(int loopVar = 0 ; loopVar < upTo ; loopVar++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int n, k;
    cin >> n >> k;
    veci input(n);
    loop(i, n){cin >> input[i];}
    pr extremes = make_pair(input[0], input[0]);
    // ---------------- Separator ----------------
    loop(i, n){
        if(input[i] < extremes.first)
            extremes.first = input[i];
        if(input[i] > extremes.second)
            extremes.second = input[i];
    }
    // ---------------- Separator ----------------
    if(k > 2)
        cout << extremes.second << endl;
    else if(k > 1)
        cout << max(input[0], input[n-1]) << endl;
    else
        cout << extremes.first << endl;
    // ---------------- Separator ----------------
    return 0;
}