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
    int sum, level;
    void backtrack_deepest_leaves_sum(TreeNode* curr_node, int curr_level) {
        if (curr_node == nullptr) {
            return;
        }
        if (curr_level > level) {
            level = curr_level;
            sum = curr_node->val;
        } else if (curr_level == level) {
            sum += curr_node->val;
        }

        backtrack_deepest_leaves_sum(curr_node->left, curr_level + 1);
        backtrack_deepest_leaves_sum(curr_node->right, curr_level + 1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        level = -1;
        sum = 0;
        backtrack_deepest_leaves_sum(root, 0);

        return sum;
    }
};
