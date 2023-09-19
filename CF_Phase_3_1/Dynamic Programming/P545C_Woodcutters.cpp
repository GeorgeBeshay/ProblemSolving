/*
 * Created By George on 9/19/2023.
 */

/*
 * Problem Link:            Woodcutters
 * Problem Status:          Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

int main() {

    int n, ans = 0;
    cin >> n;
    vector<pr> input(n);
    for(int i = 0 ; i < n ; i++)
        cin >> input[i].first >> input[i].second;

    for(int i = 0 ; i < n ; i++){
        if(i == 0 || i == n-1)
            ans++;
        else {
            if(input[i-1].first < input[i].first - input[i].second)
                ans++;
            else if(input[i+1].first > input[i].first + input[i].second){
                ans++;
                input[i].first += input[i].second;
            }
        }
    }
    cout << ans << endl;
    return 0;
}