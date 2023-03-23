/*
 * Created By George on 3/23/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/203/B
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

int ifSquare_getLastMove(pr** paper, int x, int y){
    int ans = 0, count = 0;
    for(int i = x ; i < x+3 ; i++){
        for(int j = y ; j < y+3 ; j++){
            if(paper[i][j].first == 1)
                count++;
            if(paper[i][j].first == 1 && paper[i][j].second > ans)
                ans = paper[i][j].second;
        }
    }
    if(count < 9)
        ans = (int)pow(10, 9);
    return ans;
}

int main() {
    // ---------------- Separator ----------------
    int n, m, count = 1;
    cin >> n >> m;
    veci Xs(m), Ys(m), answers;
    pr** paper = (pr**)malloc(n * sizeof(pr*));
    ffor(i, n){paper[i] = (pr*)malloc(n * sizeof(pr));}
    ffor(i, m){
        cin >> Xs[i] >> Ys[i];
        Xs[i]--;
        Ys[i]--;
        paper[Xs[i]][Ys[i]] = {1, count++};
    }
    // ---------------- Separator ----------------
    if(n < 3 || m < 3){  // impossible
        cout << -1 << endl;
        exit(0);
    }
    // ---------------- Separator ----------------
    ffor(i, n-2)
        ffor(j, n-2)
            if(paper[i][j].first == 1)
                answers.push_back(ifSquare_getLastMove(paper, i, j));
    sort(answers.begin(), answers.end());
    if(answers[0] > m)
        answers[0] = -1;
    // ---------------- Separator ----------------
    cout << answers[0] << endl;
    // ---------------- Separator ----------------
    return 0;
}