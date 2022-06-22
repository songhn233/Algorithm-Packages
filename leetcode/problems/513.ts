const findBottomLeftValue = (root: TreeNode | null) => {
  const q: TreeNode[] = []
  let ans = root.val
  q.push(root)
  while (q.length) {
    let len = q.length
    for (let i = 0; i < len; i++) {
      const head = q.shift()
      if (i == 0) {
        ans = head.val
      }
      if (head.left) q.push(head.left)
      if (head.right) q.push(head.right)
    }
  }
  return ans
}
