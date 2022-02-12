const isBalanced = (root: TreeNode | null) => {
  let ans = true
  const dfs = (root: TreeNode | null) => {
    if (root === null) return 0
    const leftLength = dfs(root.left)
    const rightLength = dfs(root.right)
    if (
      leftLength === -1 ||
      rightLength === -1 ||
      Math.abs(leftLength - rightLength) > 1
    ) {
      return -1
    } else {
      return Math.max(leftLength, rightLength) + 1
    }
  }
  return dfs(root) >= 0
}
