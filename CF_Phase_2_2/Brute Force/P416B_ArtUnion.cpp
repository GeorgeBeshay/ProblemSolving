/*
 * Created By George on 3/20/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/416/B
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

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int m, n;
    cin >> m >> n;
    vveci picturesData(m);
    ffor(i, m){veci tempVec(n);ffor(j, n){cin >> tempVec[j];}picturesData[i] = tempVec;}
    vveci picturesData_Copy(picturesData);
    // ---------------- Separator ----------------
    int temp = 0;
    ffor(i, m){
        picturesData_Copy[i][0] += temp;
        temp = picturesData_Copy[i][0];
    }
    for(int i = 1 ; i < n ; i++){
        int previous = 0;
        for(int j = 0 ; j < m ; j++){
            picturesData_Copy[j][i] += max(previous, picturesData_Copy[j][i-1]);
            previous = picturesData_Copy[j][i];
        }
    }
    // ---------------- Separator ----------------
    ffor(i, m)
        cout << picturesData_Copy[i][n-1] << " ";
    // ---------------- Separator ----------------
    return 0;
}