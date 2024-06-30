/*
 * Created By George on 4/19/2024.
 */

/*
 * Problem Link:            https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        map<TreeNode*, int> nodeToLevel;
        int currentLevel = -1;

        if (root != nullptr) {
            Q.push(root);
            nodeToLevel[root] = 0;
        }
        vveci ans;

        while (!Q.empty()) {
            TreeNode* currentNode = Q.front();
            Q.pop();
            if (nodeToLevel[currentNode] > currentLevel) {
                ans.push_back({currentNode->val});
                currentLevel++;
            } else {
                ans[ans.size() - 1].push_back(currentNode->val);
            }
            if (currentNode->left != nullptr) {
                Q.push(currentNode->left);
                nodeToLevel[currentNode->left] = nodeToLevel[currentNode] + 1;
            }
            if (currentNode->right != nullptr) {
                Q.push(currentNode->right);
                nodeToLevel[currentNode->right] = nodeToLevel[currentNode] + 1;
            }

        }

        return ans;
    }
};

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vveci ans = solution.levelOrder(root);


    return 0;
}