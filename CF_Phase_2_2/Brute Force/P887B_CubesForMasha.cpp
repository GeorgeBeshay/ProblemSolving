/*
 * Created By George on 3/28/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/887/B
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

bool solve2(vector<map<char, int>>& available, int num);

int main() {
    // ---------------- Separator ----------------
    int n, ans;
    char temp;
    cin >> n;
    vector<map<char, int>> available(n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 6 ; j++){
            cin >> temp;
            available[i][temp]++;
        }
    }
    // ---------------- Separator ----------------
    for(ans = 1 ; ans < 1000 ; ans++){
        if(!solve2(available, ans))
            break;
    }
    cout << ans - 1 << endl;
    // ---------------- Separator ----------------
    return 0;
}

bool solve2(vector<map<char, int>>& available, int num){
    string num_s = to_string(num);
    bool answer = false;
    switch (num_s.size()) {
        case 1:
            ffor(i, available.size())
                if(available[i][num_s[0]] > 0)
                    answer = true;
            break;
        case 2:
            if(available.size() < 2)
                break;
            ffor(i, available.size()){
                ffor(k, num_s.size()) {
                    if (available[i][num_s[k]] > 0) {
                        ffor(j, available.size()) {
                            if (i == j)
                                continue;
                            if (available[j][num_s[1-k]] > 0)
                                return true;
                        }
                    }
                }
            }
            break;
        case 3:
            if(available.size() < 3)
                break;
            ffor(i, available.size()){
//                ffor(k, num_s.size()) {
                    if (available[i][num_s[i]] > 0) {
                        ffor(j, available.size()) {
                            if (i == j)
                                continue;
                            if (available[j][num_s[j]] > 0) {
                                ffor(z, available.size()){
                                    if(z == i || z == j)
                                        continue;
                                    if(available[z][num_s[z]] > 0)
                                        return true;
                                }
                            }
                        }
                    }
//                }
            }
            break;
        default:
            break;
    }
    return answer;
}