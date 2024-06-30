/*
 * Created By George on 4/18/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/add-one-row-to-tree/
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        stack<TreeNode*> S;
        S.push(root);
        map<TreeNode*, int> nodeDepth;
        nodeDepth[root] = 1;

        while (!S.empty()) {
            TreeNode* currentNode = S.top();
            S.pop();

            if (nodeDepth[currentNode] == depth - 1) {
                TreeNode* newNode1 = new TreeNode(val);
                TreeNode* newNode2 = new TreeNode(val);
                newNode1->left = currentNode->left;
                newNode2->right = currentNode->right;
                currentNode->left = newNode1;
                currentNode->right = newNode2;
            } else {
                if (currentNode->left != nullptr)
                    S.push(currentNode->left);
                if (currentNode->right != nullptr)
                    S.push(currentNode->right);
                nodeDepth[currentNode->left] = nodeDepth[currentNode] + 1;
                nodeDepth[currentNode->right] = nodeDepth[currentNode] + 1;
            }
        }

        return root;
    }
};

int main() {



    return 0;
}