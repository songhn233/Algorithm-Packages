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
function findDuplicateSubtrees(root: TreeNode | null): Array<TreeNode | null> {
  if (!root) return []

  const res: Array<TreeNode> = [],
    map = new Map<string, number>()
  const dfs = (root: TreeNode | null) => {
    if (!root) return '_'
    const str = [String(root.val), dfs(root.left), dfs(root.right)].join()
    map.set(str, map.has(str) ? map.get(str) + 1 : 1)
    if (map.get(str) === 2) {
      res.push(root)
    }
    return str
  }
  dfs(root)
  return res
}
