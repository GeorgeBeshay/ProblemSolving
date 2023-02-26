/*
 * Created By George on 2/26/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/934/B
 * Problem Status:      Accepted.
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

string getNum(int x);

int main() {
    // ---------------- Separator ----------------
    int k;
    cin >> k;
    // max = 1 000 000 000 000 000 000
    // max =   888 888 888 888 888 888
    // max loops = 18 * 2 = 36
    // ---------------- Separator ----------------
    cout << ((k > 36) ? "-1" : getNum(k)) << endl;
    // ---------------- Separator ----------------
    return 0;
}

string getNum(int x){
    veci numLoops = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
    //               0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    string ans;
    if(x % 2 == 1)
        ans += '4';
    loop(i, x/2){ans += '8';}
    return ans;
}