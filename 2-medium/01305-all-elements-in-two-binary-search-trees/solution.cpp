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
    void travers(TreeNode* node, vector<int> &vec) {
        if (node == nullptr) {
            return;
        }
        travers(node->left, vec);
        vec.push_back(node->val);
        travers(node->right, vec);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1{};
        vector<int> vec2{};
        travers(root1, vec1);
        travers(root2, vec2);
        vector<int> res{};
        res.reserve(vec1.size() + vec2.size());

        int i = 0, j = 0;

        while (i < vec1.size() && j < vec2.size()) {
            if (vec1[i] <= vec2[j]) {
                res.push_back(vec1[i]);
                i += 1;
            } else {
                res.push_back(vec2[j]);
                j += 1;
            }
        }

        while (i < vec1.size()) {
            res.push_back(vec1[i]);
            i += 1;
        }
        while (j < vec2.size()) {
            res.push_back(vec2[j]);
            j += 1;
        }

        return res;
    }
};
