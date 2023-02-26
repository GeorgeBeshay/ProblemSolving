/*
 * Created By George on 2/26/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/69/B
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
    int n, m, tempStart, tempEnd, tempTime, tempPrize, ans = 0;
    cin >> n >> m;
    map<int, int> sectionToAthleteMap;
    map<int, pr> athleteToDataMap;
    loop(i, n){sectionToAthleteMap[i+1] = -1;}
    loop(i, m){
        cin >> tempStart >> tempEnd >> tempTime >> tempPrize;
        athleteToDataMap[i] = make_pair(tempTime, tempPrize);
        for(int j = tempStart ; j <= tempEnd ; j++){
            if(sectionToAthleteMap[j] == -1)
                sectionToAthleteMap[j] = i;
            else if(athleteToDataMap[sectionToAthleteMap[j]].first > tempTime)
                sectionToAthleteMap[j] = i;
        }
    }
    // ---------------- Separator ----------------
    for(auto I : sectionToAthleteMap)
        ans += athleteToDataMap[I.second].second;
    // ---------------- Separator ----------------
    cout << ans << endl;
    // ---------------- Separator ----------------
    return 0;
}