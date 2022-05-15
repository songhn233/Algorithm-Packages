const inorderSuccessor = function (root, p) {
  let cur = root,
    ans = null
  const s = []
  const dfs = (root) => {
    if (root.left) dfs(root.left)
    cur = root
    if (s[s.length - 1] === p) {
      ans = cur
    }
    s.push(cur)
    if (root.right) dfs(root.right)
  }
  dfs(root)
  return ans
}
