# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def backtrack_deepest_leaves_sum(self, curr_node, curr_level):
        if curr_node == None:
            return

        if curr_level > self.max_level:
            self.max_level = curr_level
            self.sum = curr_node.val
        elif curr_level == self.max_level:
            self.sum += curr_node.val

        self.backtrack_deepest_leaves_sum(curr_node.left, curr_level + 1)
        self.backtrack_deepest_leaves_sum(curr_node.right, curr_level + 1)

    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        self.sum = 0
        self.max_level = -1
        self.backtrack_deepest_leaves_sum(root, 0)

        return self.sum

