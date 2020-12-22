# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        sum = []

        def dfs(root):
            if not root:
                return
            if root.left:
                dfs(root.left)
            sum.append(root.val)
            if root.right:
                dfs(root.right)
        dfs(root)
        return sum[-k]
