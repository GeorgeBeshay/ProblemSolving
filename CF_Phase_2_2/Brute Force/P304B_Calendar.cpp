/*
 * Created By George on 3/24/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/304/B
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

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n) for(int i = 0 ; i < n ; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool isLeap(int year);

int main() {
    // ---------------- Separator ----------------
    string d1_s, d2_s;
    vveci dates(2); // yyyy/mm/dd
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ans = 0;
    cin >> d1_s >> d2_s;
    for(int i = 0 ; i < 2 ; i++){
        veci tempDate;
        string d = d1_s;
        if(i == 1)
            d = d2_s;
        tempDate.push_back(stoi(d.substr(0, 4)));
        tempDate.push_back(stoi(d.substr(5, 2)) - 1);
        tempDate.push_back(stoi(d.substr(8, 2)));
        dates[i] = tempDate;
    }
    sort(dates.begin(), dates.end());
    // ---------------- Separator ----------------
    if(! (dates[0][0] == dates[1][0] && dates[0][1] == dates[1][1]) ) {
        ans += days[dates[0][1]] - dates[0][2] + 1;
        if(isLeap(dates[0][0]) && dates[0][1] == 1)
            ans++;
        // get the remaining days in the same starting year after the starting month
        int limit = (dates[0][0] != dates[1][0] ? 12 : dates[1][1]);
        for(int i = dates[0][1] + 1 ; i < limit ; i++){
            ans += days[i];
            if(i == 1 && isLeap(dates[0][0]))
                ans++;
        }
        // get the number of days in the years between the starting and ending year
        for(int year = dates[0][0] + 1 ; year < dates[1][0] ; year++){
            ans += 365;
            if(isLeap(year))
                ans++;
        }
        // get the remaining days in the same ending year before the ending month
        limit = (dates[0][0] != dates[1][0] ? 0 : 12);
        for(int i = limit ; i < dates[1][1] ; i++){
            ans += days[i];
            if(i == 1 && isLeap(dates[1][0]))
                ans++;
        }
        // days in the same ending month before the ending day
        ans += dates[1][2] - 1;
    } else {
        ans = dates[1][2] - dates[0][2];
    }
    // ---------------- Separator ----------------
    cout << ans << endl;
    // ---------------- Separator ----------------
    return 0;
}

bool isLeap(int year){
    return( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}