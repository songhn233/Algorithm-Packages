function averageOfLevels(root: TreeNode | null): number[] {
  const ans: number[] = [],
    q: TreeNode[] = []
  if (root) q.push(root)
  while (q.length) {
    let len = q.length,
      tmp = 0,
      re = len
    while (len--) {
      const r = q.shift()
      if (r.left) q.push(r.left)
      if (r.right) q.push(r.right)
      tmp += r.val
    }
    ans.push(tmp / re)
  }
  return ans
}
