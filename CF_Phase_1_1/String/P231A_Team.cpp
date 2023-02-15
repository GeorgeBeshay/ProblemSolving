//
// Created By George.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/231/A
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

#define loop(loopVar, upTo) for(int loopVar = 0 ; loopVar < upTo ; loopVar++)

int main() {
    int n, ans = 0, petya, vasya, tonya;
    cin >> n;
    while(n--){
        cin >> petya >> vasya >> tonya;
        if(petya + vasya + tonya >= 2)
            ans++;
    }
    cout << ans << endl;
    return 0;
}