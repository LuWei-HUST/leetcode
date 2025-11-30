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
    bool travel(TreeNode* root, int targetSum, int sumVal) {
        sumVal += root->val;
        if (!root->left && !root->right) {
            if (sumVal == targetSum) {
                return true;
            }
        }

        bool flag1 = false;
        bool flag2 = false;
        if (root->left) {
            flag1 = travel(root->left, targetSum, sumVal);
        }
        if (root->right) {
            flag2 = travel(root->right, targetSum, sumVal);
        }

        if (flag1 || flag2) {
            return true;
        } else {
            return false;
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        bool r = travel(root, targetSum, 0);

        return r;
    }
};

int main() {
    Solution solution;

    TreeNode* root = new TreeNode(5);
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(8);
    TreeNode* n3 = new TreeNode(11);
    TreeNode* n4 = new TreeNode(13);
    TreeNode* n5 = new TreeNode(4);
    TreeNode* n6 = new TreeNode(7);
    TreeNode* n7 = new TreeNode(2);
    TreeNode* n8 = new TreeNode(1);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n5->right = n8;

    int targetSum = 22;
    bool r = solution.hasPathSum(root, targetSum);
    cout << r << endl;

    return 0;
}