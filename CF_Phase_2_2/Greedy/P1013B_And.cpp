/*
 * Created By George on 2/21/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/1013/B
 * Problem Status:      Accepted.
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
    int n, x;
    bool good = false, good2 = false;
    cin >> n >> x;
    veci input(n);
    map<int, int> m;
    map<int, int> m2;
    loop(i, n){
        cin >> input[i];
        m[input[i]]++;
        if(m[input[i]] > 1)
            good = true;
        m2[input[i] & x]++;
        if(m2[input[i] & x] > 1)
            good2 = true;
    }
    // ---------------- Separator ----------------
    if(good){
        cout << 0 << endl;
        exit(0);
    }
    // ---------------- Separator ----------------
    loop(i, n){
        if(m[input[i] & x] > 0 && input[i] != (input[i] & x)){
            cout << 1 << endl;
            exit(0);
        }
    }
    if(good2){
        cout << 2 << endl;
        exit(0);
    }
    // ---------------- Separator ----------------
    cout << -1 << endl;
    // ---------------- Separator ----------------
    return 0;
}