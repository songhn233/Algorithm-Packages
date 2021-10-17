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

function kthSmallest(root: TreeNode | null, k: number): number {
  let dep = 0, flag = false, ans = 0
  const dfs = (root: TreeNode | null) => {
    if(flag) return
    if(root.left) dfs(root.left)
    dep ++
    if(flag) return
    if(dep >= k) {
      flag = true
      ans = root.val
      return
    }
    if(root.right) dfs(root.right)
  }
  dfs(root)
  return ans
};