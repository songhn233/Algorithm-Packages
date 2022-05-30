function rightSideView(root: TreeNode | null): number[] {
  const ans: number[] = []
  const q: TreeNode[] = []
  if (root) q.push(root)
  while (q.length) {
    let len = q.length
    while (len--) {
      const r = q.shift()
      if (r.left) q.push(r.left)
      if (r.right) q.push(r.right)
      if (!len) ans.push(r.val)
    }
  }
  return ans
}
