/*
 * Created By George on 4/14/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/471/B
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

void showVec(veci vec){
    for(auto I : vec)
        cout << I << " ";
    cout << endl;
}

ll fact(int n){
    if(n == 1)
        return 1;
    return n * fact(n-1);
}

int main() {
    // ---------------- Separator ----------------
    ll n, possible_combinations = 1;
    bool flag = false;
    cin >> n;
    veci input(n);
    vveci combinations(3);
    map<int, veci> frequency;           // between difficulty & vector of integers
    ffor(i, n){cin >> input[i];frequency[input[i]].push_back(i+1);}
    // ---------------- Separator ----------------
    for(const auto& I : frequency){
        int tempSize = (int)I.second.size();
        if(tempSize < 3 && possible_combinations < 3)
            possible_combinations *= fact(tempSize);
        else
            possible_combinations = 4;
    }
    if(possible_combinations >= 3){
        cout << "YES" << endl;
        for(auto  I : frequency){
            if(I.second.size() >= 3){
                combinations[0].push_back(I.second[0]);
                combinations[0].push_back(I.second[1]);
                combinations[0].push_back(I.second[2]);
                combinations[1].push_back(I.second[1]);
                combinations[1].push_back(I.second[0]);
                combinations[1].push_back(I.second[2]);
                combinations[2].push_back(I.second[1]);
                combinations[2].push_back(I.second[2]);
                combinations[2].push_back(I.second[0]);
                for(int i = 3 ; i < I.second.size() ; i++)
                    for(int j = 0 ; j < 3 ; j++)
                        combinations[j].push_back(I.second[i]);
            } else if(I.second.size() == 2){
                combinations[0].push_back(I.second[0]);
                combinations[0].push_back(I.second[1]);
                if(flag) {
                    combinations[1].push_back(I.second[0]);
                    combinations[1].push_back(I.second[1]);
                } else {
                    combinations[1].push_back(I.second[1]);
                    combinations[1].push_back(I.second[0]);
                }
                combinations[2].push_back(I.second[1]);
                combinations[2].push_back(I.second[0]);
                flag = !flag;
            } else if(I.second.size() == 1){
                combinations[0].push_back(I.second[0]);
                combinations[1].push_back(I.second[0]);
                combinations[2].push_back(I.second[0]);
            }
        }
        showVec(combinations[0]);
        showVec(combinations[1]);
        showVec(combinations[2]);
    } else {
        cout << "NO" << endl;
    }
    // ---------------- Separator ----------------
    return 0;
}