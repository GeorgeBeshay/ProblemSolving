/*
 * Created By George on 3/6/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/426/B
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

bool areVecsEqual(veci v1, veci v2);
bool canSplit(vveci in);
int work(vveci in);

int main() {
    // ---------------- Separator ----------------
    int n, m;
    cin >> n >> m;
    vveci in(n);
    ffor(i, n){
        veci temp(m);
        ffor(j, m){
            cin >> temp[j];
        }
        in[i] = temp;
    }
    // ---------------- Separator ----------------
    if(n % 2 == 1){
        cout << n << endl;
        exit(0);
    }
    // ---------------- Separator ----------------
    cout << work(in) << endl;
    // ---------------- Separator ----------------
    return 0;
}

int work(vveci in){
    while(canSplit(in)) {
            vveci newVec;
            newVec.insert(newVec.end(), in.begin(), in.end() - (in.size() / 2));
            in = newVec;
            if(in.size() % 2 == 1)
                break;
    }
    return in.size();
}

bool canSplit(vveci in){
    if(in.size() % 2 == 1)
        return false;
    bool good = true;
    int half = in.size()/2;
    int other = half-1;
    for (int i = half; i < in.size(); i++, other--) {
        if (!areVecsEqual(in[i], in[other])) {
            good = false;
            break;
        }
    }
    return good;
}

bool areVecsEqual(veci v1, veci v2){
    for(int i = 0 ; i < v1.size() ; i++){
        if(v1[i] != v2[i])
            return false;
    }
    return true;
}