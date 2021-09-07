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

function inorderTraversal(root: TreeNode | null): number[] {
  if (root === null) return []
  const s: TreeNode[] = [],
    ans: number[] = []
  while (root || s.length) {
    while (root) {
      s.push(root)
      root = root.left
    }
    const t = s.pop()
    ans.push(t.val)
    root = t.right
  }
  return ans
}
