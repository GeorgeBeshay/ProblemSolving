/*
 * Created By George on 3/10/23.
 */

/*
 * Problem Link:            https://codeforces.com/problemset/problem/738/B
 * Problem Status:          Accepted.
 */

#include <iostream>
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

int solver(vveci& stage);

int main() {
    // ---------------- Separator ----------------
    int n, m;cin >> n >> m;vveci stage(n);ffor(i, n){veci tempRow(m);ffor(j, m){cin >> tempRow[j];}stage[i] = tempRow;}
    // ---------------- Separator ----------------
    cout << solver(stage) << endl;
    // ---------------- Separator ----------------
    return 0;
}

int solver(vveci& stage){
    int n = (int)stage.size(), m = (int)stage[0].size(), ans = 0;
    map<int, pr> rowLimits, colLimits;
    ffor(i, n){rowLimits[i] = {-1, -1};}
    ffor(j, m){colLimits[j] = {-1, -1};}
    ffor(i, n){
        ffor(j, m){
            if(stage[i][j] == 1){
                if(rowLimits[i].first == -1)
                    rowLimits[i] = {j, j};
                else
                    rowLimits[i].second = j;
                if(colLimits[j].first == -1)
                    colLimits[j] = {i, i};
                else
                    colLimits[j].second = i;
            }
        }
    }
    ffor(i, n){
        ffor(j, m){
            if(stage[i][j] == 0){
                if(j < rowLimits[i].first || (j > rowLimits[i].second && rowLimits[i].second != -1))
                    ans++;
                else if(rowLimits[i].second != -1)
                    ans +=2;
                if(i < colLimits[j].first || (i > colLimits[j].second && colLimits[j].second != -1))
                    ans ++;
                else if (colLimits[j].second != -1)
                    ans += 2;
            }
        }
    }
    // ---------------- Separator ----------------
    return ans;
}