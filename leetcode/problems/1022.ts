const sumRootToLeaf = (root: TreeNode | null) => {
  let ans = 0
  const dfs = (root: TreeNode | null, sum: string) => {
    if (!root) return
    dfs(root.left, sum + root.val)
    dfs(root.right, sum + root.val)
    if (!root.left && !root.right) {
      ans += parseInt(sum + root.val, 2)
    }
  }

  dfs(root, '')
  return ans
}
