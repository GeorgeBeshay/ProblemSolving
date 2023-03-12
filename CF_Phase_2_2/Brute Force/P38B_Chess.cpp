/*
 * Created By George on 3/12/23.
 */
 
 /*
  * Problem Link:       https://codeforces.com/problemset/problem/38/B
  * Problem Status:     Accepted.
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

int main(){
    // ---------------- Separator ----------------
    string s1, s2;cin >> s1 >> s2;
    int ans = 64 - 2;
    string board[8]; ffor(i, 8){board[i] = "........";}
    s1 = to_string(int(s1[0]) - 96) + s1[1];
    s2 = to_string(int(s2[0]) - 96) + s2[1];
    pr rook, knight;
    rook = {int(s1[0]) - 49, int(s1[1]) - 49};
    knight = {int(s2[0]) - 49, int(s2[1]) - 49};
    board[rook.first][rook.second] = 'x';
    board[knight.first][knight.second] = 'x';
    ffor(i, 8){
        ffor(j, 8){
            if(board[i][j] == 'x')
                continue;
            if(i == int(s1[0]) - 49)
                ans--;
            else if(j == int(s1[1]) - 49)
                ans--;
            else {
                if(i - 1 >= 0){
                    // ---------------- Separator ----------------
                    if(j - 2 >= 0){
                        if(board[i-1][j-2] == 'x') {
                            ans--;
                            continue;
                        }
                    }
                    if(j + 2 < 8){
                        if(board[i-1][j+2] == 'x') {
                            ans--;
                            continue;
                        }
                    }
                    // ---------------- Separator ----------------
                    if(i - 2 >= 0){
                        if(j - 1 >= 0) {
                            if (board[i - 2][j - 1] == 'x') {
                                ans--;
                                continue;
                            }
                        }
                        if(j + 1 < 8){
                            if(board[i-2][j+1] == 'x') {
                                ans--;
                                continue;
                            }
                        }
                    }
                    // ---------------- Separator ----------------
                }
                if(i + 1 < 8){
                    if(j - 2 >= 0){
                        if(board[i+1][j-2] == 'x') {
                            ans--;
                            continue;
                        }
                    }
                    if(j + 2 < 8){
                        if(board[i+1][j+2] == 'x') {
                            ans--;
                            continue;
                        }
                    }
                    // ---------------- Separator ----------------
                    if(i + 2 < 8){
                        if(j - 1 >= 0){
                            if(board[i+2][j-1] == 'x'){
                                ans--;
                                continue;
                            }
                        }
                        if(j + 1 < 8){
                            if(board[i+2][j+1] == 'x'){
                                ans--;
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
    // ---------------- Separator ----------------
    cout << ans << endl;
    // ---------------- Separator ----------------
    return 0;
}