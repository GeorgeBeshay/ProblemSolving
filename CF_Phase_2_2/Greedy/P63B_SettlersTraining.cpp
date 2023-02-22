/*
 * Created By George on 2/22/23.
 */

/*
 * Problem Link:    https://codeforces.com/problemset/problem/63/B
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

bool check(veci input, int k);

int main() {
    // ---------------- Separator ----------------
    int n, k, coins = 0;
    cin >> n >> k;
    veci input(n);
    map<int, bool> m;
    loop(i, n){cin >> input[i];}
    // ---------------- Separator ----------------
    while(!check(input, k)){
        m.clear();
        loop(i, n){
            if(!m[input[i]] && input[i] < k) {
                m[input[i]] = true;
                input[i]++;
            }
        }
        coins++;
    }
    // ---------------- Separator ----------------
    cout << coins << endl;
    // ---------------- Separator ----------------
    return 0;
}

bool check(veci input, int k){
    loop(i, input.size()){
        if(input[i] != k)
            return false;
        continue;
    }
    return true;
}