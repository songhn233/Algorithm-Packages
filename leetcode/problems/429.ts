function levelOrder(root: Node | null): number[][] {
  const ans: number[][] = [],
    q: Node[] = []
  if (root) q.push(root)
  while (q.length) {
    let len = q.length
    const tmp: number[] = []
    while (len--) {
      const r = q.shift()
      tmp.push(r.val)
      r.children.forEach((v) => q.push(v))
    }
    ans.push(tmp)
  }
  return ans
}
