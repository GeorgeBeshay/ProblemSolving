//
// Created By George.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/811/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define vecOf(type) vector<type>
#define loop(loopVar, upTo) for(int loopVar = 0 ; loopVar < upTo ; loopVar++)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    fast_cin();
    int n, m, l, x, r, smallerTermsCount;
    cin >> n >> m;
    veci myVec(n);
    loop(i, n){cin >> myVec[i];}
    while(m--){
        cin >> l >> r >> x;
        l--;r--;x--;
        if(l == r){
            cout << "Yes" << endl;
            continue;
        }
        smallerTermsCount = 0;
        for(int o = l ; o <= r ; o++)
            if(myVec[o] < myVec[x])
                smallerTermsCount++;
        if(smallerTermsCount == x - l)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}