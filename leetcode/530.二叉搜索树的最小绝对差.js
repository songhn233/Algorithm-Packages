/*
 * @lc app=leetcode.cn id=530 lang=javascript
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
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
const getMinimumDifference = (root) => {
  let res = -1,
    pre = -1
  const dfs = (root) => {
    if (root === null) return
    if (root.left) dfs(root.left)
    if (pre === -1) {
      pre = root.val
    } else {
      res = res === -1 ? root.val - pre : Math.min(res, root.val - pre)
      pre = root.val
    }
    if (root.right) dfs(root.right)
  }
  dfs(root)
  return res
}
// @lc code=end
