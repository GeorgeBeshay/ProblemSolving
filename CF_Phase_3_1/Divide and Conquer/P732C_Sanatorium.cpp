/*
 * Created By George on 8/23/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/732/problem/C
 * Problem Status:          Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> veci;
typedef vector<vector<ll>> vveci;
typedef pair<ll, ll> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define LARGE_NUM numeric_limits<long long>::max()

ll anotherSol(ll b, ll d, ll s){
    ll x, y, minTerm;
    minTerm = min({b, d, s});
    b -= minTerm; d -= minTerm; s -= minTerm;
    if(b == 0) {
        x = d;
        y = s;
    }
    else if(d == 0) {
        x = b;
        y = s;
    }
    else {
        x = b;
        y = d;
    }
    if(x == y)
        return x - 1;
    else
        return (max(x, y) - 1) * 2 - min(x, y);
}

int main() {

    ll b, d, s, maxTerm, answers[3][3], ans = LARGE_NUM;
    cin >> b >> d >> s;
    memset(answers, -1, sizeof(answers));
    maxTerm = max({b, d, s});
    maxTerm -= 2;
    if(b == d && d == s) {
        cout << 0;
        exit(0);
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(i == 0 && j == 2) { // came before b, left after s
                answers[i][j] = (3 * maxTerm) + 6 - (b + d + s);
            }
            else if(i == 0 && j == 1) { // came before b, left after d
                if (maxTerm + 2 == s)
                    continue;
                else
                    answers[i][j] = (3 * maxTerm) + 5 - (b + d + s);
            }
            else if(i == 0 && j == 0){ // came before b, left after b
                if(maxTerm + 2 == s || maxTerm + 2 == d)
                    continue;
                else
                    answers[i][j] = (3 * maxTerm) + 4 - (b + d + s);
            }
            else if(i == 1 && j == 2){  // came before d, left after s
                if(maxTerm + 2 == b)
                    continue;
                else
                    answers[i][j] = (3 * maxTerm) + 5 - (b + d + s);
            }
            else if(i == 1 && j == 1){  // came before d, left after d
                if(maxTerm + 2 == b || maxTerm + 2 == s)
                    continue;
                else
                    answers[i][j] = (3 * maxTerm) + 4 - (b + d + s);
            }
            else if(i == 1 && j == 0){ // came before d, left after b
                answers[i][j] = 3 * maxTerm + 6 - (b + d + s);
            }
            else if(i == 2 && j == 2){      // came before s, left after s
                if(maxTerm + 2 == b || maxTerm + 2 == d)
                    continue;
                else
                    answers[i][j] = (3 * maxTerm) + 4 - (b + d + s);
            }
            else if(i == 2 && j == 1){      // came before s, left after d
                answers[i][j] = 3 * maxTerm + 6 - (b + d + s);
            }
            else if(i == 2 && j == 0){  // came before s, left after b
                if(maxTerm + 2 == d)
                    continue;
                else
                    answers[i][j] = (3 * maxTerm) + 5 - (b + d + s);
            }
            if(answers[i][j] >= 0 && answers[i][j] < ans)
                ans = answers[i][j];
        }
    }
    cout << ans << endl;


    // Another Solution
//    cout << anotherSol(b, d, s) << endl;
    return 0;
}