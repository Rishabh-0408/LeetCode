# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        ans = []
        if not root:
            return ans
        q = deque()
        q.append(root)
        flag = False
        while q:
            size = len(q)
            curr = []
            for _ in range(size):
                node = q.popleft()
                curr.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if flag:
                curr.reverse()
            ans.append(curr)
            flag = not flag
        return ans
