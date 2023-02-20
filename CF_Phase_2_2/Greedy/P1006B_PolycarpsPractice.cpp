/*
 * Created By George on 2/20/23.
 */

/*
 * Problem Link:        https://codeforces.com/problemset/problem/1006/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;
#define loop(loopVar, upTo) for(int loopVar = 0 ; loopVar < upTo ; loopVar++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // ---------------- Separator ----------------
    int n, k, currentIndex = 1;
    bool found = false;
    cin >> n >> k;
    veci input(n);
    loop(i, n){cin >> input[i];}
    // ---------------- Separator ----------------
    veci inputCopy(input);
    veci maxElements(k);
    veci answers(k+1);
    sort(inputCopy.begin(), inputCopy.end());
    for(int i = n-k ; i <= n-1 ; i++){maxElements[i - n + k] = inputCopy[i]; answers[0]+=maxElements[i-n+k];}
    // ---------------- Separator ----------------
    loop(i, n){
        auto it = find(maxElements.begin(), maxElements.end(), input[i]);
        if(it != maxElements.end() && i != 0){
            maxElements.erase(it);
            if(found)
                answers[++currentIndex]++;
            else{
                answers[currentIndex]++;
                found = true;
            }
        } else {
            if(i == 0 && it != maxElements.end()) {
                maxElements.erase(it);
                found = true;
            }
            answers[currentIndex]++;
        }
    }
    // ---------------- Separator ----------------
    cout << answers[0] << endl;
    loop(i, k){cout << answers[i+1] << " ";}
    // ---------------- Separator ----------------
    return 0;
}