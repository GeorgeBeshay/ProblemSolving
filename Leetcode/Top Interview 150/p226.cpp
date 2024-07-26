/*
 * Created By George on 7/1/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        // we will adhere to a recursive approach.
        // however, it is important to note that this approach may not be suitable if the number nodes in the tree is
        // large, but since we are given that it would be at maximum = 100 nodes, then we can go with the recursive
        // solution.

        // corner case (empty tree)
        if (root == nullptr)
            return nullptr;

        TreeNode* tempPtr = root->left;
        root->left = root->right;
        root->right = tempPtr;

        if (root->left != nullptr)
            invertTree(root->left);
        if (root->right != nullptr)
            invertTree(root->right);

        return root;
    }
};

int main() {


    return 0;
}