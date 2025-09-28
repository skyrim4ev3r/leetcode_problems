# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def travers(self, node, arr):
        if node == None:
            return
        self.travers(node.left, arr)
        arr.append(node.val)
        self.travers(node.right, arr)

    def getAllElements(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> List[int]:
        vec1 = []
        vec2 = []
        self.travers(root1, vec1)
        self.travers(root2, vec2)
        res = []

        i = 0
        j = 0

        while i < len(vec1) and j < len(vec2):
            if vec1[i] <= vec2[j]:
                res.append(vec1[i])
                i += 1
            else:
                res.append(vec2[j])
                j += 1

        while i < len(vec1):
            res.append(vec1[i])
            i += 1

        while j < len(vec2):
            res.append(vec2[j])
            j += 1

        return res
