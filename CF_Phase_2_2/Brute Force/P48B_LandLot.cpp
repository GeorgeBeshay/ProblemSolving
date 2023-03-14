/*
 * Created By George on 3/14/23.
 */

/*
 * Problem Link:    https://codeforces.com/contest/48/problem/B
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

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int n, m, a, b;cin >> n >> m;vveci grid(n);veci solutions;
    ffor(i, n){
        veci row(m);
        ffor(j, m){cin >> row[j];}
        grid[i] = row;
    }
    cin >> a >> b;
    // ---------------- Separator ----------------
    for(int i = 0 ; i < n ; i++){
        if(n - i < a)
            break;
        for(int j = 0 ; j < m ; j++){
            if(m - j < b)
                break;
            int tempAns = 0;
            for(int k = i ; k < i + a ; k++){
                for(int o = j ; o < j + b ; o++){
                    if(grid[k][o] == 1)
                        tempAns++;
                }
            }
            solutions.push_back(tempAns);
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(n - i < b)
            break;
        for(int j = 0 ; j < m ; j++){
            if(m - j < a)
                break;
            int tempAns = 0;
            for(int k = i ; k < i + b ; k++){
                for(int o = j ; o < j + a ; o++){
                    if(grid[k][o] == 1)
                        tempAns++;
                }
            }
            solutions.push_back(tempAns);
        }
    }
    // ---------------- Separator ----------------
    sort(solutions.begin(), solutions.end());
    cout << solutions[0] << endl;
    // ---------------- Separator ----------------
    return 0;
}