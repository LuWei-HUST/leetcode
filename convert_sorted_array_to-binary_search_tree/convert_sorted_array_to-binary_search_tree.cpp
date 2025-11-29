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
    void travel(int l, int r, vector<int> nums, TreeNode* p) {
        if (l > r) {
            return;
        }

        int mid = (r - l) / 2 + l;
        p->val = nums[mid];

        if (mid-1 >= l) {
            TreeNode* n1 = new TreeNode();
            p->left = n1;
            travel(l, mid-1, nums, p->left);
        }

        if (mid+1 <= r) {
            TreeNode* n2 = new TreeNode();
            p->right = n2;
            travel(mid+1, r, nums, p->right);
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        TreeNode* root = new TreeNode();

        travel(0, len-1, nums, root);

        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = solution.sortedArrayToBST(nums);

    printTree(root);

    return 0;
}