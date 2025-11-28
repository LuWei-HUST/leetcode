#include <iostream>
#include <vector>

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
    void travel(TreeNode* root, vector<int>& r) {
        if (!root) {
            return;
        }
        
        travel(root->left, r);
        r.push_back(root->val);
        travel(root->right, r);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r;

        travel(root, r);

        return r;
    }
};

int main() {
    Solution solution;

    TreeNode* root = new TreeNode(5);
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(2);

    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;

    vector<int> r = solution.inorderTraversal(root);

    for (size_t i=0;i<r.size();i++) {
        cout << r[i] << " ";
    }
    cout << endl;

    return 0;
}