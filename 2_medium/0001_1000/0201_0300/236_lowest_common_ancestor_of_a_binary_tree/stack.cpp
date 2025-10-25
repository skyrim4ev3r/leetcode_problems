/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool fill_path_stack(stack<TreeNode*> &stack, TreeNode* curr, TreeNode* target) {
        if (curr == nullptr) {
            return false;
        }

        stack.push(curr);

        if (curr->val == target->val) {
            return true;
        }

        if (fill_path_stack(stack, curr->left, target)) {
            return true;
        }

        if (fill_path_stack(stack, curr->right, target)) {
            return true;
        }

        stack.pop();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stack1{};
        stack<TreeNode*> stack2{};

        fill_path_stack(stack1, root, p);
        fill_path_stack(stack2, root, q);

        while (stack1.top() != stack2.top()) {
            if (stack1.size() > stack2.size()) {
                stack1.pop();
            } else if (stack1.size() < stack2.size()) {
                stack2.pop();
            } else {
                stack1.pop();
                stack2.pop();
            }
        }

        return stack1.top();
    }
};
