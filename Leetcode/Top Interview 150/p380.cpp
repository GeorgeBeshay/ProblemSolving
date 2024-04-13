/*
 * Created By George on 4/10/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=study-plan-v2&envId=top-interview-150
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

class RandomizedSet {
public:
    unordered_set<int> nums;

    RandomizedSet() {
    }

    bool insert(int val) {
        if (nums.count(val) != 0) {
            return false;
        }
        nums.insert(val);
        return true;
    }

    bool remove(int val) {
        if (nums.count(val) != 1) {
            return false;
        }
        nums.erase(val);
        return true;
    }

    int getRandom() {
        return *next(nums.begin(), rand() % nums.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {

    return 0;
}