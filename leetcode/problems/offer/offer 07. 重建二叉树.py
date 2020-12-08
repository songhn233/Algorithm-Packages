# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        mp = {}
        for i in range(len(inorder)):
            mp[inorder[i]] = i

        def build(root, left, right):
            if left > right:
                return
            node = TreeNode(preorder[root])
            index = mp[preorder[root]]
            node.left = build(root + 1, left, index - 1)
            node.right = build(index - left + root + 1, index + 1, right)
            return node
        node = build(0, 0, len(preorder) - 1)
        return node
