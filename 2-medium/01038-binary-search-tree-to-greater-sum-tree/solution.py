# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convert_to_greater_sum(self, curr: Optional[TreeNode]):
        if curr == None:
            return

        self.convert_to_greater_sum(curr.right)
        self.sum_values += curr.val
        curr.val = self.sum_values
        self.convert_to_greater_sum(curr.left)

    def bstToGst(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.sum_values = 0
        self.convert_to_greater_sum(root)
        return root

