/*
 * Created By George on 7/8/23.
 */

/*
 * Problem Link:            https://codeforces.com/problemset/problem/777/B
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

int main() {

    int n, case1 = 0, case2 = 0;
    string s1, s2;
    map<int, bool> taken;
    cin >> n;
    cin.ignore();
    getline(cin, s1);
    getline(cin, s2);
    vector<int> sherlock(n), moriarty(n);

    for(int i = 0 ; i < n ; i++){
        sherlock[i] = int(s1[i]) - int('0');
        moriarty[i] = int(s2[i]) - int('0');
    }

    sort(moriarty.begin(), moriarty.end());

    for(int i = 0 ; i < n ; i++){   // O(n^2)
        int j = 0;
        for( ; j < n ; j++)
            if(!taken[j] && moriarty[j] >= sherlock[i]) {
                taken[j] = true;
                break;
            }
        if(j == n || moriarty[j] < sherlock[i])
            case1++;
    }

    taken.clear();

    for(int i = 0 ; i < n ; i++){
        int j = 0;
        for( ; j < n ; j++)
            if(!taken[j] && moriarty[j] > sherlock[i]) {
                taken[j] = true;
                break;
            }
        if(j < n && moriarty[j] > sherlock[i])
            case2++;
    }

    cout << case1 << endl;
    cout << case2 << endl;

    return 0;
}