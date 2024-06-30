/*
 * Created By George on 6/30/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root) {

        stack<TreeNode*> nodesStack;
        map<TreeNode*, int> depthMapper;
        if (root != nullptr) {
            nodesStack.push(root);
            depthMapper[root] = 1;
        }

        int ans = 0;

        while (!nodesStack.empty()) {

            TreeNode* tempNode = nodesStack.top();
            nodesStack.pop();

            ans = max(ans, depthMapper[tempNode]);

            if (tempNode->left != nullptr) {
                depthMapper[tempNode->left] = depthMapper[tempNode] + 1;
                nodesStack.push(tempNode->left);
            }
            if (tempNode->right != nullptr) {
                depthMapper[tempNode->right] = depthMapper[tempNode] + 1;
                nodesStack.push(tempNode->right);
            }

        }

        return ans;
    }
};

int main() {


    return 0;
}