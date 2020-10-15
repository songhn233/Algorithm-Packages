/*
 * @lc app=leetcode.cn id=116 lang=javascript
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/**
 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {Node} root
 * @return {Node}
 */
const connect = (root) => {
  const q = []
  if (root === null) return root
  q.push(root)
  while (q.length) {
    const t = q.length
    for (let i = 0; i < t; i++) {
      const node = q.shift()
      if (i !== t - 1) node.next = q[0]
      if (node.left) q.push(node.left)
      if (node.right) q.push(node.right)
    }
  }
  return root
}
// @lc code=end
