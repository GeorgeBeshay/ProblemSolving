/*
 * Created By George on 9/13/2023.
 */

/*
 * Problem Link:            https://codeforces.com/contest/1857/problem/B
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

int main() {

    int t, smallestIndex;
    string num;
    bool roundUp;
    cin >> t;
    while(t--){
        cin >> num;
        roundUp = false;
        smallestIndex = num.size() - 1;
        for(int i = num.size() - 1 ; i >= 0 ; i--){
            if(roundUp){
                if(num[i] != '9') {
                    num[i] = ((num[i] - '0') + 1) + '0';
                    roundUp = false;
                } else
                    num[i] = '0';
            }
            if(num[i] - '0' >= 5){
                roundUp = true;
                num[i] = '0';
                smallestIndex = max(0, i - 1);
            }
        }
        if(roundUp)
            num.insert(num.begin(), '1');
        for(int i = smallestIndex + 1 ; i < num.size() ; i++)
            num[i] = '0';
        cout << num << endl;
    }

    return 0;
}