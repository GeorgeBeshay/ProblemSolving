/*
 * Created By George on 4/20/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/572/B
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


#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    ll n, s, tempPrice, tempQuantity;
    char tempChar;
    cin >> n >> s;
    map<ll, ll> SOrders, BOrders;
    for(int i = 0 ; i < n ; i++){
        cin >> tempChar >> tempPrice >> tempQuantity;
        if(tempChar == 'B')
            BOrders[tempPrice] += tempQuantity;
        else
            SOrders[tempPrice] += tempQuantity;
    }
    // ---------------- Separator ----------------
    auto I = SOrders.begin();
    string temp;
    vector<string> tempCont;
    for(int i = 0 ; i < min((int)s, (int)SOrders.size()) ; i++){
        temp = "S " + to_string(I->first) + " " + to_string(I->second) + "\n";
        tempCont.push_back(temp);
        I++;
    }
    for(int i = (int)tempCont.size()-1 ; i >= 0 ; i--)
        cout << tempCont[i];
    auto J = BOrders.rbegin();
    for(int i = 0 ; i < min((int)s, (int)BOrders.size()) ; i++){
        cout << "B " << J->first << " " << J->second << endl;
        J++;
    }
    // ---------------- Separator ----------------
    return 0;
}