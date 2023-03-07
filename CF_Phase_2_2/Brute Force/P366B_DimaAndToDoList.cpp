/*
 * Created By George on 3/7/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/366/B
 * Problem Status:      Accepted.
 */

#include <iostream>
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

int getMinValue(map<int, int> m);

int main() {
    // ---------------- Separator ----------------
    int n, k;
    cin >> n >> k;
    veci in(n);ffor(i, n){cin >> in[i];}
    map<int, int> myMap;
    // ---------------- Separator ----------------
    for(int i = 0 ; i < n ; i++){
        myMap[i % k] += in[i];
    }
    // ---------------- Separator ----------------
    cout << getMinValue(myMap) << endl;
    // ---------------- Separator ----------------
    return 0;
}

int getMinValue(map<int, int> m){
    int minValue = m.begin()->second;
    int minIndex = 0;
    for(auto I : m){
        if(I.second < minValue) {
            minIndex = I.first;
            minValue = I.second;
        }
    }
    return minIndex + 1;
}