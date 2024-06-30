/*
 * Created By George on 4/18/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/smallest-string-starting-from-leaf/
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
    string smallestFromLeaf(TreeNode* root) {
        map<TreeNode*, TreeNode*> parent;
        map<TreeNode*, int> nodeLevel;

        queue<TreeNode*> Q;
        Q.push(root);
        nodeLevel[root] = 0;

        TreeNode* startNode = nullptr;

        while (!Q.empty()) {
            TreeNode* currentNode = Q.front();
            Q.pop();

            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                nodeLevel[currentNode];

                if (startNode == nullptr || startNode->val > currentNode->val)
                    startNode = currentNode;
                else if (startNode->val == currentNode->val) {

                    TreeNode* tempNode1;
                    if (parent.count(currentNode) > 0)
                        tempNode1 = parent[currentNode];
                    else
                        tempNode1 = nullptr;

                    TreeNode* tempNode2;
                    if (parent.count(startNode) > 0)
                        tempNode2 = parent[startNode];
                    else
                        tempNode2 = nullptr;

                    while (tempNode1 != nullptr && tempNode2 != nullptr && tempNode1->val == tempNode2->val) {
                        if (parent.count(tempNode1) > 0)
                            tempNode1 = parent[tempNode1];
                        else
                            tempNode1 = nullptr;

                        if (parent.count(tempNode2) > 0)
                            tempNode2 = parent[tempNode2];
                        else
                            tempNode2 = nullptr;
                    }

                    if (tempNode2 != nullptr && tempNode1->val < tempNode2->val)
                        startNode = currentNode;

                }
            }

            if (currentNode->left != nullptr) {
                parent[currentNode->left] = currentNode;
                nodeLevel[currentNode->left] = nodeLevel[currentNode] + 1;
                Q.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                parent[currentNode->right] = currentNode;
                nodeLevel[currentNode->right] = nodeLevel[currentNode] + 1;
                Q.push(currentNode->right);
            }
        }

        string ans = "";

        while (parent.count(startNode) > 0) {
            ans = ans + (char)(startNode->val + 'a');
            startNode = parent[startNode];
        }
        ans = ans + (char)(startNode->val + 'a');

        return ans;

    }
};

int main() {

    TreeNode* root = new TreeNode(2);
    root->val = 2;
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);

    root->left->right = new TreeNode(1);
    root->left->right->left = new TreeNode(0);

    root->right->left = new TreeNode(0);

    Solution solution;

    cout << solution.smallestFromLeaf(root);

    return 0;
}