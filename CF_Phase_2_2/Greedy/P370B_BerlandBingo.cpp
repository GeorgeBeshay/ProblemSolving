/*
 * Created By George on 2/28/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/370/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;
#define loop(loopVar, upTo) for(int loopVar = 0 ; loopVar < upTo ; loopVar++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


bool subSet(veci v1, veci v2);

int main() {
    // ---------------- Separator ----------------
    int n, m;
    cin >> n;
    vector<veci> input;
    while(n--){
        cin >> m;
        veci tempVec(m);
        loop(i, m){cin >> tempVec[i];}
        input.push_back(tempVec);
    }
    // ---------------- Separator ----------------
    for(int i = 0 ; i < input.size() ; i++){
        bool good = true;
        for(int j = 0 ; j < input.size() ; j++){
            if(j == i)
                continue;
            if(subSet(input[i], input[j])){
                good = false;
                break;
            }
        }
        cout << ((good) ? "YES" : "NO") << endl;
    }
    // ---------------- Separator ----------------
    return 0;
}

bool subSet(veci v1, veci v2){
    set<int> tempSet;
    tempSet.insert(v1.begin(), v1.end());
    tempSet.insert(v2.begin(), v2.end());
    if(tempSet.size() == v1.size())
        return true;
    return false;
}