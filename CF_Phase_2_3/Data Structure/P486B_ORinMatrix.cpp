/*
 * Created By George on 4/15/23.
 */

/*
 * Problem Link:    https://codeforces.com/problemset/problem/486/B
 * Problem Status:  Accepted.
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <string>
#include <queue>

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
    bool good = true;
    cin >> m >> n;
    int A[m][n], B[m][n];
    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < n ; j++){
            cin >> B[i][j];
            A[i][j] = 1;
        }
    // ---------------- Separator ----------------
    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < n ; j++){
            if(B[i][j] == 0){
                for(int k = 0 ; k < m ; k++)
                    A[k][j] = 0;
                for(int k = 0 ; k < n ; k++)
                    A[i][k] = 0;
            }
        }
    // ---------------- Separator ----------------
    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < n ; j++){
            int orOperation = 0;
            // calculate orOperation
            for(int col = 0 ; col < n ; col++)
                orOperation += A[i][col];
            for(int row = 0 ; row < m ; row++)
                orOperation += A[row][j];
            if(orOperation > 1)
                orOperation = 1;
            // --------------------------
            if(B[i][j] != orOperation){
                good = false;
                break;
            }
        }
    // ---------------- Separator ----------------
    if(good){
        cout << "YES" << endl;
        for(int i = 0 ; i < m ; i++) {
            for (int j = 0; j < n; j++)
                cout << A[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "NO";
    }
    // ---------------- Separator ----------------
    return 0;
}