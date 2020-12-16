# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        def dfs(A, B):
            if not B:
                return True
            if not A:
                return False
            if A.val == B.val:
                return dfs(A.left, B.left) and dfs(A.right, B.right)
            else:
                return False
        if not A or not B:
            return False
        if dfs(A, B):
            return True
        return self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)
