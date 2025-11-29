#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

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
        queue<TreeNode*> q;
        int depth = 0;
        int layer_size = 0;

        if (root) {
            q.push(root);
            layer_size++;
        }

        while (!q.empty()) {
            depth++;
            int i = 0;
            int layer_size_tmp = layer_size;
            layer_size = 0;
            while (i < layer_size_tmp) {
                TreeNode* n = q.front();
                q.pop();
                if (n->left) {
                    q.push(n->left);
                    layer_size++;
                }
                if (n->right) {
                    q.push(n->right);
                    layer_size++;
                }
                i++;
            }
        }

        return depth;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        int depth1 = maxDepth(root->left);
        int depth2 = maxDepth(root->right);

        if (abs(depth1-depth2) > 1) {
            return false;
        } else {
            return true && isBalanced(root->left) && isBalanced(root->right);
        }

    }
};

int main() {
    Solution solution;

    TreeNode* root = new TreeNode(1);
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(3);

    root->right = n1;
    n1->right = n2;

    bool balanced = solution.isBalanced(root);
    cout << (balanced ? "The tree is balanced." : "The tree is not balanced.") << endl;

    return 0;
}