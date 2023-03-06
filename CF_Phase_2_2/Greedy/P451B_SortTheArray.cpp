/*
 * Created By George on 3/6/23.
 */
 
 /*
  * Problem Link:       https://codeforces.com/problemset/problem/451/B
  * Problem Status:     Accepted.
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

bool isItSorted(veci v);

int main(){
    // ---------------- Separator ----------------
    int n;cin >> n;veci in(n);ffor(i, n){cin >> in[i];}
    bool good = true;
    int st = -1, end = -1;
    // ---------------- Separator ----------------
    for(int i = 1 ; i < n ; i++){
        if(in[i] < in[i-1]){
            if(end != -1){
                cout << "no" << endl;
                exit(0);
            }
            good = false;
            if(st == -1)
                st = i-1;
        } else {
            if(st != -1) {
                if (end == -1) {
                    end = i-1;
                }
            }
        }
    }
    if(good){
        cout << "yes" << endl << 1 << " " << 1 << endl;
        exit(0);
    }
    if(st != -1 && end == -1)
        end = n-1;
    sort(in.begin() + st, in.begin() + end + 1);
    if(isItSorted(in))
        cout << "yes" << endl << st + 1 << " " << end + 1 << endl;
    else
        cout << "no" << endl;
    // ---------------- Separator ----------------
    return 0;
}

bool isItSorted(veci v) {
    for(int i = 1 ; i < v.size() ; i++){
        if(v[i] < v[i-1])
            return false;
    }
    return true;
}
