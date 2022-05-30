function minDepth(root: TreeNode | null): number {
  const q: TreeNode[] = []
  let dep = 0
  if (root) q.push(root)
  while (q.length) {
    let len = q.length
    ++dep
    while (len--) {
      const r = q.shift()
      if (!r.left && !r.right) {
        return dep
      }
      if (r.left) q.push(r.left)
      if (r.right) q.push(r.right)
    }
  }
  return dep
}
