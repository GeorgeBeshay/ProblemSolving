/*
 * Created By George on 4/11/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150
 * Problem Status:      Accepted.
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
    string intToRoman(int num) {
        unordered_map<int, string> dict;
        dict[1] = "I";
        dict[4] = "IV";
        dict[5] = "V";
        dict[9] = "IX";
        dict[10] = "X";
        dict[40] = "XL";
        dict[50] = "L";
        dict[90] = "XC";
        dict[100] = "C";
        dict[400] = "CD";
        dict[500] = "D";
        dict[900] = "CM";
        dict[1000] = "M";

        veci nums = {1, 4, 5, 9 ,10, 40, 50, 90, 100, 400, 500, 900, 1000};

        string ans = "";

        for (int i = nums.size() - 1 ; i >= 0 ; i--) {
            for (int j = 0 ; j < num / nums[i] ; j++) {
                ans += dict[nums[i]];
            }
            num -= nums[i] * (num / nums[i]);
        }


        return ans;
    }
};

int main() {

    Solution solution;
    cout << solution.intToRoman(3);

    return 0;
}