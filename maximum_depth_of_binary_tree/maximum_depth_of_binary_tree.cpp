#include <iostream>
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
};

int main() {
    Solution solution;

    TreeNode* root = new TreeNode(3);
    TreeNode* n1 = new TreeNode(9);
    TreeNode* n2 = new TreeNode(20);
    TreeNode* n3 = new TreeNode(15);
    TreeNode* n4 = new TreeNode(7);

    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;

    int depth = solution.maxDepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}