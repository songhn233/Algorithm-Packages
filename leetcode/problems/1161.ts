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

function maxLevelSum(root: TreeNode | null): number {
  const q: TreeNode[] = []
  if (!root) {
    return -1
  }
  q.push(root)
  let maxn = -Infinity,
    ans = 0,
    step = 0
  while (q.length) {
    const len = q.length
    let sum = 0
    ++step
    for (let i = 0; i < len; i++) {
      const head = q.shift()
      sum += head.val
      if (head.left) q.push(head.left)
      if (head.right) q.push(head.right)
    }
    if (sum > maxn) {
      maxn = sum
      ans = step
    }
  }
  return ans
}
