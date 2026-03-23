# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    maxi = 0
    def height(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        leftMax = self.height(root.left)
        rightMax = self.height(root.right)
        self.maxi = max(self.maxi,leftMax+rightMax)
        return 1+max(leftMax,rightMax)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.height(root)
        return self.maxi