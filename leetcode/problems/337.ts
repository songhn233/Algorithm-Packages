const max = (...args: number[]) => args.reduce((a, b) => (a > b ? a : b))

const rob = (root: TreeNode | null) => {
  const dfs = (root: TreeNode | null) => {
    if (!root) {
      return [0, 0]
    }
    const a = dfs(root.left),
      b = dfs(root.right)
    return [root.val + a[1] + b[1], max(...a) + max(...b)]
  }
  return max(...dfs(root))
}
