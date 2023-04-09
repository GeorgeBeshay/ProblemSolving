/*
 * Created By George on 3/28/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/807/B
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
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool check(int score, int rank);

int main() {
    // ---------------- Separator ----------------
    veci answers;
    int p, x, y, x_copy;
    cin >> p >> x >> y;
    // ---------------- Separator ----------------
    x_copy = x;
    while(x_copy >= y){
        if(check(x_copy, p)){
            cout << 0 << endl;
            exit(0);
        }
        x_copy -= 50;
    }
    // ---------------- Separator ----------------
    x_copy = x;
    while(x_copy <= 1000000){
        if(check(x_copy, p)){
            cout << ((x_copy + 50 - x) / 100) << endl;
            exit(0);
        }
        x_copy += 50;
    }
    // ---------------- Separator ----------------
    return 0;
}

bool check(int score, int rank){
    score /= 50;
    score %= 475;
    for(int i = 0 ; i < 25 ; i++){
        score = (score * 96 + 42) % 475;
        if(score + 26 == rank)
            return true;
    }
    return false;
}