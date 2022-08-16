function deepestLeavesSum(root: TreeNode | null): number {
  const q: TreeNode[] = []
  if (!root) {
    return 0
  }
  q.push(root)
  let ans = 0
  while (q.length) {
    let len = q.length
    ans = 0
    while (len--) {
      const head = q.shift()
      if (head.left) q.push(head.left)
      if (head.right) q.push(head.right)
      ans += head.val
    }
  }
  return ans
}
