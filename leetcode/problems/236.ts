/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

interface TreeNode {
  tag?: boolean
  fa?: TreeNode | null
}

function lowestCommonAncestor(
  root: TreeNode | null,
  p: TreeNode | null,
  q: TreeNode | null
): TreeNode | null {
  if (root === null) return null
  if (!p || !q) return null
  const dfs = (root: TreeNode, fa: TreeNode | null) => {
    root.fa = fa
    if (root.left) dfs(root.left, root)
    if (root.right) dfs(root.right, root)
  }
  dfs(root, null)
  while (p) {
    p.tag = true
    p = p.fa
  }
  while (!q.tag) {
    q = q.fa
  }
  return q
}
