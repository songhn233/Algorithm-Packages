function levelOrder(root: TreeNode | null): number[][] {
  const ans: number[][] = []
  const q: TreeNode[] = []
  if (root) q.push(root)
  while (q.length) {
    const tmp: number[] = []
    let len = q.length
    while (len--) {
      const r = q.shift()
      tmp.push(r.val)
      if (r.left) q.push(r.left)
      if (r.right) q.push(r.right)
    }
    ans.push(tmp)
  }
  return ans
}
