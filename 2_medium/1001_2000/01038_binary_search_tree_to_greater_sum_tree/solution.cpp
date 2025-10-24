/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sum;

    void convert_to_greater_sum(TreeNode* curr) {
        if (curr == nullptr) {
            return;
        }

        convert_to_greater_sum(curr->right);
        sum += curr->val;
        curr->val = sum;
        convert_to_greater_sum(curr->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        convert_to_greater_sum(root);
        return root;
    }
};
