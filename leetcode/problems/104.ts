function maxDepth(root: TreeNode | null): number {
  let ans = 0
  const dfs = (root: TreeNode | null, val: number) => {
    if (!root) {
      return
    }
    dfs(root.left, val + 1)
    dfs(root.right, val + 1)
    ans = ans > val ? ans : val
  }
  dfs(root, 1)
  return ans
}
