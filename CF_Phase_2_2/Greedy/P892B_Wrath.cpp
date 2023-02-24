/*
 * Created By George on 2/24/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/892/B
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
    int n, ans = 0, killUpTo = 0;
    cin >> n;
    veci input(n);
    loop(i, n){cin >> input[i];}
    // ---------------- Separator ----------------
    for(int i = n-1 ; i >= 0 ; i--){
        if(killUpTo > 0){
            killUpTo--;
            if(input[i] > killUpTo)
                killUpTo = input[i];
        } else {
            ans++;
            killUpTo = input[i];
        }
    }
    // ---------------- Separator ----------------
    cout << ans << endl;
    // ---------------- Separator ----------------
    return 0;
}