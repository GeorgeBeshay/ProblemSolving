/*
 * Created By George on 2/25/23.
 */

/*
 * Problem Link:    https://codeforces.com/problemset/problem/914/B
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
    int n;cin >> n;veci input(n);
    string winner = "Agasa";
    map<int, int> freq;
    loop(i, n){
        cin >> input[i];
        freq[input[i]]++;
    }
    for(auto I = freq.rbegin(); I != freq.rend() ; I++){
        if(I->second % 2 == 1) {
            winner = "Conan";
            break;
        }
    }
    // ---------------- Separator ----------------
    cout << winner << endl;
    // ---------------- Separator ----------------
    return 0;
}