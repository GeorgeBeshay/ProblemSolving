/*
 * Created By George on 7/1/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/same-tree/
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // check for empty tree(s) first. (corner cases)
        if (q == nullptr && p == nullptr) {
            return true;
        }
        if (q == nullptr || p == nullptr) {
            return false;
        }

        // let's use a recursive procedure to compare each node to its corresponding one.

        // base case is to reach a leaf node.
        if (q->left == nullptr && q->right == nullptr && p->left == nullptr && p->right == nullptr) {
            return q->val == p->val;
        }

        // if structure not the same, no need to further compare any nodes.
        if (
                (q->left == nullptr && p->left != nullptr) || (q->right == nullptr && p->right != nullptr) ||
                        (q->left != nullptr && p->left == nullptr) || (q->right != nullptr && p->right == nullptr)
        ) {
            return false;
        }

        // now we are sure that the nodes are equivalent considering the structure aspect only.
        // let's check for the value aspect.
        if (q->val != p->val) {
            return false;
        }

        // at this point we are sure for both, the structure and the value aspect that they are equal.
        // we still need to process the remaining children nodes.

        bool tempAns = true;
        // recall that they are equally in the structure, so if a left node is not null, then surely the other is also
        // not null.
        if (q->left != nullptr)
            tempAns &= isSameTree(p->left, q->left);
        if (q->right != nullptr)
            tempAns &= isSameTree(p->right, q->right);

        return tempAns;
    }
};

int main() {


    return 0;
}