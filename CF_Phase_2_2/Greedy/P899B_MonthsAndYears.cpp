//
// Created By George.
//

/*
 * Problem Link:        https://codeforces.com/problemset/problem/899/B
 * Problem Status:      Accepted.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define vecOf(type) vector<type>
#define loop(loopVar, upTo) for(int loopVar = 0 ; loopVar < upTo ; loopVar++)

int main() {
    int n;
    cin >> n;
    veci myVec(n);
    veci possibleYear1 = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    veci possibleYear2 = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vveci possibilities = {possibleYear1, possibleYear2};
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 2 ; j++){
            if(j == 1 && i == 1)
                continue;
            veci temp(possibilities[i]);
            temp.insert(temp.end(), possibilities[j].begin(), possibilities[j].end());
            possibilities.push_back(temp);
        }
    possibilities.erase(possibilities.begin());possibilities.erase(possibilities.begin());
    loop(i, n){cin >> myVec[i];}
    for(veci possibility : possibilities){
        for(int i = 0 ; i < 24 ; i++){
            if(possibility[i] != myVec[0])
                continue;
            bool good = true;
            int c1 = 0;
            int c2 = i;
            for(int j = 0 ; j < n ; j++){
                if(myVec[c1] != possibility[c2]){
                    good = false;
                    break;
                }
                c2 = (c2 + 1) % 24;
                c1++;
            }
            if(good){
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;
    return 0;
}