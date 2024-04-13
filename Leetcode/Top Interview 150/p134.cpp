/*
 * Created By George on 4/11/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/gas-station/?envType=study-plan-v2&envId=top-interview-150
 * Problem Status:      Accepted
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

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int currentGas = 0;
        int startIdx = 0;

        for (int i = 0 ; i < gas.size() ; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += (gas[i] - cost[i]);
            if (currentGas < 0) {
                currentGas = 0;
                startIdx = i + 1;
            }
        }

        if (totalCost > totalGas)
            return -1;
        else
            return startIdx;
    }
};

int main() {



    return 0;
}