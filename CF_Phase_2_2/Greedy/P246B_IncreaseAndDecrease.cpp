/*
 * Created By George on 2/28/23.
 */

/*
 * Problem Link:    https://codeforces.com/problemset/problem/246/B
 * Problem Status:  Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;
#define loop(loopVar, upTo) for(int loopVar = 0 ; loopVar < upTo ; loopVar++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int n;
    cin >> n;veci input(n);loop(i, n){cin >> input[i];}
    sort(input.begin(), input.end());
    // ---------------- Separator ----------------
    for(int i = 1 ; i < n-1 ; i++) {
        input[n - 1] += input[i] - input[0];
        input[i] = input[0];
    }
    if( (input[n-1] - input[0]) % n == 0)
        cout << n << endl;
    else
        cout << n-1 << endl;
    // ---------------- Separator ----------------
    return 0;
}