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
            return true && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = new TreeNode(2);
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(2);
    TreeNode* n4 = new TreeNode(2);

    root1->left = n1;
    root1->right = n2;
    n1->right = n3;
    n3->left = n4;

    TreeNode* root2 = new TreeNode(2);
    TreeNode* n5 = new TreeNode(2);
    TreeNode* n6 = new TreeNode(2);
    TreeNode* n7 = new TreeNode(2);
    TreeNode* n8 = new TreeNode(2);

    root2->left = n5;
    root2->right = n6;
    n5->left = n7;
    n6->left = n8;

    bool r = solution.isSameTree(root1, root2);

    cout << r << endl;

    return 0;
}