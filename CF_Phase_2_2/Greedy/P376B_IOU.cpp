/*
 * Created By George on 3/1/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/376/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;
#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vveci filter(vveci in);
int countFinalDebts(vveci in);
vveci work(vveci in);
bool checkTerminationCondition(vveci in);

int main() {
    // ---------------- Separator ----------------
    int n, m, tempInput, ans = 0;
    cin >> n >> m;
    vveci debts(m);ffor(i, m){ffor(j, 3){cin >> tempInput; debts[i].push_back(tempInput);}}
    vveci newDebts;
    // ---------------- Separator ----------------
    while(!checkTerminationCondition(debts))
        debts = work(debts);
    // ---------------- Separator ----------------
    cout << countFinalDebts(debts) << endl;
    // ---------------- Separator ----------------
    return 0;
}

int countFinalDebts(vveci in){
    int ans = 0;
    ffor(i, in.size()){ans += in[i][2];}
    return ans;
}

vveci work(vveci in){
    vveci out;
    ffor(i, in.size()){
        if(in[i][2] == 0)
            continue;
        ffor(j, in.size()){
            if(i == j)
                continue;
            if(in[i][2] == 0)
                break;
            if(in[j][2] == 0)
                continue;
            if(in[j][0] == in[i][1]){
                veci temp;
                if(in[i][2] >= in[j][2])
                    temp = {in[i][0], in[j][1], in[j][2]};
                else
                    temp = {in[i][0], in[j][1], in[i][2]};
                in[i][2] -= temp[2];
                in[j][2] -= temp[2];
                out.push_back(temp);
            }
        }
        if(in[i][2] > 0)
            out.push_back(in[i]);
    }
    return filter(out);
}

bool checkTerminationCondition(vveci in){
    map<int, bool> indebted;
    ffor(i, in.size()){indebted[in[i][0]] = true;}
    ffor(i, in.size()){
        if(indebted[in[i][1]])
            return false;
    }
    return true;
}

vveci filter(vveci in){
    vveci ans;
    ffor(i, in.size()){
     if(in[i][0] != in[i][1])
         ans.push_back(in[i]);
    }
    return ans;
}