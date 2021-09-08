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
  ans?: number
}

const max = (a: number, b: number) => (a > b ? a : b)

function maxPathSum(root: TreeNode | null): number {
  if (root === null) return 0
  let ans = root.val
  const dfs = (root: TreeNode) => {
    root.ans = root.val
    if (root.left) dfs(root.left)
    if (root.right) dfs(root.right)
    root.ans += max(max(root.left?.ans ?? 0, 0), max(root.right?.ans ?? 0, 0))
    ans = max(
      ans,
      root.val + max(root.left?.ans ?? 0, 0) + max(root.right?.ans ?? 0, 0)
    )
  }
  dfs(root)
  return ans
}
