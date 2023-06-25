/*
 * Created By George on 6/24/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/932/B
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int answers[10][1000005];

int func_f(int n){
    string s = to_string(n);
    int tempProduct = 1;
    for(char c : s)
        if(c - '0' != 0)
            tempProduct *= (c - '0');
    return tempProduct;
}

int func_g(int n){
    if(n < 10)
        return n;
    return func_g(func_f(n));
}

int main() {
    // ---------------- Separator ----------------
    int q, l, r, k, tempVar; // q = 10^5

    for(int i = 1 ; i <= 1000000 ; i++){
        tempVar = func_g(i);
        answers[tempVar][i]++;
    }
    for(int i = 1 ; i < 10 ; i++)
        for(int j = 1 ; j <= 1000000 ; j++)
            answers[i][j] += answers[i][j-1];

    cin >> q;
    while(q--){
        cin >> l >> r >> k;
        cout << answers[k][r] - answers[k][l-1] << endl;
    }
    // ---------------- Separator ----------------    
    return 0;
}
