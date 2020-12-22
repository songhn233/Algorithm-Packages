/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
const maxDepth = (root) => {
  let ans = 0
  const dfs = (root, dep) => {
    if (!root) {
      return
    }
    if (!root.left && !root.right) {
      ans = Math.max(ans, dep)
    }
    dfs(root.left, dep + 1)
    dfs(root.right, dep + 1)
  }
  dfs(root, 1)
  return ans
}
