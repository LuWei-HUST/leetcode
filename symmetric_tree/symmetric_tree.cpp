#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p && q) {
            return false;
        }

        if (p && !q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        } else {
            return true && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (!root->left && !root->right) {
            return true;
        }

        if (!root->left && root->right) {
            return false;
        }

        if (root->left && !root->right) {
            return false;
        }

        return isSameTree(root->left, root->right);
    }
};

int main() {
    Solution solution;

    TreeNode* root = new TreeNode(1);
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(3);
    root->left = n1;
    root->right = n2;
    n1->right = n3;
    n2->right = n4;

    bool r = solution.isSymmetric(root);

    cout << r << endl;

    return 0;
}