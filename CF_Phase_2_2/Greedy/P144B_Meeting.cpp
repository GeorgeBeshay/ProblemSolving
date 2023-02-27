/*
 * Created By George on 2/27/23.
 */

/*
 * Problem Link:        https://codeforces.com/contest/144/problem/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;
#define loop(loopVar, upTo) for(int loopVar = 0 ; loopVar < upTo ; loopVar++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int xa, ya, xb, yb, n, xrad, yrad, radrad, good = 0;
    pr leftDown, rightUp;
    cin >> xa >> ya >> xb >> yb >> n;
    leftDown = make_pair(min(xa, xb), min(ya, yb));
    rightUp = make_pair(max(xa, xb), max(ya, yb));
    vector<pr> chairs;
    vector<pair<pr, int>> radiators;
    for(int i = leftDown.first ; i <= rightUp.first ; i++){
        chairs.push_back(make_pair(i, leftDown.second));
        chairs.push_back(make_pair(i, rightUp.second));
    }
    for(int j = leftDown.second + 1 ; j <= rightUp.second - 1 ; j++){
        chairs.push_back(make_pair(leftDown.first, j));
        chairs.push_back(make_pair(rightUp.first, j));
    }
    while(n--) {
        cin >> xrad >> yrad >> radrad;
        radiators.push_back(make_pair(make_pair(xrad, yrad), radrad));
    }
    for(int i = 0 ; i < chairs.size() ; i++){
        for(int j = 0 ; j < radiators.size() ; j++){
            if(sqrt(pow(chairs[i].first - radiators[j].first.first, 2) + pow(chairs[i].second - radiators[j].first.second, 2)) <= radiators[j].second){
                good++;
                break;
            }
        }
    }
    // ---------------- Separator ----------------
    cout << chairs.size() - good << endl;
    // ---------------- Separator ----------------
    return 0;
}